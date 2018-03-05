#include "PageForm.h"
#include "Page.h"
#include "Shape.h"
#include "Topic.h"
#include "Line.h"
#include <afxwin.h>
#include <afxdb.h>
#include <string>
#include "Branch.h"
#include "TextForm.h"
#include "TextFormSize.h"
#include "MouseAction.h"
#include "DrawingStrategy.h"
#include "SelectionStrategy.h"
#include "HitTestVisitor.h"
#include "SelectionMarkVisitor.h"
#include "DrawLines.h"
#include "DrawTopics.h"
#include "Mark.h"
#include "DrawingVisitor.h"
#include "DeleteVisitor.h"
#include "ScrollAction.h"
#include "SingleSelect.h"
#include "KeyBoard.h"

BEGIN_MESSAGE_MAP(PageForm, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_KEYDOWN()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

PageForm::PageForm()
	:clipboard(&selection)
{
	this->movedX = 0;
	this->movedY = 0;
}

int PageForm::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CFrameWnd::OnCreate(lpCreateStruct);
	this->branch = new Branch;
	this->branch->Add(new Topic(387, 150, 200, 200, "메인토픽"));
	this->branch->Add(new Mark(573, 200));
	this->selection.Add(this->branch);
	this->mouseAction = new MouseAction();
	this->branch->SetOwnerBranch(this->branch);//메인 브랜치의 오너브랜치는 자기자신
	this->scrollAction = new ScrollAction;
	return 0;
}

void PageForm::SetScrolls() {
	//스크롤 생성
	SCROLLINFO scrollInfo;

	scrollInfo.cbSize = sizeof(SCROLLINFO);
	scrollInfo.fMask = SIF_PAGE | SIF_RANGE;
	scrollInfo.nPage = 1200;
	scrollInfo.nMin = 0;
	scrollInfo.nMax = 10000;
	SetScrollInfo(SB_HORZ, &scrollInfo, TRUE);

	scrollInfo.cbSize = sizeof(SCROLLINFO);
	scrollInfo.fMask = SIF_PAGE | SIF_RANGE;
	scrollInfo.nPage = 600;
	scrollInfo.nMin = 0;
	scrollInfo.nMax = 8000;
	SetScrollInfo(SB_VERT, &scrollInfo, TRUE);
}

void PageForm::OnLButtonDown(UINT nFlags, CPoint point) {
	Shape *clickedObject = NULL;

	point.Offset(this->movedX*-1, this->movedY *-1);

	clickedObject = this->mouseAction->GetClickedObject(this->branch, point);
	this->mouseAction->SetStrategy(clickedObject);
	this->mouseAction->OnLButtonDown(point, nFlags, &this->selection, clickedObject);
	CFrameWnd::OnLButtonDown(nFlags, point);
}

void PageForm::OnMouseMove(UINT nFlags, CPoint point) {
	point.Offset(this->movedX*-1, this->movedY* -1);
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
	{
		this->mouseAction->OnMouseMove(point, nFlags);
		RedrawWindow();
	}
	CFrameWnd::OnMouseMove(nFlags, point);
}

void PageForm::OnLButtonUp(UINT nFlags, CPoint point) {
	point.Offset(this->movedX, this->movedY);
	this->mouseAction->OnLButtonUp(&this->selection, nFlags, this->branch);

	RedrawWindow();
	CFrameWnd::OnLButtonUp(nFlags, point);
}

void PageForm::OnPaint() {
	Long i = 0;
	Topic *selectedTopic;
	CPaintDC dc(this);
	CPen blackPen;

	//선택표시하기
	SelectionMarkVisitor selectionMarkVisitor(&this->selection, &dc, this->movedX, this->movedY);
	while (i < this->selection.GetLength()) {
		selectedTopic = this->selection.GetAt(i)->GetTopic();
		selectedTopic->Accept(selectionMarkVisitor);
		i++;
	}

	//검정펜으로 다시 설정
	blackPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	dc.SelectObject(&blackPen);

	DrawingVisitor visitor(&dc, this->movedX, this->movedY);

	this->branch->Accept(visitor);
}

void PageForm::OnClose()
{
	if (this->branch != NULL)
	{
		delete this->branch;
		this->branch = NULL;
	}

	if (this->mouseAction != NULL)
	{
		delete this->mouseAction;
		this->mouseAction = NULL;
	}

	CFrameWnd::OnClose();
}

void PageForm::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	KeyBoard keyBoard;

	keyBoard.KeyDown(this, nChar, nRepCnt, nFlags);

	RedrawWindow();
	CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

void PageForm::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar *pScrollBar)
{
	Long movedPosition;
	this->scrollAction->SetHScrollStrategy(nSBCode);
	movedPosition = this->scrollAction->Scroll(this, nPos);
	this->movedX += movedPosition;

	RedrawWindow();
	CFrameWnd::OnHScroll(nSBCode, nPos, pScrollBar);
}

void PageForm::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar *pScrollBar)
{
	Long movedPosition;
	this->scrollAction->SetVScrollStrategy(nSBCode);
	movedPosition = this->scrollAction->Scroll(this, nPos);
	this->movedY += movedPosition;

	RedrawWindow();
	CFrameWnd::OnHScroll(nSBCode, nPos, pScrollBar);
}

BOOL PageForm::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	Long movedPosition;
	this->scrollAction->SetHScrollStrategy(WM_MOUSEWHEEL);
	movedPosition = this->scrollAction->Scroll(this, zDelta);
	this->movedY += movedPosition;

	/*
		CString string;
		string.Format(_T("zdelta : %d "), zDelta);
		AfxMessageBox(string);
	*/
	RedrawWindow();
	return CFrameWnd::OnMouseWheel(nFlags, zDelta, pt);
}

void PageForm::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	SingleSelect singleSelect;
	Shape *clickedObject = NULL;
	Topic *topic;

	point.Offset(this->movedX, this->movedY);
	clickedObject = this->mouseAction->GetClickedObject(this->branch, point);
	if (clickedObject != NULL) {
		//클릭된 브랜치를 선택한다.
		singleSelect.SelectBranch(&this->selection, clickedObject->GetOwnerBranch());

		//선택된 토픽을 구한다.
		topic = (Topic*)this->selection.GetLastSelection()->GetTopic();

		this->textForm = new TextForm;
		this->textForm->CreateEx(WS_EX_CLIENTEDGE, TEXT("STATIC"), TEXT("DEMO"), WS_CHILD | WS_VISIBLE | WS_BORDER, topic->GetX(), topic->GetY(), topic->GetWidth() + 6, topic->GetHeight(), m_hWnd, (HMENU)2345);

		this->textForm->textFormSize->SetX(topic->GetX());
		this->textForm->textFormSize->SetY(topic->GetY());
		this->textForm->textFormSize->SetWidth(topic->GetWidth());
		this->textForm->textFormSize->SetHeight(topic->GetHeight());
		this->textForm->ShowWindow(SW_SHOW);
		this->textForm->UpdateWindow();
		AfxGetApp()->m_pMainWnd = this->textForm;

		this->textForm->SetCapture();
	}
	CFrameWnd::OnLButtonDblClk(nFlags, point);
}
#include "PageForm.h"
#include "Page.h"
#include "Shape.h"
#include "Topic.h"
#include "Line.h"
#include <afxwin.h>
#include <afxdb.h>
#include <string>
#include "Branch.h"
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
END_MESSAGE_MAP()

PageForm::PageForm() {
	this->movedX = 0;
	this->movedY = 0;
}

int PageForm::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CFrameWnd::OnCreate(lpCreateStruct);
	this->branch = new Branch;
	this->branch->Add(new Topic(387, 150, 200, 200, "��������"));
	this->branch->Add(new Mark(573, 200));
	this->selection.Add(this->branch);
	this->mouseAction = new MouseAction();
	this->branch->SetOwnerBranch(this->branch);//���� �귣ġ�� ���ʺ귣ġ�� �ڱ��ڽ�
	this->scrollAction = new ScrollAction;
	return 0;
}

void PageForm::SetScrolls()
{
	SCROLLINFO scrollInfo;

	scrollInfo.cbSize = sizeof(SCROLLINFO);
	scrollInfo.fMask = SIF_PAGE | SIF_RANGE;
	scrollInfo.nPage = 100;
	scrollInfo.nMin = 0;
	scrollInfo.nMax = 1280;
	SetScrollInfo(SB_HORZ, &scrollInfo, TRUE);

	scrollInfo.cbSize = sizeof(SCROLLINFO);
	scrollInfo.fMask = SIF_PAGE | SIF_RANGE;
	scrollInfo.nPage = 80;
	scrollInfo.nMin = 0;
	scrollInfo.nMax = 720;
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
		this->mouseAction->OnMouseMove(point);
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

	//����ǥ���ϱ�
	SelectionMarkVisitor selectionMarkVisitor(&this->selection, &dc, this->movedX, this->movedY);
	while (i < this->selection.GetLength()) {
		selectedTopic = this->selection.GetAt(i)->GetTopic();
		selectedTopic->Accept(selectionMarkVisitor);
		i++;
	}

	//���������� �ٽ� ����
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
	Long i = 0;
	Long length;
	if (nChar == VK_DELETE)
	{
		DeleteVisitor visitor;
		length = selection.GetLength();

		while (i < length) //�ݺ��ϸ� ���ú귣ġ ����
		{
			visitor.TakeBranch(selection.GetAt(i));
			this->branch->Accept(visitor);
			i++;
		}

		Branch *compare = NULL;
		Branch *temp = NULL;

		if (0 < length)
		{
			temp = this->selection.GetLastSelection()->GetOwnerBranch();//������ ���ú귣ġ�� ���ʺ귣ġ�� ����
			compare = temp;
		}

		while (compare != NULL && compare != this->branch)//������ ���ú귣ġ�� �����귣ġ�� ���ù迭�ȿ� �ִ°�� �ֻ��� �귣ġ�� ���ʺ귣ġ ����
		{
			i = 0;
			while (i < length)
			{
				if (selection.GetAt(i) == compare)
				{
					compare = this->selection.GetAt(i)->GetOwnerBranch();
					temp = compare;
					i = -1;
				}
				i++;
			}
			compare = compare->GetOwnerBranch();
		}

		if (0 < length)//���ú귣ġ�� �ִ� ��� �迭�� ���� ����� �ӽú귣ġ �߰�.
		{
			this->selection.Clear();
			this->selection.Add(temp);
		}
	}
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
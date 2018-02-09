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
#include "SingleSelect.h"

BEGIN_MESSAGE_MAP(PageForm, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

PageForm::PageForm() {
}
int PageForm::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CFrameWnd::OnCreate(lpCreateStruct);
	this->branch = new Branch;
	this->branch->Add(new Topic(387, 150, 200, 200, "��������"));
	this->branch->Add(new Mark(573, 200));
	this->selection.Add(this->branch);
	this->mouseAction = new MouseAction();
	return 0;
}

void PageForm::OnLButtonDown(UINT nFlags, CPoint point) {
	Shape *clickedObject = NULL;

	clickedObject = this->mouseAction->GetClickedObject(this->branch, point);
	this->mouseAction->SetStrategy(clickedObject);
	this->mouseAction->OnLButtonDown(point, nFlags, &this->selection, clickedObject);

	CFrameWnd::OnLButtonDown(nFlags, point);
}

void PageForm::OnMouseMove(UINT nFlags, CPoint point) {
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
	{
		this->mouseAction->OnMouseMove(point);
	}
	CFrameWnd::OnMouseMove(nFlags, point);
}

void PageForm::OnLButtonUp(UINT nFlags, CPoint point) {
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
	SelectionMarkVisitor selectionMarkVisitor(&this->selection, &dc);
	while (i < this->selection.GetLength()) {
		selectedTopic = this->selection.GetAt(i)->GetTopic();
		selectedTopic->Accept(selectionMarkVisitor);
		i++;
	}

	//���������� �ٽ� ����
	blackPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	dc.SelectObject(&blackPen);

	DrawingVisitor visitor(&dc);

	this->branch->Accept(visitor);

	//�� �׸���
	//DrawLines drawLines(this->branch, &dc);
	//drawLines.Traverse();

	//���� �׸���
	//DrawTopics drawTopics(this->branch, &dc);
	//drawTopics.Traverse();
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

void PageForm::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	SingleSelect singleSelect;
	Shape *clickedObject;
	Topic *topic;

	clickedObject = this->mouseAction->GetClickedObject(this->branch, point);

	if (typeid(*clickedObject) == typeid(Topic)) {
		//Ŭ���� �귣ġ�� �����Ѵ�.
		singleSelect.SelectBranch(&this->selection, (Branch*)clickedObject);

		//���õ� ������ ���Ѵ�.
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
}
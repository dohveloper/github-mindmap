#include "PageForm.h"
#include "Page.h"
#include "Shape.h"
#include "Topic.h"
#include "Line.h"
#include <afxwin.h>
#include <afxdb.h>
#include <string>
//#include "TextForm.h"
#include "Branch.h"
#include "DrawingVisitor.h"
#include "MouseAction.h"
#include "DrawingMouse.h"
#include "SelectionMouse.h"
#include "HitTestVisitor.h"
#include "SelectionMarkVisitor.h"


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
	this->branch->Add(new Topic(387, 150, 200, 200, "메인토픽"));
	this->selection.Add(this->branch);
	this->mouseAction = new MouseAction();

	return 0;
}

void PageForm::OnLButtonDown(UINT nFlags, CPoint point) {

	Branch *clickedBranch=NULL;
	HitTestVisitor visitor(point,this->mouseAction,&clickedBranch);
	
	this->branch->Accept(visitor);

	if (clickedBranch != NULL) {
		mouseAction->ChangeState(SelectionMouse::Instance());
	}
	else {
		mouseAction->ChangeState(DrawingMouse::Instance());
	}

	this->mouseAction->OnLButtonDown(point, &this->selection, clickedBranch);

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

	this->mouseAction->OnLButtonUp(&this->selection);

	RedrawWindow();
	CFrameWnd::OnLButtonUp(nFlags, point);
}

void PageForm::OnPaint() {

	Long i = 0;
	Topic *selectedTopic;
	CPaintDC dc(this);
	CPen blackPen;
	

	//선택표시하기 
	SelectionMarkVisitor selectionMarkVisitor(&this->selection, &dc);
	while (i < this->selection.GetLength()) {
		selectedTopic = this->selection.GetAt(i)->GetTopic();
		selectedTopic->Accept(selectionMarkVisitor);
		i++;
	}

	//검정펜으로 다시 설정
	blackPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	dc.SelectObject(&blackPen);

	//드로잉 비지터 생성 
	DrawingVisitor visitor(&dc);

	//브랜치 그리기
	this->branch->Accept(visitor);

}

void PageForm::OnClose()
{

	if(this->branch != NULL)
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

	this->mouseAction->ChangeState(SelectionMouse::Instance());
	CFrameWnd::OnLButtonDblClk(nFlags, point);
}

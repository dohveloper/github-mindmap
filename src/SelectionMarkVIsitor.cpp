#include "ShapeVisitor.h"
#include <afxwin.h>
#include "SelectionMarkVisitor.h"
#include "Topic.h"
#include "View.h"
#define SELECTONMARKGAP 5

SelectionMarkVisitor::SelectionMarkVisitor()
{
}

SelectionMarkVisitor::SelectionMarkVisitor(Selection *selection, CPaintDC *dc, View *view)
{
	this->selection = selection;
	this->dc = dc;
	this->view = view;
}

SelectionMarkVisitor::~SelectionMarkVisitor()
{
}

void SelectionMarkVisitor::VisitTopic(Topic * topic)
{
	CPen bluePen;
	Long x;
	Long y;
	Long width;
	Long height;
	Long scale;

	bluePen.CreatePen(PS_DOT, 1, RGB(0, 0, 255));
	this->dc->SelectObject(&bluePen);

	x = topic->GetX();
	y = topic->GetY();
	this->view->ConvertToViewPoint(&x, &y);
	scale = this->view->GetScale();
	width = topic->GetWidth()*scale;
	height = topic->GetHeight()*scale;

	this->dc->Ellipse(x - SELECTONMARKGAP, y - SELECTONMARKGAP, x + width + SELECTONMARKGAP, y + height + SELECTONMARKGAP);
}
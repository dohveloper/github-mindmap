#include "ShapeVisitor.h"
#include <afxwin.h>
#include "SelectionMarkVisitor.h"
#include "Topic.h"
#define SELECTONMARKGAP 5

SelectionMarkVisitor::SelectionMarkVisitor()
{
}

SelectionMarkVisitor::SelectionMarkVisitor(Selection *selection, CPaintDC *dc, Long movedX, Long movedY)
{
	this->selection = selection;
	this->dc = dc;
	this->movedX = movedX;
	this->movedY = movedY;
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

	bluePen.CreatePen(PS_DOT, 1, RGB(0, 0, 255));
	this->dc->SelectObject(&bluePen);
	x = topic->GetX() - this->movedX;
	y = topic->GetY() - this->movedY;
	width = topic->GetWidth();
	height = topic->GetHeight();
	this->dc->Ellipse(x - SELECTONMARKGAP, y - SELECTONMARKGAP, x + width + SELECTONMARKGAP, y + height + SELECTONMARKGAP);
}
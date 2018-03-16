//DrawingVisitor.cpp

#include "DrawingVisitor.h"
#include "Branch.h"
#include "PageForm.h"
#include "DrawLines.h"
#include "DrawTopics.h"
#include "DrawMarks.h"

DrawingVisitor::DrawingVisitor() {
}

DrawingVisitor::DrawingVisitor(CPaintDC * dc, Long movedX, Long movedY)
{
	this->dc = dc;
	this->movedX = movedX;
	this->movedY = movedY;
}

DrawingVisitor::~DrawingVisitor() {
}

void DrawingVisitor::VisitBranch(Branch *branch)
{
	DrawLines drawLines(branch, this->dc, this->movedX, this->movedY);
	drawLines.Traverse();

	DrawTopics drawTopics(branch, this->dc, this->movedX, this->movedY);
	drawTopics.Traverse();

	DrawMarks drawMarks(branch, this->dc, this->movedX, this->movedY);
	drawMarks.Traverse();
}
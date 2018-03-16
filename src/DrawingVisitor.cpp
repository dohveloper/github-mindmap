//DrawingVisitor.cpp

#include "DrawingVisitor.h"
#include "Branch.h"
#include "PageForm.h"
#include "DrawLines.h"
#include "DrawTopics.h"
#include "DrawMarks.h"
#include "View.h"

DrawingVisitor::DrawingVisitor() {
}

DrawingVisitor::DrawingVisitor(CPaintDC * dc, View *view)
{
	this->dc = dc;
	this->view = view;
}

DrawingVisitor::~DrawingVisitor() {
}

void DrawingVisitor::VisitBranch(Branch *branch)
{
	DrawLines drawLines(branch, this->dc, view);
	drawLines.Traverse();

	DrawTopics drawTopics(branch, this->dc, view);
	drawTopics.Traverse();

	DrawMarks drawMarks(branch, this->dc, view);
	drawMarks.Traverse();
}
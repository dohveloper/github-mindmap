#include "DrawingVisitor.h"
#include "Branch.h"
#include "PageForm.h"
#include "DrawLines.h"
#include "DrawTopics.h"
//#include "DrawMarks.h"

DrawingVisitor::DrawingVisitor() {

}

DrawingVisitor::DrawingVisitor(CPaintDC *dc){
	this->dc = dc;
}

DrawingVisitor::~DrawingVisitor() {

}

void DrawingVisitor::VisitBranch(Branch *branch)
{
	DrawLines drawLines(branch, dc);
	drawLines.Traverse();

	DrawTopics drawTopics(branch, dc);
	drawTopics.Traverse();

	//DrawMarks drawMarks(branch, dc);
	//DrawMarks.Traverse();
}

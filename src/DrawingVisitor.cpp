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

DrawingVisitor::DrawingVisitor(CDC * dc, View *view)
{
	this->dc = dc;
	this->view = view;
}

DrawingVisitor::~DrawingVisitor() {
}

void DrawingVisitor::VisitBranch(Branch *branch)
{
	CPen blackPen;
	CFont font;
	Long fontSize;
	Long scale;

	//검정펜으로 설정
	blackPen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	this->dc->SelectObject(&blackPen);
	//폰트설정
	scale = this->view->GetScale();
	fontSize = 14 * scale;
	font.CreatePointFont(fontSize, "system");
	this->dc->SelectObject(&font);

	DrawLines drawLines(branch, this->dc, view);
	drawLines.Traverse();

	DrawTopics drawTopics(branch, this->dc, view);
	drawTopics.Traverse();

	DrawMarks drawMarks(branch, this->dc, view);
	drawMarks.Traverse();
}
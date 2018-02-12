#include "ScrollingVisitor.h"
#include "Topic.h"
#include "Line.h"
#include "PageForm.h"
#include <afxwin.h>

ScrollingVisitor::ScrollingVisitor() {

}

ScrollingVisitor::ScrollingVisitor(CPaintDC *dc){
	this->dc = dc;
}

ScrollingVisitor::~ScrollingVisitor() {

}
void ScrollingVisitor::VisitTopic(Topic *topic) {
	
	Long x;
	Long y;
	Long width;
	Long height;
	string content;

	CFont fnt;
	fnt.CreatePointFont(14, "system");
	this->dc->SelectObject(&fnt);
	
	//토픽을 그리는 코드 

	x = topic->GetX();
	y = topic->GetY();
	width = topic->GetWidth();
	height = topic->GetHeight();
	content = topic->GetContent();

	this->dc->Ellipse(x-100, y, x + width, y + height);
	//dc.TextOut(x + width / 2 - 10, y + height / 2, (CString)content.c_str());
	
}

void ScrollingVisitor::VisitLine(Line *line) {
	Long x;
	Long y;
	Long width;
	Long height;

	//라인을 그리는 코드
	x = line->GetX();
	y = line->GetY();
	width = line->GetWidth();
	height = line->GetHeight();

	this->dc->MoveTo(x, y);
	this->dc->LineTo(x + width, y + height);
	
}

void ScrollingVisitor::VisitBranch(Branch * branch)
{
	Long length;
	Long i = 0;
	Shape *currentItem;

	length = branch->GetLength();

	while (i < length) {
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) != typeid(Topic)) {
			currentItem->Accept(*this);
		}
		i++;
	}
	i = 0;
	while (i < length)
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Topic)) {
			currentItem->Accept(*this);
		}
		i++;
	}
}

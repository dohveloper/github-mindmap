#include "DrawTopics.h"
#include "Branch.h"
#include "Shape.h"
#include "Topic.h"
#include "View.h"

DrawTopics::DrawTopics(Branch *branch, CPaintDC *dc, View *view)
	:BranchTraverser(branch)
{
	this->dc = dc;
	this->view = view;
}

bool DrawTopics::ProcessItem(Shape *shape)
{
	Long startX;
	Long startY;
	Long x;
	Long y;
	Long width;
	Long height;
	string content;

	startX = this->view->GetStartX();
	startY = this->view->GetStartY();

	if (typeid(*shape) == typeid(Topic)) {
		CFont fnt;
		fnt.CreatePointFont(14, "system");
		this->dc->SelectObject(&fnt);

		//토픽을 그리는 코드

		x = shape->GetX() - startX;
		y = shape->GetY() - startY;
		width = shape->GetWidth();
		height = shape->GetHeight();
		content = shape->GetContent();

		this->dc->Ellipse(x, y, x + width, y + height);
		this->dc->TextOut(x + width / 2 - 30, y + height / 2, (CString)content.c_str());
	}

	if (typeid(*shape) == typeid(Branch)) {
		if ((((Branch*)shape))->GetIsShown() == true) {
			DrawTopics drawTopics((Branch*)shape, this->dc, this->view);
			drawTopics.Traverse();
		}
	}

	return true;
}
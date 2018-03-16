#include "DrawMarks.h"
#include "Branch.h"
#include "Shape.h"
#include "Mark.h"
#include "View.h"

DrawMarks::DrawMarks(Branch *branch, CPaintDC *dc, View *view)
	:BranchTraverser(branch)
{
	this->dc = dc;
	this->view = view;
}

bool DrawMarks::ProcessItem(Shape *shape)
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

	if (typeid(*shape) == typeid(Mark)) {
		if ((((Mark*)shape))->GetIsShown() == true) {
			CFont fnt;
			fnt.CreatePointFont(14, "system");
			this->dc->SelectObject(&fnt);

			//마크를 그리는 코드

			x = shape->GetX() - startX;
			y = shape->GetY() - startY;
			width = shape->GetWidth();
			height = shape->GetHeight();
			content = shape->GetContent();

			this->dc->Ellipse(x, y, x + width, y - height);
			this->dc->TextOut(x + 14 * width / 15 - 12, y + height / 4 - 23, (CString)(content.c_str()));
		}
	}

	if (typeid(*shape) == typeid(Branch)) {
		if ((((Branch*)shape))->GetIsShown() == true) {
			DrawMarks drawMarks((Branch*)shape, this->dc, this->view);
			drawMarks.Traverse();
		}
	}

	return true;
}
#include "DrawLines.h"
#include "Branch.h"
#include "Shape.h"
#include "Line.h"
#include "View.h"

DrawLines::DrawLines(Branch *branch, CPaintDC *dc, View *view)
	:BranchTraverser(branch)
{
	this->dc = dc;
	this->view = view;
}

bool DrawLines::ProcessItem(Shape *shape)
{
	Long startX;
	Long startY;
	Long x;
	Long y;
	Long width;
	Long height;

	startX = this->view->GetStartX();
	startY = this->view->GetStartY();

	if (typeid(*shape) == typeid(Line)) {
		x = shape->GetX() - startX;
		y = shape->GetY() - startY;
		width = shape->GetWidth();
		height = shape->GetHeight();
		this->dc->MoveTo(x, y);
		this->dc->LineTo(x + width, y + height);
	}

	if (typeid(*shape) == typeid(Branch)) {
		if ((((Branch*)shape))->GetIsShown() == true) {
			DrawLines drawLines((Branch*)shape, this->dc, this->view);
			drawLines.Traverse();
		}
	}

	return true;
}
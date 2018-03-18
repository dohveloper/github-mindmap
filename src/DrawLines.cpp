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
	Long x;
	Long y;
	Long width;
	Long height;
	Long scale;
	if (typeid(*shape) == typeid(Line)) {
		x = shape->GetX();
		y = shape->GetY();
		view->ConvertToViewPoint(&x, &y);
		scale = this->view->GetScale();
		width = shape->GetWidth()*scale;
		height = shape->GetHeight()*scale;
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
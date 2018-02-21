#include "DrawLines.h"
#include "Branch.h"
#include "Shape.h"
#include "Line.h"

DrawLines::DrawLines(Branch *branch, CPaintDC *dc, Long movedX, Long movedY)
	:BranchTraverser(branch)
{
	this->dc = dc;
	this->movedX = movedX;
	this->movedY = movedY;
}

bool DrawLines::ProcessItem(Shape *shape)
{
	Long x;
	Long y;
	Long width;
	Long height;

	if (typeid(*shape) == typeid(Line)) {
		x = shape->GetX() + this->movedX;
		y = shape->GetY() + this->movedY;
		width = shape->GetWidth();
		height = shape->GetHeight();
		this->dc->MoveTo(x, y);
		this->dc->LineTo(x + width, y + height);
	}

	if (typeid(*shape) == typeid(Branch)) {
		if ((((Branch*)shape))->GetIsShown() == true) {
			DrawLines drawLines((Branch*)shape,this->dc, this->movedX, this->movedY);
			drawLines.Traverse();
		}
	}

	return true;
}
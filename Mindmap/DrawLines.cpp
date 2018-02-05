#include "DrawLines.h"
#include "Branch.h"
#include "Shape.h"


DrawLines::DrawLines(Branch *branch, CPaintDC *dc)
	:BranchTraverser(branch)
{
	this->dc = dc;
}

bool DrawLines::ProcessItem(Shape* shape)
{
	Long x;
	Long y;
	Long width;
	Long height;

	if (typeid(*shape) == typeid("Line")) {
		//라인을 그리는 코드

		x = shape->GetX();
		y = shape->GetY();
		width = shape->GetWidth();
		height = shape->GetHeight();
		this->dc->MoveTo(x, y);
		this->dc->LineTo(x + width, y + height);
	}

	if (typeid(*shape) == typeid("Branch")) {
		if ((((Branch*)shape))->GetIsHidden() == false) {
			DrawLines drawLines((Branch*)shape, this->dc);
			drawLines.Traverse();
		}
	}

	return true;
}

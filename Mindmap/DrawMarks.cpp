#include "DrawMarks.h"
#include "Branch.h"
#include "Shape.h"
#include "Mark.h"

DrawMarks::DrawMarks(Branch *branch, CPaintDC *dc)
	:BranchTraverser(branch)
{
	this->dc = dc;
}

bool DrawMarks::ProcessItem(Shape *shape)
{
	Long x;
	Long y;
	Long width;
	Long height;
	string content;

	if (typeid(*shape) == typeid(Mark)) {
		if ((((Mark*)shape))->GetIsShown() == true) {
			CFont fnt;
			fnt.CreatePointFont(14, "system");
			this->dc->SelectObject(&fnt);

			//마크를 그리는 코드

			x = shape->GetX();
			y = shape->GetY();
			width = shape->GetWidth();
			height = shape->GetHeight();
			content = shape->GetContent();

			this->dc->Ellipse(x, y, x + width, y - height);
			this->dc->TextOut(x + 14 * width / 15 - 12, y + height / 4 - 23, (CString)(content.c_str()));
		}
	}

	if (typeid(*shape) == typeid(Branch)) {
		if ((((Branch*)shape))->GetIsShown() == true) {
			DrawMarks drawLines((Branch*)shape, this->dc);
			drawLines.Traverse();
		}
	}

	return true;
}
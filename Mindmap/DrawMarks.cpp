#include "DrawMarks.h"
#include "Branch.h"
#include "Shape.h"
#include "Mark.h"

DrawMarks::DrawMarks(Branch *branch, CPaintDC *dc, Long movedX, Long movedY)
	:BranchTraverser(branch)
{
	this->dc = dc;
	this->movedX = movedX;
	this->movedY = movedY;
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

			//��ũ�� �׸��� �ڵ�

			x = shape->GetX() - this->movedX;
			y = shape->GetY() - this->movedY;
			width = shape->GetWidth();
			height = shape->GetHeight();
			content = shape->GetContent();

			this->dc->Ellipse(x, y, x + width, y - height);
			this->dc->TextOut(x + 14 * width / 15 - 12, y + height / 4 - 23, (CString)(content.c_str()));
		}
	}

	if (typeid(*shape) == typeid(Branch)) {
		if ((((Branch*)shape))->GetIsShown() == true) {
			DrawMarks drawLines((Branch*)shape, this->dc, this->movedX, this->movedY);
			drawLines.Traverse();
		}
	}

	return true;
}
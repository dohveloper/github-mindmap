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
	Long x;
	Long y;
	Long width;
	Long height;
	string content;
	Long scale;
	CFont font;
	Long fontSize;

	if (typeid(*shape) == typeid(Mark)) {
		if ((((Mark*)shape))->GetIsShown() == true) {
			//마크를 그리는 코드
			x = shape->GetX();
			y = shape->GetY();
			view->ConvertToViewPoint(&x, &y);
			scale = this->view->GetScale();
			width = shape->GetWidth()*scale;
			height = shape->GetHeight()*scale;
			content = shape->GetContent();

			fontSize = 2 * scale;
			font.CreateFont(fontSize, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0,
				DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
				DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "굴림체");
			dc->SelectObject(&font);

			this->dc->Ellipse(x, y, x + width, y - height);
			this->dc->TextOut(x + width / 3 * 1, y - height / 5 * 4, (CString)(content.c_str()));
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
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
	Long scale;
	Long x;
	Long y;
	Long width;
	Long height;
	string content;
	CFont font;
	Long fontSize;
	CBrush brush;

	if (typeid(*shape) == typeid(Topic)) {
		//토픽을 그리는 코드

		x = shape->GetX();
		y = shape->GetY();
		view->ConvertToViewPoint(&x, &y);
		scale = this->view->GetScale();
		width = shape->GetWidth()*scale;
		height = shape->GetHeight()*scale;
		content = shape->GetContent();

		brush.CreateSolidBrush(RGB(255, 255, 240));       // 배경색
		dc->SelectObject(&brush);

		fontSize = 2 * scale;
		font.CreateFont(fontSize, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0,
			DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "굴림체");
		dc->SelectObject(&font);

		this->dc->Ellipse(x, y, x + width, y + height);
		this->dc->TextOut(x + width / 3, y + height / 2, (CString)content.c_str());
	}

	if (typeid(*shape) == typeid(Branch)) {
		if ((((Branch*)shape))->GetIsShown() == true) {
			DrawTopics drawTopics((Branch*)shape, this->dc, this->view);
			drawTopics.Traverse();
		}
	}

	return true;
}
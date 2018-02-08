#include "DrawTopics.h"
#include "Branch.h"
#include "Shape.h"
#include "Topic.h"

DrawTopics::DrawTopics(Branch *branch, CPaintDC *dc)
	:BranchTraverser(branch)
{
	this->dc = dc;
}

bool DrawTopics::ProcessItem(Shape *shape)
{
	Long x;
	Long y;
	Long width;
	Long height;
	string content;

	if (typeid(*shape) == typeid(Topic)) {

		CFont fnt;
		fnt.CreatePointFont(14, "system");
		this->dc->SelectObject(&fnt);

		//토픽을 그리는 코드

		x = shape->GetX();
		y = shape->GetY();
		width = shape->GetWidth();
		height = shape->GetHeight();
		content = shape->GetContent();

		this->dc->Ellipse(x, y, x + width, y + height);
		this->dc->TextOut(x + width / 2 - 25, y + height / 2, (CString)content.c_str());
	}

	if (typeid(*shape) == typeid(Branch)) {
		if ((((Branch*)shape))->GetIsShown() == true) {
			DrawTopics drawLines((Branch*)shape, this->dc);
			drawLines.Traverse();
		}
	}

	return true;
}
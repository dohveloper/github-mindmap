//Mark.cpp

#include "Mark.h"
#include "Branch.h"
#include "Topic.h"
#include <afxwin.h>

Mark::Mark()
	:Shape(0, 0, 0, 0, "+", NULL, false)
{
}

Mark::Mark(Long x, Long y, Long width, Long height, string content, Branch *branch)
	: Shape(x, y, width, height, content, branch, false)
{
}

Mark::Mark(const Mark& source)
	: Shape(source.x, source.y, source.width, source.height, source.content, source.ownerBranch, source.isShown)
{
}

void Mark::UpdatePosition()
{
	//OwnerBranch의 토픽 값을 바탕으로 마크 위치 업데이트하는 연산

	Topic *topic;

	topic = this->GetOwnerBranch()->GetTopic();

	//기존 마크 위치 그려지는 코드 바탕으로 작성 ( DrawingStrategy.cpp )

	this->x = topic->GetX() + 14 * topic->GetWidth() / 15;
	this->y = topic->GetY() + topic->GetHeight() / 4;
}

Mark::~Mark()
{
}

void Mark::Accept(ShapeVisitor& visitor) {
	visitor.VisitMark(this);
}

Mark& Mark::operator=(const Mark& source)
{
	this->x = source.x;
	this->y = source.y;
	this->width = source.width;
	this->height = source.height;
	this->content = source.content;
	this->ownerBranch = source.ownerBranch;
	this->isShown = source.isShown;
	return *this;
}
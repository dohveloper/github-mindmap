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
	//OwnerBranch�� ���� ���� �������� ��ũ ��ġ ������Ʈ�ϴ� ����

	Topic *topic;

	topic = this->GetOwnerBranch()->GetTopic();

	//���� ��ũ ��ġ �׷����� �ڵ� �������� �ۼ� ( DrawingStrategy.cpp )

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
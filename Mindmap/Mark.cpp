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

Mark::~Mark()
{
}

void Mark::SetContent(string content)
{
	this->content = content;
}

void Mark::Accept(ShapeVisitor& visitor) {
	//visitor.VisitTopic(this);
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
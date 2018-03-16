#include "UnFoldVisitor.h"
#include "Topic.h"
#include "Line.h"
#include "Branch.h"
#include "MouseAction.h"
#include "DrawingStrategy.h"


UnFoldVisitor::UnFoldVisitor()
{
}

UnFoldVisitor::UnFoldVisitor(Long x, Long y, Long height, Long width)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->isOverlapped = false;
}

UnFoldVisitor::~UnFoldVisitor() {

}

void UnFoldVisitor::VisitBranch(Branch *branch)
{
	Long i = 0;
	Long length;
	Shape *currentItem;

	length = branch->GetLength();

	while (i < length)
	{
		currentItem = branch->GetAt(i);

		if (typeid(*currentItem) == typeid(Branch))
		{
			currentItem->Show();
			currentItem->Accept(*this);
		}
		i++;
	}
}
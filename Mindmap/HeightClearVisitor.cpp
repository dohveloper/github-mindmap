//HeightClearVisitor.cpp

#include "HeightClearVisitor.h"
#include "Branch.h"
#include "Topic.h"
#define vInterval 10

HeightClearVisitor::HeightClearVisitor()
{
}

HeightClearVisitor::HeightClearVisitor(Long totalHeight)
{
}

HeightClearVisitor::~HeightClearVisitor()
{
}

void HeightClearVisitor::VisitBranch(Branch *branch)
{
	Long i = 0;
	Long length;
	Shape *currentItem;

	length = branch->GetLength();

	while (i < branch->GetLength())
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			currentItem->Accept(*this);
		}
		i++;
	}
	branch->SetHeight(0);
}

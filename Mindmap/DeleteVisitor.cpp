//DeleteVisitor.cpp

#include "DeleteVisitor.h"
#include "Branch.h"
#include "Topic.h"

DeleteVisitor::DeleteVisitor()
{
	this->select = NULL;
}

DeleteVisitor::DeleteVisitor(Branch *select)
{
	this->select = select;
}
DeleteVisitor::~DeleteVisitor()
{
}

void DeleteVisitor::VisitBranch(Branch *branch)
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
			if (currentItem ==this->select)
			{
				branch->Remove(i);
			}
			currentItem->Accept(*this);
		}
		i++;
	}

}
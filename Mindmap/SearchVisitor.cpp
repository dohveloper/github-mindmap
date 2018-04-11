//SearchVisitor.cpp

#include "SearchVisitor.h"
#include "Branch.h"
#include "Topic.h"
#include "PageForm.h"

SearchVisitor::SearchVisitor()
{
}

SearchVisitor::SearchVisitor(BranchArray *branchArray)
{
	this->branchArray = branchArray;
}

SearchVisitor::~SearchVisitor()
{
}

void SearchVisitor::VisitBranch(Branch *branch)
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
			currentItem->Accept(*this);
		}
		else if (typeid(*currentItem) == typeid(Topic))
		{
			if (currentItem->GetContent() == "메인토픽")
			{
				branchArray->Add(currentItem->GetOwnerBranch());
			}
		}
		i++;
	}

}
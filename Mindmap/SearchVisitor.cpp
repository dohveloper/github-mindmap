//SearchVisitor.cpp

#include "SearchVisitor.h"
#include "Branch.h"
#include "Topic.h"
#include "PageForm.h"
#include "BranchArray.h"

SearchVisitor::SearchVisitor()
{
}

SearchVisitor::SearchVisitor(PageForm *pageForm)
{
	this->pageForm = pageForm;
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
			if (currentItem->GetContent() == "")//""대신에 찾을 검색어 넣기
			{
				this->pageForm->branchArray.Add(currentItem->GetOwnerBranch());
			}
		}
		i++;
	}

}
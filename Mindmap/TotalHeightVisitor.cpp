//TotalHeightVisitor.cpp

#include "TotalHeightVisitor.h"
#include "Branch.h"
#include "Topic.h"
#define vInterval 10

TotalHeightVisitor::TotalHeightVisitor()
{
}

TotalHeightVisitor::TotalHeightVisitor(Long totalHeight)
{
}

TotalHeightVisitor::~TotalHeightVisitor()
{
}

void TotalHeightVisitor::VisitBranch(Branch *branch)
{
	Long i = 0;
	Long length;
	Shape *currentItem;
	Long branchCount = 0;

	length = branch->GetLength();

	while (i < branch->GetLength())//브랜치 개수 카운트
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			branchCount++;
		}
		i++;
	}

	i = 0;
	while (i < branch->GetLength() && branchCount != 0)
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			currentItem->Accept(*this);
		}
		i++;
	}

	if (branchCount > 0)
	{
		branch->GetOwnerBranch()->SetHeight(branch->GetOwnerBranch()->GetHeight() + branch->GetHeight() + vInterval * (branchCount / 2 - 1));
		if (branch->GetOwnerBranch()->GetHeight() < branch->GetTopic()->GetHeight())
		{
			branch->GetOwnerBranch()->SetHeight(branch->GetTopic()->GetHeight());
		}
	}
	else
	{
		branch->GetOwnerBranch()->SetHeight(branch->GetOwnerBranch()->GetHeight() + branch->GetTopic()->GetHeight());
	}
}

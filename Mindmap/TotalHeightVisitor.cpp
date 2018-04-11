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

	while (i < length)//브랜치 개수 카운트
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			branchCount++;
		}
		i++;
	}

	i = 0;
	while (i < length && branchCount != 0)
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			currentItem->Accept(*this);
		}
		i++;
	}

	if (branchCount > 0)//하위 브랜치가 있을 때
	{
		branch->SetHeight(branch->GetHeight() + vInterval * (branchCount - 1));//간격추가
		if (branch->GetHeight() < branch->GetTopic()->GetHeight())
		{
			branch->SetHeight(branch->GetTopic()->GetHeight());
		}
		branch->GetOwnerBranch()->SetHeight(branch->GetOwnerBranch()->GetHeight() + branch->GetHeight());
	}
	else//하위 브랜치가 없을 때
	{
		branch->SetHeight(branch->GetTopic()->GetHeight());
		branch->GetOwnerBranch()->SetHeight(branch->GetOwnerBranch()->GetHeight() + branch->GetTopic()->GetHeight());
	}
}

//ArrangeVisitor.cpp

#include "ArrangeVisitor.h"
#include "Branch.h"
#include "Topic.h"
#define hInterval 10
#define vInterval 10


ArrangeVisitor::ArrangeVisitor()
{
}

ArrangeVisitor::~ArrangeVisitor()
{
}

void ArrangeVisitor::VisitBranch(Branch *branch)
{
	Long length;
	Long i = 0;
	Shape *currentItem;
	Long branchCount = 0;
	Long branchPosition = 0;
	Long mostLeft = 0;
	Long tempX;
	Long j = 0;
	Long totalHeight = 0;
	Long mostUp = 0;
	Long tempY;

	length = branch->GetLength();

	while (i < length)//브랜치개수, 브랜치 시작지점 찾기
	{
		currentItem = branch->GetOwnerBranch()->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			branchCount++;
		}
		else
		{
			branchPosition++;
		}
		i++;
	}

	i = 0;
	j = branchPosition;
	while (i < branchCount / 2)//가장 왼쪽, 위쪽에 위치한 브랜치(토픽)찾기
	{
		tempX = branch->GetOwnerBranch()->GetAt(j)->GetX() - hInterval - branch->GetTopic()->GetWidth();
		tempY = branch->GetOwnerBranch()->GetAt(j)->GetY();

		if (tempX < mostLeft)
		{
			mostLeft = tempX;
		}

		if (tempY > mostUp)
		{
			mostUp = tempY;
		}
	}

	i = 0;
	j = branchPosition;
	while (i < branchCount / 2)//가로정렬
	{
		branch->GetOwnerBranch()->GetAt(j)->SetX(mostLeft);
		j++;
		i++;
	}

	/////////////////////


	i = 0;
	j = branchPosition;
	while (i < branchCount / 2)//세로 총높이  ???하위 브랜치 있으면 계산해야함.
	{
		totalHeight += branch->GetOwnerBranch()->GetAt(j)->GetHeight();
		j++;
		i++;
	}

	

	
	
	//branch->GetOwnerBranch()->GetTopic()->GetX() - hInterval - branch->GetTopic()->GetWidth();
}

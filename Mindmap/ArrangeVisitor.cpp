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
	Long centerY;
	Long currentY;
	Long selectTopic;
	Array<Branch*> temp;
	Long k = 0;

	length = branch->GetOwnerBranch()->GetLength();

	while (i < length)//브랜치개수, 브랜치 시작지점 찾기
	{
		currentItem = branch->GetOwnerBranch()->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			branchCount++;//브랜치 개수
		}
		else
		{
			branchPosition++;//브랜치가 시작되는 지점
		}
		i++;
	}

	i = 0;
	j = branchPosition;
	while (i < branchCount / 2)//가장 왼쪽위치한 브랜치(토픽)찾기
	{
		//오너브랜치의 브랜치들 중 가장 좌측의 브랜치 찾기
		tempX = ((Branch*)branch->GetOwnerBranch()->GetAt(j))->GetTopic()->GetX() - hInterval - branch->GetTopic()->GetWidth();

		if (tempX < mostLeft)
		{
			mostLeft = tempX;
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

	/*
	i = 0;
	j = branchPosition;
	while (i < branchCount / 2)//세로 총높이  ???하위 브랜치 있으면 계산해야함.
	{
		totalHeight += branch->GetOwnerBranch()->GetAt(j)->GetHeight();
		j++;
		i++;
	}

	centerY = branch->GetOwnerBranch()->GetTopic()->GetY() + branch->GetOwnerBranch()->GetTopic()->GetHeight() / 2;
	currentY = centerY + totalHeight / 2;
	
	i = 0;
	j = branchPosition;
	while (i < branchCount / 2)
	{
		tempY = branch->GetOwnerBranch()->GetAt(j)->GetY();


		if (tempY > mostUp)
		{
			mostUp = tempY;
			selectTopic = j;
			temp[k] = ;

		}

	}

	branch->GetOwnerBranch()->GetAt(j)->SetY(currentY);

	*/



}

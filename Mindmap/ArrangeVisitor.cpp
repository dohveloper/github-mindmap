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

	while (i < length)//�귣ġ����, �귣ġ �������� ã��
	{
		currentItem = branch->GetOwnerBranch()->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			branchCount++;//�귣ġ ����
		}
		else
		{
			branchPosition++;//�귣ġ�� ���۵Ǵ� ����
		}
		i++;
	}

	i = 0;
	j = branchPosition;
	while (i < branchCount / 2)//���� ������ġ�� �귣ġ(����)ã��
	{
		//���ʺ귣ġ�� �귣ġ�� �� ���� ������ �귣ġ ã��
		tempX = ((Branch*)branch->GetOwnerBranch()->GetAt(j))->GetTopic()->GetX() - hInterval - branch->GetTopic()->GetWidth();

		if (tempX < mostLeft)
		{
			mostLeft = tempX;
		}
	}

	i = 0;
	j = branchPosition;
	while (i < branchCount / 2)//��������
	{
		branch->GetOwnerBranch()->GetAt(j)->SetX(mostLeft);
		j++;
		i++;
	}

	/////////////////////

	/*
	i = 0;
	j = branchPosition;
	while (i < branchCount / 2)//���� �ѳ���  ???���� �귣ġ ������ ����ؾ���.
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

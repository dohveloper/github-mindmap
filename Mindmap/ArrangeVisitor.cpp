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

	while (i < length)//�귣ġ����, �귣ġ �������� ã��
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
	while (i < branchCount / 2)//���� ����, ���ʿ� ��ġ�� �귣ġ(����)ã��
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
	while (i < branchCount / 2)//��������
	{
		branch->GetOwnerBranch()->GetAt(j)->SetX(mostLeft);
		j++;
		i++;
	}

	/////////////////////


	i = 0;
	j = branchPosition;
	while (i < branchCount / 2)//���� �ѳ���  ???���� �귣ġ ������ ����ؾ���.
	{
		totalHeight += branch->GetOwnerBranch()->GetAt(j)->GetHeight();
		j++;
		i++;
	}

	

	
	
	//branch->GetOwnerBranch()->GetTopic()->GetX() - hInterval - branch->GetTopic()->GetWidth();
}

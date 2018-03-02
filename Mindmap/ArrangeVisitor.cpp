//ArrangeVisitor.cpp

#include "ArrangeVisitor.h"
#include "Branch.h"
#include "Topic.h"
#include "Line.h"
#include "TotalHeightVisitor.h"
#define hInterval 30
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
	Long mostLeft;
	Long mostWidth;
	Long tempX;
	Long j;
	Long totalHeight = 0;
	Long centerY;
	Long currentY;
	Array<Branch*> temp;
	Long mostRight;
	Long lineWidth;
	Long lineHeight;
	Long branchHeight;

	length = branch->GetLength();


	while (i < length)//�귣ġ����, �귣ġ �������� ã��
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			currentItem->Accept(*this);
			branchCount++;//�귣ġ ����
		}
		else
		{
			branchPosition++;//�귣ġ�� ���۵Ǵ� ����
		}
		i++;
	}

	if (typeid(*branch->GetAt(0)) == typeid(Topic))//������ �����귣ġ ����
	{
		//���κ귣ġ�� ���� �귣ġ ����
		i = 0;
		j = branchPosition;
		mostLeft = branch->GetTopic()->GetX();

		while (i < branchCount / 2)
		{
			tempX = branch->GetTopic()->GetX() - hInterval - ((Branch*)branch->GetAt(j))->GetTopic()->GetWidth();//�귣ġ�� x��ǥ - ����- �����귣ġ�� ����

			if (tempX < mostLeft)
			{
				mostLeft = tempX;
				mostWidth= ((Branch*)branch->GetAt(j))->GetTopic()->GetWidth();
			}
			j++;
			i++;
		}
		i = 0;
		j = branchPosition;
		while (i < branchCount / 2)//��������
		{
			((Branch*)branch->GetAt(j))->GetTopic()->SetX(mostLeft + (mostWidth - ((Branch*)branch->GetAt(j))->GetTopic()->GetWidth()));
			lineWidth = ((Branch*)branch->GetAt(j))->GetTopic()->GetX() + (((Branch*)branch->GetAt(j))->GetTopic()->GetWidth()) / 2 - ((Branch*)branch->GetAt(j))->GetLine()->GetX();
			((Branch*)branch->GetAt(j))->GetLine()->SetWidth(lineWidth);
			((Branch*)branch->GetAt(j))->GetMark()->SetX(mostLeft + (mostWidth - ((Branch*)branch->GetAt(j))->GetTopic()->GetWidth()) + 14 * (((Branch*)branch->GetAt(j))->GetTopic()->GetWidth()) / 15);
			j++;
			i++;
		}

		i = 0;
		j = branchPosition;
		while (i < branchCount / 2)//���� �ѳ���  ???���� �귣ġ ������ ����ؾ���.
		{
			//branchHeight = ((Branch*)branch->GetAt(j))->GetTotalHeight();
			totalHeight += ((Branch*)branch->GetAt(j))->GetTopic()->GetHeight();
			j++;
			i++;
		}
		/*
		TotalHeightVisitor totalHeightVisitor;
		branch->Accept(totalHeightVisitor);
		totalHeight = totalHeightVisitor.GetTotalHeight();
		totalHeight += vInterval * (branchCount / 2 - 1);
		totalHeight = branch->GetTotalHeight();
		*/


		centerY = branch->GetTopic()->GetY() + branch->GetTopic()->GetHeight() / 2;
		currentY = centerY - totalHeight / 2;

		i = 0;
		j = branchPosition;
		while (i < branchCount / 2)
		{
			((Branch*)branch->GetAt(j))->GetTopic()->SetY(currentY);
			lineHeight = currentY + (((Branch*)branch->GetAt(j))->GetTopic()->GetHeight()) / 2 - centerY;
			((Branch*)branch->GetAt(j))->GetLine()->SetHeight(lineHeight);
			((Branch*)branch->GetAt(j))->GetMark()->SetY(currentY + (((Branch*)branch->GetAt(j))->GetTopic()->GetHeight()) / 4);
			currentY = currentY + ((Branch*)branch->GetAt(j))->GetTopic()->GetHeight() + vInterval;
			j++;
			i++;
		}

		//���κ귣ġ�� ���� �귣ġ ����

		branchPosition = j;

		mostRight = branch->GetTopic()->GetX() + branch->GetTopic()->GetWidth() + hInterval;
		
		i = branchPosition;
		while (i < length)//��������
		{
			((Branch*)branch->GetAt(i))->GetTopic()->SetX(mostRight);
			lineWidth = mostRight + (((Branch*)branch->GetAt(i))->GetTopic()->GetWidth()) / 2 - ((Branch*)branch->GetAt(i))->GetLine()->GetX();
			((Branch*)branch->GetAt(i))->GetLine()->SetWidth(lineWidth);
			((Branch*)branch->GetAt(i))->GetMark()->SetX(mostRight + 14 * (((Branch*)branch->GetAt(i))->GetTopic()->GetWidth()) / 15);
			i++;
		}

		/*
		i = branchPosition;
		while (i < length)
		{
			tempX = branch->GetTopic()->GetX() + branch->GetTopic()->GetWidth() + hInterval + ((Branch*)branch->GetAt(i))->GetTopic()->GetWidth();//�귣ġ�� x��ǥ - ����- �����귣ġ�� ����


			if (tempX > mostRight)
			{
				mostRight = tempX;
			}
			i++;
		}
		*/
		/*
		TotalHeightVisitor totalHeightVisitor;
		branch->Accept(totalHeightVisitor);
		totalHeight = totalHeightVisitor.GetTotalHeight();
		totalHeight += vInterval * (branchCount / 2 - 1);
		totalHeight = branch->GetTotalHeight();
		TotalHeightVisitor totalHeightVisitor;
		if (branch->GetHeight() == 0)
		{
		branch->Accept(totalHeightVisitor);
		}

		totalHeight = branch->GetHeight();
	    */

		totalHeight = 0;
		i = branchPosition;
		while (i < length)//���� �ѳ���  ???���� �귣ġ ������ ����ؾ���.
		{

			totalHeight += ((Branch*)branch->GetAt(i))->GetTopic()->GetHeight();
			i++;
		}	

		totalHeight += vInterval * (branchCount / 2 - 1);

		centerY = branch->GetTopic()->GetY() + branch->GetTopic()->GetHeight() / 2;
		currentY = centerY - totalHeight / 2;

		i = branchPosition;
		while (i < length)
		{
			((Branch*)branch->GetAt(i))->GetTopic()->SetY(currentY);
			lineHeight = currentY + (((Branch*)branch->GetAt(i))->GetTopic()->GetHeight()) / 2 - centerY;
			((Branch*)branch->GetAt(i))->GetLine()->SetHeight(lineHeight);
			((Branch*)branch->GetAt(i))->GetMark()->SetY(currentY + (((Branch*)branch->GetAt(i))->GetTopic()->GetHeight()) / 4);
			currentY = currentY + ((Branch*)branch->GetAt(i))->GetTopic()->GetHeight() + vInterval;
			i++;


		}
	}


	/////////////////////////////
	else if (branch->GetTopic()->GetX() < 487)//������
	{
		i = 0;
		j = branchPosition;
		mostLeft = branch->GetTopic()->GetX();

		while (i < branchCount)
		{
			tempX = branch->GetTopic()->GetX() - hInterval - ((Branch*)branch->GetAt(j))->GetTopic()->GetWidth();//�귣ġ�� x��ǥ - ����- �����귣ġ�� ����


			if (tempX < mostLeft)
			{
				mostLeft = tempX;
				mostWidth = ((Branch*)branch->GetAt(j))->GetTopic()->GetWidth();
			}
			j++;
			i++;
		}

		i = 0;
		j = branchPosition;
		while (i < branchCount)//��������
		{
			((Branch*)branch->GetAt(j))->GetTopic()->SetX(mostLeft + (mostWidth - ((Branch*)branch->GetAt(j))->GetTopic()->GetWidth()));
			((Branch*)branch->GetAt(j))->GetLine()->SetX(branch->GetTopic()->GetX() + (branch->GetTopic()->GetWidth()) / 2);
			lineWidth = ((Branch*)branch->GetAt(j))->GetTopic()->GetX() + (((Branch*)branch->GetAt(j))->GetTopic()->GetWidth()) / 2 - ((Branch*)branch->GetAt(j))->GetLine()->GetX();
			((Branch*)branch->GetAt(j))->GetLine()->SetWidth(lineWidth);
			((Branch*)branch->GetAt(j))->GetMark()->SetX(mostLeft + (mostWidth - ((Branch*)branch->GetAt(j))->GetTopic()->GetWidth()) + 14 * (((Branch*)branch->GetAt(j))->GetTopic()->GetWidth()) / 15);
			j++;
			i++;
		}

		i = 0;
		j = branchPosition;
		while (i < branchCount)//���� �ѳ���  ???���� �귣ġ ������ ����ؾ���.
		{
			totalHeight += ((Branch*)branch->GetAt(j))->GetTopic()->GetHeight();
			j++;
			i++;
		}

		totalHeight += vInterval * (branchCount - 1);

		centerY = branch->GetTopic()->GetY() + branch->GetTopic()->GetHeight() / 2;
		currentY = centerY - totalHeight / 2;

		i = 0;
		j = branchPosition;
		while (i < branchCount)
		{
			((Branch*)branch->GetAt(j))->GetTopic()->SetY(currentY);
			((Branch*)branch->GetAt(j))->GetLine()->SetY(centerY);
			lineHeight = currentY + (((Branch*)branch->GetAt(j))->GetTopic()->GetHeight()) / 2 - centerY;
			((Branch*)branch->GetAt(j))->GetLine()->SetHeight(lineHeight);
			((Branch*)branch->GetAt(j))->GetMark()->SetY(currentY + (((Branch*)branch->GetAt(j))->GetTopic()->GetHeight()) / 4);
			currentY = currentY + ((Branch*)branch->GetAt(j))->GetTopic()->GetHeight() + vInterval;
			j++;
			i++;
		}

	}
	//////////////////////////////////
	else if (branch->GetTopic()->GetX() > 487)//������
	{
		mostRight = branch->GetTopic()->GetX() + branch->GetTopic()->GetWidth() + hInterval;

		i = branchPosition;
		while (i < length)//��������
		{
			((Branch*)branch->GetAt(i))->GetTopic()->SetX(mostRight);
			lineWidth = mostRight + (((Branch*)branch->GetAt(i))->GetTopic()->GetWidth()) / 2 - ((Branch*)branch->GetAt(i))->GetLine()->GetX();
			((Branch*)branch->GetAt(i))->GetLine()->SetX(branch->GetTopic()->GetX() + (branch->GetTopic()->GetWidth()) / 2);
			((Branch*)branch->GetAt(i))->GetLine()->SetWidth(lineWidth);
			((Branch*)branch->GetAt(i))->GetMark()->SetX(mostRight + 14 * (((Branch*)branch->GetAt(i))->GetTopic()->GetWidth()) / 15);
			i++;
		}

		/*
		totalHeight = 0;
		i = branchPosition;
		while (i < length)//���� �ѳ���  ???���� �귣ġ ������ ����ؾ���.
		{

			totalHeight += ((Branch*)branch->GetAt(i))->GetTopic()->GetHeight();
			i++;
		}
		*/
		
		totalHeight = branch->GetHeight();
		totalHeight += vInterval * (branchCount - 1);
		
		centerY = branch->GetTopic()->GetY() + branch->GetTopic()->GetHeight() / 2;
		currentY = centerY - totalHeight / 2;

		i = branchPosition;
		while (i < length)
		{
			((Branch*)branch->GetAt(i))->GetTopic()->SetY(currentY);
			lineHeight = currentY + (((Branch*)branch->GetAt(i))->GetTopic()->GetHeight()) / 2 - centerY;
			((Branch*)branch->GetAt(i))->GetLine()->SetY(centerY);
			((Branch*)branch->GetAt(i))->GetLine()->SetHeight(lineHeight);
			((Branch*)branch->GetAt(i))->GetMark()->SetY(currentY + (((Branch*)branch->GetAt(i))->GetTopic()->GetHeight()) / 4);
			
			currentY = currentY + ((Branch*)branch->GetAt(i))->GetTopic()->GetHeight() + vInterval;
			/*
			if (branch->GetAt(i)->GetHeight() == 0 && 4 > length)
			{
				branchHeight = ((Branch*)branch->GetAt(i))->GetTopic()->GetHeight();
			}
			else
			{
				branchHeight = branch->GetHeight();
			}
			currentY = currentY + branchHeight + vInterval;
			*/
			
			i++;
		}
	}

	i = 0;
	while (i < length)//�����귣ġ ����
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			currentItem->Accept(*this);
		}
		i++;
	}
	i = 0;
	while (i < length)//�����귣ġ ����
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			currentItem->Accept(*this);
		}
		i++;
	}
}

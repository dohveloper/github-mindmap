//ArrangeVisitor.cpp

#include "ArrangeVisitor.h"
#include "Branch.h"
#include "Topic.h"
#include "Line.h"
#include "TotalHeightVisitor.h"
#define hInterval 30
#define vInterval 5

ArrangeVisitor::ArrangeVisitor()
{
}

ArrangeVisitor::ArrangeVisitor(Long x)
{
	this->x = x;
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
	Long mostWidth = 0;
	Long tempX;
	Long j;
	Long totalHeight = 0;
	Long addHeight = 0;
	Long leftHeight = 0;
	Long centerY = 0;
	Long currentY = 0;
	Long realY;
	Long mostRight;
	Long lineWidth;
	Long lineHeight;
	Long leftCount = 0;

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
			totalHeight += branch->GetAt(j)->GetHeight();
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
		while (i < branchCount / 2)//��������
		{
			((Branch*)branch->GetAt(j))->GetTopic()->SetX(mostLeft + (mostWidth - ((Branch*)branch->GetAt(j))->GetTopic()->GetWidth()));
			lineWidth = ((Branch*)branch->GetAt(j))->GetTopic()->GetX() + (((Branch*)branch->GetAt(j))->GetTopic()->GetWidth()) / 2 - ((Branch*)branch->GetAt(j))->GetLine()->GetX();
			((Branch*)branch->GetAt(j))->GetLine()->SetWidth(lineWidth);
			((Branch*)branch->GetAt(j))->GetMark()->SetX(mostLeft + (mostWidth - ((Branch*)branch->GetAt(j))->GetTopic()->GetWidth()) + 14 * (((Branch*)branch->GetAt(j))->GetTopic()->GetWidth()) / 15);
			j++;
			i++;
		}

		centerY = branch->GetTopic()->GetY() + branch->GetTopic()->GetHeight() / 2;

		if (branchCount > 1)
		{
			realY = centerY - totalHeight / 2;
			currentY = realY + branch->GetAt(branchPosition)->GetHeight() / 2 - ((Branch*)branch->GetAt(branchPosition))->GetTopic()->GetHeight() / 2;
		}
		else
		{
			realY = centerY;
			currentY = realY;
		}

		if (branchCount == 2)
		{
			realY = centerY - ((Branch*)branch->GetAt(branchPosition))->GetTopic()->GetHeight() / 2;
			currentY = realY;
		}

		i = 0;
		j = branchPosition;
		while (i < branchCount / 2)
		{
			((Branch*)branch->GetAt(j))->GetTopic()->SetY(currentY);
			lineHeight = currentY + (((Branch*)branch->GetAt(j))->GetTopic()->GetHeight()) / 2 - centerY;
			((Branch*)branch->GetAt(j))->GetLine()->SetHeight(lineHeight);
			((Branch*)branch->GetAt(j))->GetMark()->SetY(currentY + (((Branch*)branch->GetAt(j))->GetTopic()->GetHeight()) / 4);

			if (j + 1 < length)
			{
				currentY = realY + branch->GetAt(j)->GetHeight() + branch->GetAt(j + 1)->GetHeight() / 2 - ((Branch*)branch->GetAt(j + 1))->GetTopic()->GetHeight() / 2 + vInterval;
			}
			else
			{
				currentY = realY + branch->GetAt(j)->GetHeight() + vInterval;
			}
			realY = realY + branch->GetAt(j)->GetHeight() + vInterval;
			j++;
			i++;
		}

		//���κ귣ġ�� ���� �귣ġ ����

		branchPosition = j;

		mostRight = branch->GetTopic()->GetX() + branch->GetTopic()->GetWidth() + hInterval;
		totalHeight = 0;
		i = branchPosition;
		while (i < length)//��������
		{
			((Branch*)branch->GetAt(i))->GetTopic()->SetX(mostRight);
			lineWidth = mostRight + (((Branch*)branch->GetAt(i))->GetTopic()->GetWidth()) / 2 - ((Branch*)branch->GetAt(i))->GetLine()->GetX();
			((Branch*)branch->GetAt(i))->GetLine()->SetWidth(lineWidth);
			((Branch*)branch->GetAt(i))->GetMark()->SetX(mostRight + 14 * (((Branch*)branch->GetAt(i))->GetTopic()->GetWidth()) / 15);
			totalHeight += branch->GetAt(i)->GetHeight();//���� ���� �� ���
			i++;
		}

		centerY = branch->GetTopic()->GetY() + branch->GetTopic()->GetHeight() / 2;

		if (branchCount > 2)
		{
			realY = centerY - totalHeight / 2;
			currentY = realY + branch->GetAt(branchPosition)->GetHeight() / 2 - ((Branch*)branch->GetAt(branchPosition))->GetTopic()->GetHeight() / 2;
		}
		else
		{
			realY = centerY;
			currentY = realY;
		}

		if (branchCount > 0 && branchCount < 3)
		{
			realY = centerY - ((Branch*)branch->GetAt(branchPosition))->GetTopic()->GetHeight() / 2;
			currentY = realY;
		}

		i = branchPosition;
		while (i < length)
		{
			((Branch*)branch->GetAt(i))->GetTopic()->SetY(currentY);
			lineHeight = currentY + (((Branch*)branch->GetAt(i))->GetTopic()->GetHeight()) / 2 - centerY;
			((Branch*)branch->GetAt(i))->GetLine()->SetHeight(lineHeight);
			((Branch*)branch->GetAt(i))->GetMark()->SetY(currentY + (((Branch*)branch->GetAt(i))->GetTopic()->GetHeight()) / 4);

			if (i + 1 < length)
			{
				currentY = realY + branch->GetAt(i)->GetHeight() + branch->GetAt(i + 1)->GetHeight() / 2 - ((Branch*)branch->GetAt(i + 1))->GetTopic()->GetHeight() / 2 + vInterval;
			}
			else
			{
				currentY = realY + branch->GetAt(i)->GetHeight() + vInterval;
			}
			realY = realY + branch->GetAt(i)->GetHeight() + vInterval;
			i++;
		}
	}


	/////////////////////////////
	else if (branch->GetTopic()->GetX() < this->x)//������
	{
		i = branchPosition;
		mostLeft = branch->GetTopic()->GetX();

		while (i < length)
		{
			tempX = branch->GetTopic()->GetX() - hInterval - ((Branch*)branch->GetAt(i))->GetTopic()->GetWidth();//�귣ġ�� x��ǥ - ����- �����귣ġ�� ����


			if (tempX < mostLeft)
			{
				mostLeft = tempX;
				mostWidth = ((Branch*)branch->GetAt(i))->GetTopic()->GetWidth();
			}
			i++;
		}

		i = branchPosition;
		while (i < length)//��������
		{
			((Branch*)branch->GetAt(i))->GetTopic()->SetX(mostLeft + (mostWidth - ((Branch*)branch->GetAt(i))->GetTopic()->GetWidth()));
			((Branch*)branch->GetAt(i))->GetLine()->SetX(branch->GetTopic()->GetX() + (branch->GetTopic()->GetWidth()) / 2);
			lineWidth = ((Branch*)branch->GetAt(i))->GetTopic()->GetX() + (((Branch*)branch->GetAt(i))->GetTopic()->GetWidth()) / 2 - ((Branch*)branch->GetAt(i))->GetLine()->GetX();
			((Branch*)branch->GetAt(i))->GetLine()->SetWidth(lineWidth);
			((Branch*)branch->GetAt(i))->GetMark()->SetX(mostLeft + (mostWidth - ((Branch*)branch->GetAt(i))->GetTopic()->GetWidth()) + 14 * (((Branch*)branch->GetAt(i))->GetTopic()->GetWidth()) / 15);
			i++;
		}

		totalHeight = branch->GetHeight();

		centerY = branch->GetTopic()->GetY() + branch->GetTopic()->GetHeight() / 2;

		if (branchCount > 0)
		{
			if (branchCount == 1)
			{
				realY = centerY - ((Branch*)branch->GetAt(branchPosition))->GetTopic()->GetHeight() / 2;
				currentY = realY;
			}
			else
			{
				realY = centerY - totalHeight / 2;
				currentY = realY + branch->GetAt(branchPosition)->GetHeight() / 2 - ((Branch*)branch->GetAt(branchPosition))->GetTopic()->GetHeight() / 2;
			}
		}
		else
		{
			realY = centerY;
			currentY = realY;
		}

		i = branchPosition;
		while (i < length)//��������
		{
			((Branch*)branch->GetAt(i))->GetTopic()->SetY(currentY);
			((Branch*)branch->GetAt(i))->GetLine()->SetY(centerY);
			lineHeight = currentY + (((Branch*)branch->GetAt(i))->GetTopic()->GetHeight()) / 2 - centerY;
			((Branch*)branch->GetAt(i))->GetLine()->SetHeight(lineHeight);
			((Branch*)branch->GetAt(i))->GetMark()->SetY(currentY + (((Branch*)branch->GetAt(i))->GetTopic()->GetHeight()) / 4);

			if (i + 1 < length)
			{
				currentY = realY + branch->GetAt(i)->GetHeight() + branch->GetAt(i + 1)->GetHeight() / 2 - ((Branch*)branch->GetAt(i + 1))->GetTopic()->GetHeight() / 2 + vInterval;
			}
			else
			{
				currentY = realY + branch->GetAt(i)->GetHeight() + vInterval;
			}
			realY = realY + branch->GetAt(i)->GetHeight() + vInterval;
			i++;
		}
	}
	//////////////////////////////////
	else if (branch->GetTopic()->GetX() > this->x)//������
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

		totalHeight = branch->GetHeight();

		centerY = branch->GetTopic()->GetY() + branch->GetTopic()->GetHeight() / 2;

		if (branchCount > 0)
		{
			if (branchCount == 1)
			{
				realY = centerY - ((Branch*)branch->GetAt(branchPosition))->GetTopic()->GetHeight() / 2;
				currentY = realY;
			}
			else
			{
				realY = centerY - totalHeight / 2;
				currentY = realY + branch->GetAt(branchPosition)->GetHeight() / 2 - ((Branch*)branch->GetAt(branchPosition))->GetTopic()->GetHeight() / 2;
			}
		}
		else
		{
			realY = centerY;
			currentY = realY;
		}

		i = branchPosition;
		while (i < length)//��������
		{
			((Branch*)branch->GetAt(i))->GetTopic()->SetY(currentY);
			lineHeight = currentY + (((Branch*)branch->GetAt(i))->GetTopic()->GetHeight()) / 2 - centerY;
			((Branch*)branch->GetAt(i))->GetLine()->SetY(centerY);
			((Branch*)branch->GetAt(i))->GetLine()->SetHeight(lineHeight);
			((Branch*)branch->GetAt(i))->GetMark()->SetY(currentY + (((Branch*)branch->GetAt(i))->GetTopic()->GetHeight()) / 4);

			if (i + 1 < length)
			{
				currentY = realY + branch->GetAt(i)->GetHeight() + branch->GetAt(i + 1)->GetHeight() / 2 - ((Branch*)branch->GetAt(i + 1))->GetTopic()->GetHeight() / 2 + vInterval;
			}
			else
			{
				currentY = realY + branch->GetAt(i)->GetHeight() + vInterval;
			}
			realY = realY + branch->GetAt(i)->GetHeight() + vInterval;
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
}

//OverlappedConfirmVisitor.cpp

#include "OverlappedConfirmVisitor.h"
#include "Branch.h"
#include "Topic.h"

OverlappedConfirmVisitor::OverlappedConfirmVisitor()
	:rectA(), rectB()
{
	this->isOverlapped = false;
}

OverlappedConfirmVisitor::OverlappedConfirmVisitor(CRect rectA, CRect rectB)
	: rectA(rectA), rectB(rectB)
{
	this->isOverlapped = false;
}
OverlappedConfirmVisitor::~OverlappedConfirmVisitor()
{
}

void OverlappedConfirmVisitor::VisitBranch(Branch *branch)
{
	Long i = 0;
	Long length;
	Long areaX1;
	Long areaY1;
	Long areaX2;
	Long areaY2;
	Shape *currentItem;

	length = branch->GetLength();

	while (i < length)
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Topic))
		{
			areaX1 = currentItem->GetX();
			areaY1 = currentItem->GetY();
			areaX2 = currentItem->GetX() + currentItem->GetWidth();
			areaY2 = currentItem->GetY() + currentItem->GetHeight();

			CRect rectC(areaX1, areaY1, areaX2, areaY2);

			if (this->rectB.IntersectRect(rectA, rectC) == TRUE)
			{
				this->isOverlapped = TRUE;
			}
		}
		if (typeid(*currentItem) == typeid(Branch))
		{
			currentItem->Accept(*this);
		}
		i++;
	}
}
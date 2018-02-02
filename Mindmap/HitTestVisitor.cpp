#include "HitTestVisitor.h"
#include "Topic.h"
#include "Line.h"
#include "Branch.h"
#include "MouseAction.h"
#include "SelectionStrategy.h"

HitTestVisitor::HitTestVisitor() {
}

HitTestVisitor::HitTestVisitor(CPoint point, MouseAction * mouseAction, Branch **clickedBranch)
{
	this->point = point;
	this->mouseAction = mouseAction;
	this->clickedBranch = clickedBranch;
}


HitTestVisitor::~HitTestVisitor() {

}
void HitTestVisitor::VisitTopic(Topic *topic) {
	
}

void HitTestVisitor::VisitBranch(Branch *branch)
{
	
	Long length;
	Long x;
	Long y;
	Long a;
	Long b;
	Long value = 0;
	Long i = 0;
	Shape *currentItem;

	length = branch->GetLength();

	while (i < length && *(this->clickedBranch)==NULL)
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Topic))
		{
			x = point.x - (currentItem->GetX() + currentItem->GetWidth() / 2);
			y = point.y - (currentItem->GetY() + currentItem->GetHeight() / 2);
			a = currentItem->GetWidth() / 2;
			b = currentItem->GetHeight() / 2;
			value = ((x*x) / (a*a)) + ((y*y) / (b*b)); // 타원방정식 ((x*x) / (a*a)) + ((y*y) / (b*b)) =1
			if (value <= 0.8)
			{
				*(this->clickedBranch) = branch;
			}
			
		}
		if (typeid(*currentItem) == typeid(Branch))
		{	
			currentItem->Accept(*this);
		}
		i++;  
	}
	
}

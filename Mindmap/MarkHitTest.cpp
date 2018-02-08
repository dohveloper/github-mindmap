#include "MarkHitTest.h"
#include "Topic.h"
#include "Branch.h"

MarkHitTest::MarkHitTest(Branch *branch, CPoint point)
	:BranchTraverser(branch)
{
	this->point = point;
	this->hitMark = NULL;
	this->isHit = false;
}

bool MarkHitTest::ProcessItem(Shape *shape)
{
	Long x;
	Long y;
	Long a;
	Long b;
	Long value = 0;
	bool ret = true;

	if (typeid(*shape) == typeid(Mark))
	{
		x = this->point.x - (shape->GetX() + shape->GetWidth() / 2);
		y = this->point.y - (shape->GetY() + shape->GetHeight() / 2);
		a = shape->GetWidth() / 2;
		b = shape->GetHeight() / 2;
		value = ((x*x) / (a*a)) + ((y*y) / (b*b)); // 타원방정식 ((x*x) / (a*a)) + ((y*y) / (b*b)) =1
		if (value <= 0.8)
		{
			this->hitMark = (Mark*)shape;
			this->isHit = true;
			ret = false;
		}
	}
	if (typeid(*shape) == typeid(Branch))
	{
		if ((((Branch*)shape))->GetIsShown() == true) {
			MarkHitTest topicHitTest((Branch*)shape, this->point);
			ret = topicHitTest.Traverse();
			this->hitMark = topicHitTest.GetHitMark();
			this->isHit = topicHitTest.GetIsHit();
		}
	}
	return ret;
}
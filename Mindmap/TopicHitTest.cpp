#include "TopicHitTest.h"
#include "Topic.h"
#include "Branch.h"

TopicHitTest::TopicHitTest(Branch *branch, CPoint point)
	:BranchTraverser(branch)
{
	this->point = point;
	this->hitTopic = NULL;
	this->isHit = false;
}

bool TopicHitTest::ProcessItem(Shape *shape)
{
	Long x;
	Long y;
	Long a;
	Long b;
	Long value = 0;
	bool ret = true;

	if (typeid(*shape) == typeid(Topic))
	{
		x = this->point.x - (shape->GetX() + shape->GetWidth() / 2);
		y = this->point.y - (shape->GetY() + shape->GetHeight() / 2);
		a = shape->GetWidth() / 2;
		b = shape->GetHeight() / 2;
		value = ((x*x) / (a*a)) + ((y*y) / (b*b)); // 타원방정식 ((x*x) / (a*a)) + ((y*y) / (b*b)) =1
		if (value <= 0.8)
		{
			this->hitTopic = (Topic*)shape;
			this->isHit = true;
			ret = false;
		}
	}
	if (typeid(*shape) == typeid(Branch))
	{
		if ((((Branch*)shape))->GetIsShown() == true) {
			TopicHitTest topicHitTest((Branch*)shape, this->point);
			ret = topicHitTest.Traverse();
			this->hitTopic = topicHitTest.GetHitTopic();
			this->isHit = topicHitTest.GetIsHit();
		}
	}
	return ret;
}
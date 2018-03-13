#include "FlipTraverser.h"
#include "Branch.h"
#include "Topic.h"
#include "Line.h"
#include "Mark.h"

FlipTraverser::FlipTraverser(Branch *branch, Branch* centerBranch)
	:BranchTraverser(branch)
{
	this->centerBranch = centerBranch;
	this->centerLine = centerBranch->GetTopic()->GetCenterX();
	this->centerX = centerBranch->GetTopic()->GetX();
}

bool FlipTraverser::ProcessItem(Shape * shape)
{
	bool ret = true;
	Long previousX;
	Long y;
	Long width;
	Long height;
	Long newX;
	Long newWidth;

	Long interval;
	Topic *topic;
	Long centerX;
	Long topicWidth;

	previousX = shape->GetX();
	width = shape->GetWidth();

	if (typeid(*shape) == typeid(Topic)) {
		if (previousX < this->centerLine) {  //나중에 수정하게 되면 x말고 centerLine이용해서 수정할것
			interval = this->centerLine - previousX - width;
			newX = this->centerLine + interval;
		}
		else {
			interval = previousX - this->centerLine;
			newX = this->centerLine - interval - width;
		}
		shape->SetX(newX);
	}
	if (typeid(*shape) == typeid(Line)) {
		interval = previousX - this->centerLine;
		newX = this->centerLine - interval;
		shape->SetX(newX);

		newWidth = width * -1;
		shape->SetWidth(newWidth);
	}
	if (typeid(*shape) == typeid(Mark)) {
		topic = shape->GetOwnerBranch()->GetTopic();
		topicWidth = topic->GetWidth();

		if (previousX - topicWidth < this->centerLine) {    //<previousX - topicWidth>는 < topic의 "previousX"> 와 같음  .  나중에 수정하게 되면 x말고 centerLine이용해서 수정할것
			interval = this->centerLine - previousX - width;
			newX = this->centerLine + interval + topicWidth;
		}
		else {
			interval = previousX - this->centerLine - topicWidth;
			newX = this->centerLine - interval - width;
		}
		shape->SetX(newX);
	}
	if (typeid(*shape) == typeid(Branch)) {
		FlipTraverser traverser((Branch*)shape, this->centerBranch);
		traverser.Traverse();
	}

	return ret;
}
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
	Long width;
	Long newX;
	Long newWidth;
	Long interval;

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
		((Mark*)shape)->UpdatePosition();
	}
	if (typeid(*shape) == typeid(Branch)) {
		FlipTraverser traverser((Branch*)shape, this->centerBranch);
		traverser.Traverse();
	}

	return ret;
}
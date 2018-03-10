#include "FlipTraverser.h"
#include "Branch.h"
#include "Topic.h"
#include "Line.h"
#include "Mark.h"

FlipTraverser::FlipTraverser(Branch *branch, Long centerX)
	:BranchTraverser(branch)
{
	this->centerX = centerX;
}

bool FlipTraverser::ProcessItem(Shape * shape)
{
	bool ret = true;
	Long x;
	Long y;
	Long width;
	Long height;
	Long newX;
	Long newWidth;

	x = shape->GetX();
	width = shape->GetWidth();

	if (typeid(*shape) == typeid(Topic)) {
		newX = this->centerX * 2 - (x + width);  //centerX-newX-widthX = preX-centerX
		shape->SetX(newX);
	}
	if (typeid(*shape) == typeid(Line)) {
		newWidth = width * -1;
		shape->SetWidth(newWidth);
	}
	if (typeid(*shape) == typeid(Branch)) {
		FlipTraverser traverser((Branch*)shape, this->centerX);
		traverser.Traverse();
	}

	return ret;
}
#include "SubBranchDeselect.h"
#include "Branch.h"
#include "Shape.h"
#include "Selection.h"

SubBranchDeselect::SubBranchDeselect(Branch *branch, Selection *selection)
	:BranchTraverser(branch)
{
	this->selection = selection;
}

bool SubBranchDeselect::ProcessItem(Shape *shape)
{
	if (typeid(*shape) == typeid(Branch)) {
		if (this->selection->IsSelected((Branch*)shape) == true) {
			this->selection->Remove((Branch*)shape);
		}
		SubBranchDeselect subBranchDeselect((Branch*)shape, this->selection);
		subBranchDeselect.Traverse();
	}

	return true;
}
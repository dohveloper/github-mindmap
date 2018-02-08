#ifndef _SUBBRANCHDESELECT_H
#define _SUBBRANCHDESELECT_H
#include "BranchTraverser.h"

class Selection;
class SubBranchDeselect :public BranchTraverser {
public:
	SubBranchDeselect(Branch *branch, Selection *selection);

protected:
	virtual bool ProcessItem(Shape*);

private:
	Selection * selection;
};

#endif // _SUBBRANCHDESELECT_H
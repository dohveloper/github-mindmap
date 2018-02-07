#ifndef _BRANCHTRAVERSER_H
#define _BRANCHTRAVERSER_H
#include "BranchIterator.h"

class BranchTraverser{
public:
	BranchTraverser(Branch* branch);
	bool Traverse();

protected:
	virtual bool ProcessItem(Shape*) = 0;

private:
	BranchIterator iterator;
};

#endif //_BRANCHTRAVERSER_H
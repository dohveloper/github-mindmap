#ifndef _BRANCHTRAVERSER_H
#define _BRANCHTRAVERSER_H
#include "BranchIterator.h"
typedef signed long int Long;

class BranchTraverser {
public:
	BranchTraverser(Branch* branch);
	bool Traverse();

protected:
	virtual bool ProcessItem(Shape*) = 0;

	BranchIterator iterator;
};

#endif //_BRANCHTRAVERSER_H
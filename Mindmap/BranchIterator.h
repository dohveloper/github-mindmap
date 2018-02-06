#ifndef _BRANCHITERATOR_H
#define _BRANCHITERATOR_H
#include "Iterator.h"
class Branch;
class Shape;

class BranchIterator :public Iterator{
public:
	BranchIterator(Branch* branch);
	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual Shape* CurrentItem() const;

private:
	Branch *branch;
	long current;
};

#endif //_BRANCHITERATOR_H
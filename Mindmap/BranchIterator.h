#ifndef _BRANCHITERATOR_H
#define _BRANCHITERATOR_H
#include "Iterator.h"
typedef signed long int Long;
class Branch;
class Shape;
class BranchIterator :public Iterator {
public:
	BranchIterator(Branch* branch);
	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual Shape* CurrentItem() const;

	Long GetCurrent();

private:
	Branch * branch;
	Long current;
};

#endif //_BRANCHITERATOR_H
#ifndef _LINEITERATOR_H
#define _LINEITERATOR_H_
#include "Iterator.h"
class Branch;

class LineIterator :public Iterator{
public:
	LineIterator(Branch* branch);
	virtual void First();
	virtual void Next();
	virtual bool IsDone() const;
	virtual Shape* CurrentItem() const;

private:
	Branch *branch;
	Shape *current;
};

#endif //_LINEITERATOR_H_
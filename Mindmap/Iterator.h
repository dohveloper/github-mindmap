#ifndef _ITERATOR_H
#define _ITERATOR_H

#include "Shape.h"

class Iterator {
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual Shape* CurrentItem() const = 0;
protected:
	Iterator();
};

Iterator::Iterator() {

}

#endif //_Iterator_H
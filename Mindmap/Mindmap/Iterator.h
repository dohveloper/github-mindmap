#ifndef _ITERATOR_H
#define _ITERATOR_H

class Shape;
class Iterator {
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual Shape* CurrentItem() const = 0;

protected:
	Iterator();
};
#endif //_ITERATOR_H
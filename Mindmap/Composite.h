//Composite.h

#ifndef _COMPOSITE_H
#define _COMPOSITE_H
#include "Array.h"
#include "Shape.h"

typedef signed long int Long;

class Shape;
class Composite : public Shape {
public:
	Composite(Long capacity = 256, Branch* branch = NULL);
	Composite(const Composite& source);
	virtual ~Composite() = 0;

	Long Add(Shape *shape);
	Long Correct(Long index, Shape *shape);
	void Replace(Shape *before, Shape *after);
	Long Find(Shape *shape);
	Shape* GetAt(Long index);
	Composite& operator=(const Composite& source);

	Long GetCapacity() const;
	Long GetLength() const;

protected:
	Array<Shape*> shapes;
	Long capacity;
	Long length;
};

inline Long Composite::GetCapacity() const
{
	return this->capacity;
}

inline Long Composite::GetLength() const
{
	return this->length;
}

int CompareShapes(void *one, void *other);

#endif //_COMPOSITE_H

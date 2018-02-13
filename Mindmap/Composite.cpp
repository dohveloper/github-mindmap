//Composite.cpp

#include "Composite.h"

Composite::Composite(Long capacity, Branch* branch)
	:shapes(capacity) {
	this->capacity = capacity;
	this->length = 0;
	this->ownerBranch = branch;
}

Composite::Composite(const Composite& source)
	: shapes(source.shapes) {
	this->capacity = source.capacity;
	this->length = source.length;
	this->ownerBranch = source.ownerBranch;
}

Composite::~Composite()
{
}

Long Composite::Add(Shape *shape)
{
	Long index;

	if (this->length < this->capacity)
	{
		index = this->shapes.Store(this->length, shape);
	}
	else
	{
		index = this->shapes.AppendFromRear(shape);
		this->capacity++;
	}
	this->length++;
	return index;
}

Long Composite::Correct(Long index, Shape *shape)
{
	index = this->shapes.Modify(index, shape);
	return index;
}

Long Composite::Find(Shape * shape)
{
	Long index;
	index = this->shapes.LinearSearchUnique(&shape, CompareShapes);
	return index;
}

Shape* Composite::GetAt(Long index)
{
	Shape *shape;

	shape = this->shapes.GetAt(index);

	return shape;
}

Composite& Composite::operator=(const Composite& source)
{
	this->shapes = source.shapes;
	this->capacity = source.capacity;
	this->length = source.length;

	return *this;
}

int CompareShapes(void *one, void *other) {
	int ret = -1;
	if (*((Shape**)one) == *((Shape**)other)) {
		ret = 0;
	}
	return ret;
}
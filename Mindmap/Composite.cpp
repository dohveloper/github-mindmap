//Composite.cpp

#include "Composite.h"
#include "Selection.h"

Composite::Composite(Long capacity, Branch* branch)
	: shapes(capacity) {
	this->capacity = capacity;
	this->length = 0;
	this->ownerBranch = branch;
}

Composite::Composite(const Composite& source)
	: shapes(source.shapes) {
	this->capacity = source.capacity;
	this->length = source.length;
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

Long Composite::Remove(Long index)
{
	index = this->shapes.Delete(index);
	this->capacity--;
	this->length--;

	return index;
}

void Composite::Clear()
{
	Branch* branch;
	Long i = 0;

	while (i < this->length) {
		this->shapes.Delete(i);
		i++;
	}
	this->length = 0;
}

Long Composite::Correct(Long index, Shape *shape)
{
	index = this->shapes.Modify(index, shape);
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
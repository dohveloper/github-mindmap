//Composite.cpp

#include "Composite.h"
#include "Selection.h"

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

Long Composite::Remove(Selection *selection, Branch *branch)
{
	Long i = 0;
	Long index = -1;
	Branch *temp;

	
	//selection->GetAt(i)->shapes.LinearSearchUnique();

	while (i < selection->GetLength()) 
	{
		temp = selection->GetAt(i);
		index = temp->GetOwnerBranch()->shapes.LinearSearchUnique(&temp, CompareBranches);
		if (index != -1)
		{
			branch->shapes.Delete(i);
		}
		i++;
	}

	return index;
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
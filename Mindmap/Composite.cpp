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
	Long index = -1;
	Long i = 0;
	Long j = 0;
	Branch *temp;
	Branch *temp2;

	branch->shapes.Delete(2);

	/*
	temp = selection->GetAt(0);
	temp2 = temp->GetOwnerBranch();
	while (temp->GetLength())
	{
		*temp3[j] = *temp->shapes[i];
		i++;
		j++;
	}
	temp2->shapes[2] = *temp3;


	while (i < selection->GetLength()) 
	{

	temp = selection->GetAt(i);
	temp2 = temp->GetOwnerBranch();


		

		branch->shapes.DeleteFromRear();

		temp = selection->GetAt(i);

		if (this->temp != NULL)
		{
		delete [] this->temp;
		this->temp = NULL;
		}


		temp = selection->GetAt(i);
		temp->shapes.Delete(0);
		temp->shapes.Delete(1);

		temp2 = temp->GetOwnerBranch();
	index = temp2->shapes.LinearSearchUnique(&temp, CompareBranches);
	index = temp2->shapes.Delete(i);	
		
		if (index != -1)
		{
			
		}
		i++;
	}
	*/

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
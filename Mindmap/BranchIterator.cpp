#include "BranchIterator.h"
#include "Shape.h"
#include "Branch.h"

BranchIterator::BranchIterator(Branch* branch) 
:Iterator(){
	this->branch = branch;
	current = 0;
}

void BranchIterator::First()
{
	this->current = 0;
}

void BranchIterator::Next()
{
	this->current++;
}

bool BranchIterator::IsDone() const
{
	return this->current >= this->branch->GetLength();
}

Shape * BranchIterator::CurrentItem() const
{
	Shape* currentItem;
	currentItem=this->branch->GetAt(this->current);
	
	return currentItem;
}

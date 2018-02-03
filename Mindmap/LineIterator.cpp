#include "LineIterator.h"
#include "Branch.h"
#include "Line.h"
#include "Topic.h"

LineIterator::LineIterator(Branch* branch) {
	this->branch = branch;
	current = 0;
}

void LineIterator::First()
{
	Long length;
	Long i = 0;
	Shape *current;

	length = branch->GetLength();

	while (i < length) {
		current = this->branch->GetAt(i);
		if (typeid(*current) != typeid(Topic)) {
			this->current = current;
		}
		if (typeid(*current) != typeid(Branch)) {
			
		i++;
	}

}

void LineIterator::Next()
{
}

bool LineIterator::IsDone() const
{
	return false;
}

Shape * LineIterator::CurrentItem() const
{
	return this->current;
}

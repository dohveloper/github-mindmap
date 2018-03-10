//Branch.cpp
#include "Shape.h"
#include "Branch.h"
#include "Composite.h"
#include "Topic.h"
#include "Line.h"
#include "BranchCopyTraverser.h"

Branch::Branch(Long capacity, Branch* branch)
	:Composite(capacity, branch)
{
}
Branch::Branch(const Branch& source)
	: Composite(source) {
}
Branch::~Branch()
{
}

Long Branch::Add(Shape * shape)
{
	Long index;
	index = Composite::Add(shape);
	shape->SetOwnerBranch(this);
	return index;
}

Long Branch::Correct(Long index, Shape * shape)
{
	Long ret;
	ret = Composite::Correct(index, shape);
	shape->SetOwnerBranch(this);
	return index;
}

void Branch::Replace(Shape * before, Shape * after)
{
	Long index;
	Composite::Replace(before, after);
	after->SetOwnerBranch(this);
}

Topic* Branch::GetTopic()
{
	Shape *topic;

	topic = this->shapes.GetAt(0);
	if (typeid(*topic) != typeid(Topic)) {
		topic = this->shapes.GetAt(1);
	}

	return (Topic*)topic;
}

Line* Branch::GetLine()
{
	Shape *shape;
	Line *line = NULL;
	Long length;
	Long i = 0;

	length = this->shapes.GetLength();

	while (i < length)
	{
		shape = this->shapes.GetAt(i);

		if (typeid(*shape) == typeid(Line))
		{
			line = (Line*)shape;
			i = length;
		}
		i++;
	}
	return line;
}

Mark* Branch::GetMark()
{
	Shape *mark;
	Long length;
	Long i = 0;

	length = this->shapes.GetLength();

	while (i < length)
	{
		mark = this->shapes.GetAt(i);

		if (typeid(*mark) == typeid(Mark))
		{
			i = length;
		}
		i++;
	}
	/*
	mark = this->shapes.GetAt(1);
	if (typeid(*mark) == typeid(Mark))
	{
		mark = this->shapes.GetAt(2);
	}
	*/
	return (Mark*)mark;
}

void Branch::Accept(ShapeVisitor& visitor) {
	visitor.VisitBranch(this);
}

Branch * Branch::Clone()
{
	Branch *clone;
	BranchCopyTraverser traverser(this);
	traverser.Traverse();
	clone = traverser.GetClone();
	return clone;
}

Branch& Branch::operator=(const Branch& source)
{
	this->ownerBranch = source.ownerBranch;
	this->isShown = source.isShown;

	this->shapes = source.shapes;
	this->capacity = source.capacity;
	this->length = source.length;
	return *this;
}

/*
#include <iostream>
#include "Topic.h"
#include "Line.h"
#include "Mark.h"
#include "BranchArray.h"
int main(int argc, char *argv[]) {
	Long i = 0;
	Long j = 0;

	//Branch Clone 테스트
	Branch ownerBranch;
	Branch branch;
	Topic topic(2, 2, 2, 2, "topic");
	Line line(3, 3, 3, 3, "line ");
	Mark mark(4, 4, 4, 4, "mark ");

	BranchArray branches;
	Branch *currentBranch;
	Shape *current;

	Branch *clone;

	ownerBranch.SetContent("ownerBranch");

	branch.Add(&topic);
	branch.Add(&line);
	branch.Add(&mark);

	branch.SetCapacity(100);
	branch.SetX(1);
	branch.SetY(1);
	branch.SetWidth(1);
	branch.SetHeight(1);
	branch.SetContent("branch");
	branch.SetIsShown(false);
	branch.SetOwnerBranch(&ownerBranch);

	//초기값

	branches.Add(&branch);
	while (i < branches.GetLength()) {
		currentBranch = branches.GetAt(i);
		cout << currentBranch->GetContent() << "  :  " << endl << " x: " << currentBranch->GetX() << " y: " << currentBranch->GetY() << " width: " << currentBranch->GetWidth() << " height: " << currentBranch->GetHeight() << " isShown: " << currentBranch->GetIsShown() << "    CONTENT:   " << currentBranch->GetContent() << "   OWNERBRANCH:   " << currentBranch->GetOwnerBranch()->GetContent() << endl;
		while (j < currentBranch->GetLength()) {
			current = currentBranch->GetAt(j);
			cout << "   L " << current->GetContent() << "  :  " << " x: " << current->GetX() << " y: " << current->GetY() << " width: " << current->GetWidth() << " height: " << current->GetHeight() << " isShown: " << current->GetIsShown() << "    CONTENT:   " << current->GetContent() << "   OWNERBRANCH:   " << current->GetOwnerBranch()->GetContent() << endl;
			if (typeid(*current) == typeid(Branch)) {
				branches.Add((Branch*)current);
			}
			j++;
		}
		cout << endl;
		j = 0;
		i++;
	}

	branches.Clear();
	i = 0;
	j = 0;

	//복사

	clone = branch.Clone();
	branches.Add(clone);
	while (i < branches.GetLength()) {
		currentBranch = branches.GetAt(i);
		cout << currentBranch->GetContent() << "  :  " << endl << " x: " << currentBranch->GetX() << " y: " << currentBranch->GetY() << " width: " << currentBranch->GetWidth() << " height: " << currentBranch->GetHeight() << " isShown: " << currentBranch->GetIsShown() << "    CONTENT:   " << currentBranch->GetContent() << "   OWNERBRANCH:   " << currentBranch->GetOwnerBranch()->GetContent() << endl;
		while (j < currentBranch->GetLength()) {
			current = currentBranch->GetAt(j);
			cout << "   L " << current->GetContent() << "  :  " << " x: " << current->GetX() << " y: " << current->GetY() << " width: " << current->GetWidth() << " height: " << current->GetHeight() << " isShown: " << current->GetIsShown() << "    CONTENT:   " << current->GetContent() << "   OWNERBRANCH:   " << current->GetOwnerBranch()->GetContent() << endl;
			if (typeid(*current) == typeid(Branch)) {
				branches.Add((Branch*)current);
			}
			j++;
		}
		cout << endl;
		j = 0;
		i++;
	}

	//값수정테스트
	branches.Clear();
	i = 0;
	j = 0;

	clone = branch.Clone();
	branches.Add(clone);
	while (i < branches.GetLength()) {
		currentBranch = branches.GetAt(i);
		//값 수정 테스트
		currentBranch->SetCapacity(10000);
		currentBranch->SetX(10000);
		currentBranch->SetY(10000);
		currentBranch->SetWidth(10000);
		currentBranch->SetHeight(10000);
		currentBranch->SetContent("copy");
		currentBranch->SetIsShown(false);
		currentBranch->SetOwnerBranch(&ownerBranch);

		cout << currentBranch->GetContent() << "  :  " << endl << " x: " << currentBranch->GetX() << " y: " << currentBranch->GetY() << " width: " << currentBranch->GetWidth() << " height: " << currentBranch->GetHeight() << " isShown: " << currentBranch->GetIsShown() << "    CONTENT:   " << currentBranch->GetContent() << "   OWNERBRANCH:   " << currentBranch->GetOwnerBranch()->GetContent() << endl;
		while (j < currentBranch->GetLength()) {
			current = currentBranch->GetAt(j);

			//값 수정 테스트
			current->SetX(10000);
			current->SetY(10000);
			current->SetWidth(10000);
			current->SetHeight(10000);
			current->SetContent("copy");
			current->SetIsShown(false);
			current->SetOwnerBranch(&ownerBranch);

			cout << "   L " << current->GetContent() << "  :  " << " x: " << current->GetX() << " y: " << current->GetY() << " width: " << current->GetWidth() << " height: " << current->GetHeight() << " isShown: " << current->GetIsShown() << "    CONTENT:   " << current->GetContent() << "   OWNERBRANCH:   " << current->GetOwnerBranch()->GetContent() << endl;
			if (typeid(*current) == typeid(Branch)) {
				branches.Add((Branch*)current);
			}
			j++;
		}
		cout << endl;
		j = 0;
		i++;
	}

	//원래값 다시 확인
	branches.Clear();
	i = 0;
	j = 0;

	branches.Add(&branch);
	while (i < branches.GetLength()) {
		currentBranch = branches.GetAt(i);
		cout << currentBranch->GetContent() << "  :  " << endl << " x: " << currentBranch->GetX() << " y: " << currentBranch->GetY() << " width: " << currentBranch->GetWidth() << " height: " << currentBranch->GetHeight() << " isShown: " << currentBranch->GetIsShown() << "    CONTENT:   " << currentBranch->GetContent() << "   OWNERBRANCH:   " << currentBranch->GetOwnerBranch()->GetContent() << endl;
		while (j < currentBranch->GetLength()) {
			current = currentBranch->GetAt(j);
			cout << "   L " << current->GetContent() << "  :  " << " x: " << current->GetX() << " y: " << current->GetY() << " width: " << current->GetWidth() << " height: " << current->GetHeight() << " isShown: " << current->GetIsShown() << "    CONTENT:   " << current->GetContent() << "   OWNERBRANCH:   " << current->GetOwnerBranch()->GetContent() << endl;
			if (typeid(*current) == typeid(Branch)) {
				branches.Add((Branch*)current);
			}
			j++;
		}
		cout << endl;
		j = 0;
		i++;
	}

	//Replace Test
	cout << endl << endl << "REPLACE TEST" << endl << endl;
	branch.Replace(&mark, clone);

	branches.Clear();
	i = 0;
	j = 0;
	branches.Add(&branch);
	while (i < branches.GetLength()) {
		currentBranch = branches.GetAt(i);
		cout << currentBranch->GetContent() << "  :  " << endl << " x: " << currentBranch->GetX() << " y: " << currentBranch->GetY() << " width: " << currentBranch->GetWidth() << " height: " << currentBranch->GetHeight() << " isShown: " << currentBranch->GetIsShown() << "    CONTENT:   " << currentBranch->GetContent() << "   OWNERBRANCH:   " << currentBranch->GetOwnerBranch()->GetContent() << endl;
		while (j < currentBranch->GetLength()) {
			current = currentBranch->GetAt(j);
			cout << "   L " << current->GetContent() << "  :  " << " x: " << current->GetX() << " y: " << current->GetY() << " width: " << current->GetWidth() << " height: " << current->GetHeight() << " isShown: " << current->GetIsShown() << "    CONTENT:   " << current->GetContent() << "   OWNERBRANCH:   " << current->GetOwnerBranch()->GetContent() << endl;
			if (typeid(*current) == typeid(Branch)) {
				branches.Add((Branch*)current);
			}
			j++;
		}
		cout << endl;
		j = 0;
		i++;
	}
}
*/
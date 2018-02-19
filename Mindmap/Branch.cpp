//Branch.cpp

#include "Branch.h"
#include "Composite.h"
#include "Topic.h"
#include "Line.h"
#include "Selection.h"
Branch::Branch(Long capacity, Branch* branch)
	:Composite(capacity, branch)
{
}
Branch::Branch(const Branch& source)
	: Composite(source){
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

void Branch::Sort()
{
	Long length;
	Long i = 0;
	Shape *currentItem;
	Long branchPosition = 0;
	Long centerX;
	Branch *temp;
	Long x;
	Branch leftBranchs;
	Branch rightBranchs;

	length = this->shapes.GetLength();
	
	while (i < length)
	{
		currentItem = this->shapes.GetAt(i);
		if (typeid(*currentItem) != typeid(Branch))
		{
			branchPosition++;
		}
		else
		{
			i = length;
		}
		i++;
	}

	i = branchPosition;
	while (i < length)
	{
		centerX = this->GetTopic()->GetX() + this->GetTopic()->GetWidth() / 2;
		temp = (Branch*)this->shapes.GetAt(i);

		x = temp->GetTopic()->GetX();

		if (x < centerX)
		{
			leftBranchs.Add(temp);
		}
		else
		{
			rightBranchs.Add(temp);
		}
		i++;
	}

	i = 0;
	while (i < leftBranchs.GetLength())
	{
		this->shapes.Modify(branchPosition, leftBranchs.GetAt(i));
		i++;
		branchPosition++;
	}

	i = 0;
	while (i < rightBranchs.GetLength())
	{
		this->shapes.Modify(branchPosition, rightBranchs.GetAt(i));
		i++;
		branchPosition++;
	}
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

Mark* Branch::GetMark()
{
	Shape *mark;
	Long length;
	Long i = 0;

	length=this->shapes.GetLength();

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
	return new Branch(*this);
}

Branch& Branch::operator=(const Branch& source)
{
	this->shapes = source.shapes;
	this->capacity = source.capacity;
	this->length = source.length;
	return *this;
}

#include <iostream>
#include "Topic.h"
#include "Line.h"
int main(int argc, char *argv[])
{
	Long i = 0;
	Shape *currentItem;
	Long lenght;

	Branch *branch = new Branch;
	branch->Add(new Topic(287, 150, 200, 200, "메인토픽"));
	branch->Add(new Mark(573, 200));

	cout << branch->GetAt(0)->GetX() << endl;

	Branch *branch2 = new Branch;
	branch2->Add(new Topic(500, 500, 100, 100, "토픽"));
	branch2->Add(new Line(500, 500, 100, 100, "선"));

	Branch *branch3 = new Branch;
	branch3->Add(new Topic(100, 100, 100, 100, "토픽"));
	branch3->Add(new Line(100, 500, 100, 100, "선"));

	Branch *branch4 = new Branch;
	branch4->Add(new Topic(400, 400, 100, 100, "토픽"));
	branch4->Add(new Line(400, 400, 100, 100, "선"));

	Branch *branch5 = new Branch;
	branch5->Add(new Topic(150, 150, 100, 100, "토픽"));
	branch5->Add(new Line(150, 100, 100, 100, "선"));

	branch->Add(branch2);
	branch->Add(branch3);
	branch->Add(branch4);
	branch->Add(branch5);

	lenght = branch->GetLength();
	cout << lenght << endl;

	while (i < lenght)
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			cout << currentItem->GetAt(0)->GetX() << endl;
		}
		else
		{
			cout << currentItem->GetX() << endl;
		}
		i++;
	}

	i = 0;
	branch->Sort();
	cout << "" << endl;
	while (i < lenght)
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			cout << currentItem->GetAt(0)->GetX() << endl;
		}
		else
		{
			cout << currentItem->GetX() << endl;
		}
		i++;
	}

	return 0;
}
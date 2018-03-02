//Branch.cpp

#include "Branch.h"
#include "Composite.h"
#include "Topic.h"
#include "Line.h"
#include "BranchArray.h"
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

void Branch::Sort()
{
	Long length;
	Long i = 0;
	Shape *currentItem;
	Long branchPosition = 0;
	Long centerX;
	Branch *branch;
	Long x;
	BranchArray leftBranches;
	BranchArray rightBranches;

	length = this->shapes.GetLength();

	currentItem = this->shapes.GetAt(i);
	while (typeid(*currentItem) != typeid(Branch))
	{
		branchPosition++;
		i++;
		currentItem = this->shapes.GetAt(i);
	}

	i = branchPosition;
	while (i < length)
	{
		centerX = this->GetTopic()->GetX() + this->GetTopic()->GetWidth() / 2;
		branch = (Branch*)this->shapes.GetAt(i);

		x = branch->GetTopic()->GetX();

		if (x < centerX)
		{
			leftBranches.Add(branch);
		}
		else
		{
			rightBranches.Add(branch);
		}
		i++;
	}
	leftBranches.branches.InsertionSort(CompareYs);
	rightBranches.branches.InsertionSort(CompareYs);

	i = 0;
	while (i < leftBranches.GetLength())
	{
		this->shapes.Modify(branchPosition, leftBranches.GetAt(i));
		i++;
		branchPosition++;
	}

	i = 0;
	while (i < rightBranches.GetLength())
	{
		this->shapes.Modify(branchPosition, rightBranches.GetAt(i));
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

Line* Branch::GetLine()
{
	Shape *line = NULL;
	Long length;
	Long i = 0;

	length = this->shapes.GetLength();

	line = this->shapes.GetAt(i);

	while (i < length)
	{
		line = this->shapes.GetAt(i);

		if (typeid(*line) == typeid(Line))
		{
			i = length;
		}
		i++;
	}
	return (Line*)line;
}

Mark* Branch::GetMark()
{
	Shape *mark = NULL;
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
	while (typeid(*mark) == typeid(Mark))
	{
		i++;
		mark = this->shapes.GetAt(i);
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


int CompareYs(void *one, void *other)
{
	int ret = 0;

	if ((*(Branch**)one)->GetTopic()->GetY() > (*(Branch**)other)->GetTopic()->GetY())
	{
		ret = 1;
	}
	else if ((*(Branch**)one)->GetTopic()->GetY() == (*(Branch**)other)->GetTopic()->GetY())
	{
		ret = 0;
	}
	else if ((*(Branch**)one)->GetTopic()->GetY() < (*(Branch**)other)->GetTopic()->GetY())
	{
		ret = -1;
	}
	return ret;
}

/*
#include <iostream>
#include "Topic.h"
#include "Line.h"
#include "ArrangeVisitor.h"
int main(int argc, char *argv[])
{
	Long i = 0;
	Shape *currentItem;
	Long lenght;

	Branch *branch = new Branch;
	branch->Add(new Topic(550, 200, 200, 200, "메인토픽"));
	branch->Add(new Mark(573, 200));

	cout << branch->GetAt(0)->GetX() << endl;

	Branch *branch2 = new Branch;
	branch2->Add(new Topic(300, 400, 200, 200, "토픽"));
	branch2->Add(new Line(400, 400, 100, 100, "선"));

	Branch *branch3 = new Branch;
	branch3->Add(new Topic(100, 200, 200, 200, "토픽"));
	branch3->Add(new Line(200, 200, 200, 200, "선"));

	Branch *branch4 = new Branch;
	branch4->Add(new Topic(200, 500, 200, 200, "토픽"));
	branch4->Add(new Line(500, 500, 100, 100, "선"));

	Branch *branch5 = new Branch;
	branch5->Add(new Topic(150, 150, 200, 200, "토픽"));
	branch5->Add(new Line(150, 100, 100, 100, "선"));

	Branch *branch6 = new Branch;
	branch6->Add(new Topic(600, 600, 200, 200, "토픽"));
	branch6->Add(new Line(200, 200, 200, 200, "선"));

	Branch *branch7 = new Branch;
	branch7->Add(new Topic(700, 700, 200, 200, "토픽"));
	branch7->Add(new Line(200, 200, 200, 200, "선"));

	Branch *branch8 = new Branch;
	branch8->Add(new Topic(300, 300, 200, 200, "토픽"));
	branch8->Add(new Line(200, 200, 200, 200, "선"));

	Branch *branch9 = new Branch;
	branch9->Add(new Topic(400, 400, 200, 200, "토픽"));
	branch9->Add(new Line(200, 200, 200, 200, "선"));


	branch->Add(branch2);
	branch->Add(branch3);
	branch->Add(branch4);
	branch->Add(branch5);
	branch->Add(branch6);
	branch->Add(branch7);
	branch->Add(branch8);
	branch->Add(branch9);

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
			cout << currentItem->GetAt(0)->GetX() << "_" << currentItem->GetAt(0)->GetY() << endl;
		}

		else
		{
			cout << currentItem->GetX() << "__" << currentItem->GetY() << endl;
		}
		i++;
	}


	ArrangeVisitor arrangeVisitor;
	arrangeVisitor.VisitBranch(branch);


	i = 0;
	cout << "절취선" << endl;
	while (i < lenght)
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			cout << currentItem->GetAt(0)->GetX() << "_" << currentItem->GetAt(0)->GetY() <<  "_" << currentItem->GetHeight() << endl;
		}

		else
		{
			cout << currentItem->GetX() << "__" << currentItem->GetY() << endl;
		}
		i++;
	}



	return 0;
}
*/

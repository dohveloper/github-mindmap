//BranchArrange.cpp

#include "BranchArrange.h"
#include "Selection.h"
#include "Branch.h"
#include "Topic.h"

BranchArrange::BranchArrange()
{
}

BranchArrange::~BranchArrange()
{
}

void BranchArrange::Arrange(Branch *branch)
{
	Long length;
	Long i = 0;
	Shape *currentItem;
	Long x;
	Long center;
	Selection leftSpot;
	Selection rightSpot;
	Long count = 0;
	Long j = 0;
	Long leftSpotLength;
	Long rightSpotLength;

	length = branch->GetLength();

	while (i < length)
	{
		center = branch->GetTopic()->GetX() + branch->GetTopic()->GetWidth() / 2;
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			x = currentItem->GetX();
			
			if (x < center)
			{
				leftSpot.Add((Branch*)currentItem);
			}
			else
			{
				rightSpot.Add((Branch*)currentItem);
			}
		}
		else
		{
			count++;
		}
		i++;
	}
	


	Branch *allSpot = new Branch;

	i = 0;
	while (i < length)
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) != typeid(Branch))
		{
			allSpot->Add(currentItem);
		}
		i++;
	}

	leftSpotLength = leftSpot.GetLength();
	rightSpotLength = rightSpot.GetLength();

	while (j < leftSpotLength)
	{
		allSpot->Add(leftSpot.GetAt(j));
		j++;
	}

	j = 0;

	while (j < rightSpotLength)
	{
		allSpot->Add(rightSpot.GetAt(j));
		j++;
	}

	branch = allSpot;
	

	/*
	i = 0;
	leftSpotLength = leftSpot.GetLength();
	rightSpotLength = rightSpot.GetLength();

	while (i < length && j < leftSpotLength)
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			branch->Correct(i, leftSpot.GetAt(j));
			j++;
		}
		i++;
	}

	j = 0;
	while (i < length && j < rightSpotLength)
	{
		currentItem = branch->GetAt(i);
		if (typeid(*currentItem) == typeid(Branch))
		{
			branch->Correct(i, rightSpot.GetAt(j));
			j++;
		}
		i++;
	}
	*/




	/*
	i = count;
	leftSpotLength = leftSpot.GetLength();

	while (j < leftSpotLength)
	{
		branch->Correct(i, leftSpot.GetAt(j));
		i++;
		j++;
	}

	j = 0;
	rightSpotLength = rightSpot.GetLength();

	while (j < rightSpotLength)
	{
		branch->Correct(i, rightSpot.GetAt(j));
		i++;
		j++;
	}
	*/

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
	branch->Add(new Topic(387, 150, 200, 200, "메인토픽"));
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
	BranchArrange branchArrange;
	branchArrange.Arrange(branch);
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



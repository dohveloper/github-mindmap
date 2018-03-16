#include "UpdateTraverser.h"
#include "Branch.h"
#include "Topic.h"
#include "Line.h"
#include "Mark.h"

UpdateTraverser::UpdateTraverser(Branch *before, Branch *after)
	:BranchTraverser(before)
{
	Long capacity;
	Long length;
	Long x;
	Long y;
	Long width;
	Long height;
	string content;
	bool isShown;

	this->after = after;

	//�ٲ� branch�� ������ �����´�.
	capacity = this->after->GetCapacity();
	length = this->after->GetLength();
	x = this->after->GetX();
	y = this->after->GetY();
	width = this->after->GetWidth();
	height = this->after->GetHeight();
	content = this->after->GetContent();
	isShown = this->after->GetIsShown();

	//�ٲ۴�.
	before->SetCapacity(capacity);
	before->SetLength(length);
	before->SetX(x);
	before->SetY(y);
	before->SetWidth(width);
	before->SetHeight(height);
	before->SetContent(content);
	before->SetIsShown(isShown);
}

inline bool UpdateTraverser::ProcessItem(Shape * shape)
{
	bool ret = true;

	Branch *after;
	Long current;
	Long x;
	Long y;
	Long width;
	Long height;
	string content;
	bool isShown;

	current = this->iterator.GetCurrent();
	after = (Branch*)this->after->GetAt(current);

	//�ٲ� branch�� ������ �����´�.
	x = after->GetX();
	y = after->GetY();
	width = after->GetWidth();
	height = after->GetHeight();
	content = after->GetContent();
	isShown = after->GetIsShown();

	//������Ʈ�Ѵ�.

	shape->SetX(x);
	shape->SetY(y);
	shape->SetWidth(width);
	shape->SetHeight(height);
	shape->SetContent(content);
	shape->SetIsShown(isShown);

	if (typeid(*shape) == typeid(Branch)) {
		UpdateTraverser traverser((Branch*)shape, after);
		traverser.Traverse();
	}
	return ret;
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

	//Branch Clone �׽�Ʈ
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

	//�ʱⰪ
	cout << "<�귣ġ A > " << endl;

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

	//�������׽�Ʈ
	cout << "<�귣ġB (������)> " << endl;

	branches.Clear();
	i = 0;
	j = 0;
	Long value = 1000;
	clone = branch.Clone();
	branches.Add(clone);
	while (i < branches.GetLength()) {
		currentBranch = branches.GetAt(i);
		//�� ���� �׽�Ʈ
		currentBranch->SetCapacity(10000);
		currentBranch->SetX(10000);
		currentBranch->SetY(10000);
		currentBranch->SetWidth(10000);
		currentBranch->SetHeight(10000);
		currentBranch->SetContent("update");
		currentBranch->SetIsShown(false);
		currentBranch->SetOwnerBranch(&ownerBranch);

		cout << currentBranch->GetContent() << "  :  " << endl << " x: " << currentBranch->GetX() << " y: " << currentBranch->GetY() << " width: " << currentBranch->GetWidth() << " height: " << currentBranch->GetHeight() << " isShown: " << currentBranch->GetIsShown() << "    CONTENT:   " << currentBranch->GetContent() << "   OWNERBRANCH:   " << currentBranch->GetOwnerBranch()->GetContent() << endl;
		while (j < currentBranch->GetLength()) {
			current = currentBranch->GetAt(j);

			//�� ���� �׽�Ʈ
			current->SetX(value);
			current->SetY(value);
			current->SetWidth(value);
			current->SetHeight(value);
			//current->SetContent("update");
			current->SetIsShown(false);
			//current->SetOwnerBranch(&ownerBranch);
			value += 1000;
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

	///// UpdateTraverser �׽�Ʈ

	cout << "�����������������귣ġA �� �귣ġB�� ������Ʈ������������������ " << endl << endl;

	//�ʱⰪ
	cout << "<�귣ġ A (�ʱⰪ) > " << endl;

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

	//�������� Ŭ������ Update
	UpdateTraverser traverser(&branch, clone);
	traverser.Traverse();

	//��� Ȯ��
	cout << "<�귣ġ A (�귣ġB�� ������Ʈ�� ��)> " << endl;
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

	return 0;
}
*/
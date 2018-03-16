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

	//郊蝦 branch税 葵級聖 亜閃紳陥.
	capacity = this->after->GetCapacity();
	length = this->after->GetLength();
	x = this->after->GetX();
	y = this->after->GetY();
	width = this->after->GetWidth();
	height = this->after->GetHeight();
	content = this->after->GetContent();
	isShown = this->after->GetIsShown();

	//郊菓陥.
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

	//郊蝦 branch税 葵級聖 亜閃紳陥.
	x = after->GetX();
	y = after->GetY();
	width = after->GetWidth();
	height = after->GetHeight();
	content = after->GetContent();
	isShown = after->GetIsShown();

	//穣汽戚闘廃陥.

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

	//Branch Clone 砺什闘
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

	//段奄葵
	cout << "<崎沓帖 A > " << endl;

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

	//葵呪舛砺什闘
	cout << "<崎沓帖B (葵呪舛)> " << endl;

	branches.Clear();
	i = 0;
	j = 0;
	Long value = 1000;
	clone = branch.Clone();
	branches.Add(clone);
	while (i < branches.GetLength()) {
		currentBranch = branches.GetAt(i);
		//葵 呪舛 砺什闘
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

			//葵 呪舛 砺什闘
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

	///// UpdateTraverser 砺什闘

	cout << "けけけけけけけけ崎沓帖A 研 崎沓帖B稽 穣汽戚闘けけけけけけけけけ " << endl << endl;

	//段奄葵
	cout << "<崎沓帖 A (段奄葵) > " << endl;

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

	//据掘葵聖 適経生稽 Update
	UpdateTraverser traverser(&branch, clone);
	traverser.Traverse();

	//衣引 溌昔
	cout << "<崎沓帖 A (崎沓帖B稽 穣汽戚闘廃 葵)> " << endl;
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
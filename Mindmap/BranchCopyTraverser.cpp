#include "BranchCopyTraverser.h"
#include "Branch.h"
#include "Topic.h"
#include "Line.h"
#include "Mark.h"

BranchCopyTraverser::BranchCopyTraverser(Branch *branch)
	:BranchTraverser(branch)
{
	Long x;
	Long y;
	Long width;
	Long height;
	string content;
	bool isShown;

	//���� branch�� ������ �����´�.
	x = branch->GetX();
	y = branch->GetY();
	width = branch->GetWidth();
	height = branch->GetHeight();
	content = branch->GetContent();
	isShown = branch->GetIsShown();

	//�� �귣ġ�� �Ҵ��Ѵ�.
	this->clone = new Branch();

	//�� �귣ġ�� �����°����� �����Ѵ�.
	clone->SetX(x);
	clone->SetY(y);
	clone->SetWidth(width);
	clone->SetHeight(height);
	clone->SetContent(content);
	clone->SetIsShown(isShown);
}

inline bool BranchCopyTraverser::ProcessItem(Shape * shape)
{
	bool ret = true;
	Mark *mark;
	Topic *topic;
	Line *line;
	Branch *branch;

	if (typeid(*shape) == typeid(Mark)) {
		mark = new Mark(*(Mark*)shape);
		clone->Add(mark);
	}
	if (typeid(*shape) == typeid(Topic)) {
		topic = new Topic(*(Topic*)shape);
		clone->Add(topic);
	}
	if (typeid(*shape) == typeid(Line)) {
		line = new Line(*(Line*)shape);
		clone->Add(line);
	}
	if (typeid(*shape) == typeid(Branch)) {
		BranchCopyTraverser traverser((Branch*)shape);
		traverser.Traverse();
		branch = traverser.Getclone();
		clone->Add(branch);
	}
	return ret;
}

#include <iostream>
#include <string>
#include "Line.h"
#include "Branch.h"
#include "BranchArray.h"
using namespace std;

int main(int argc, char argv[]) {
	Long i = 0;
	Long j = 0;
	Shape *current;
	Branch *currentBranch;
	////////////////////////////�귣ġ, ���� ����//////////////////////////////
	//0
	Branch branch; Line line(0, 0, 0, 0, "line"); Topic topic(0, 0, 0, 0, "topic"); Mark mark(0, 0, 0, 0, "mark");
	branch.Add(&line); branch.Add(&topic); branch.Add(&mark);
	branch.SetContent("branch");
	//1
	Branch branch1; Line line1(0, 0, 0, 0, "line1"); Topic topic1(0, 0, 0, 0, "topic1");  Mark mark1(0, 0, 0, 0, "mark1");
	branch1.Add(&line1); branch1.Add(&topic1); branch1.Add(&mark1);
	branch1.SetContent("branch1");
	//1_1
	Branch branch1_1; Line line1_1(0, 0, 0, 0, "line1_1"); Topic topic1_1(0, 0, 0, 0, "topic1_1"); Mark mark1_1(0, 0, 0, 0, "mark1_1");
	branch1_1.Add(&line1_1); branch1_1.Add(&topic1_1); branch1_1.Add(&mark1_1);
	branch1_1.SetContent("branch1_1");
	branch1_1.SetIsShown(false);
	//1_2
	Branch branch1_2;	Line line1_2(0, 0, 0, 0, "line1_2");	Topic topic1_2(0, 0, 0, 0, "topic1_2");	Mark mark1_2(0, 0, 0, 0, "mark1_2");
	branch1_2.Add(&line1_2); branch1_2.Add(&topic1_2); branch1_2.Add(&mark1_2);
	branch1_2.SetContent("branch1_2");

	//branch�� branch �ֱ�
	branch.Add(&branch1); branch1.Add(&branch1_1); branch1.Add(&branch1_2);
	///////////////////////////////////////////////////////////////////////////////

	//�ʱⰪ ����( branch ���� ���� �ڵ�)

	cout << "    �ʱⰪ" << endl;
	BranchArray branches;
	branches.Add(&branch);
	while (j < branches.GetLength()) {
		currentBranch = branches.GetAt(j);
		cout << currentBranch->GetContent() << "  :  ";
		while (i < currentBranch->GetLength()) {
			current = currentBranch->GetAt(i);
			cout << current->GetContent() << " ";
			if (typeid(*current) == typeid(Branch)) {
				branches.Add((Branch*)current);
			}
			i++;
		}
		cout << endl;
		i = 0;
		j++;
	}

	//����
	Branch *clone;
	BranchCopyTraverser traverser(&branch);
	traverser.Traverse();
	clone = traverser.GetClone();
	clone->SetContent("clone");

	//clone ����

	cout << "    �����Ȱ�" << endl;
	branches.Clear();
	j = 0;
	i = 0;
	branches.Add(clone);
	while (j < branches.GetLength()) {
		currentBranch = branches.GetAt(j);
		cout << currentBranch->GetContent() << "  :  ";
		while (i < currentBranch->GetLength()) {
			current = currentBranch->GetAt(i);
			//isShown�� Ʈ���� ���̵���
			if (current->GetOwnerBranch()->GetIsShown()) {
				cout << current->GetContent() << " ";
			}
			if (typeid(*current) == typeid(Branch)) {
				branches.Add((Branch*)current);
			}
			i++;
		}
		cout << endl;
		i = 0;
		j++;
	}
	cout << endl << endl << endl << endl;

	//clone ������ ������ �ȹٲ����� �׽�Ʈ

	//�����Ȱ� ����
	cout << "�����Ȱ� ����" << endl;
	branches.Clear();
	j = 0;
	i = 0;
	branches.Add(clone);
	while (j < branches.GetLength()) {
		currentBranch = branches.GetAt(j);
		while (i < currentBranch->GetLength()) {
			current = currentBranch->GetAt(i);
			current->SetContent("copied"); //�� ����
			if (typeid(*current) == typeid(Branch)) {
				branches.Add((Branch*)current);
			}
			i++;
		}
		cout << endl;
		i = 0;
		j++;
	}

	cout << "    �ʱⰪ" << endl;
	branches.Clear();
	j = 0;
	i = 0;
	branches.Add(&branch);
	while (j < branches.GetLength()) {
		currentBranch = branches.GetAt(j);
		cout << currentBranch->GetContent() << "  :  ";
		while (i < currentBranch->GetLength()) {
			current = currentBranch->GetAt(i);
			cout << current->GetContent() << " ";
			if (typeid(*current) == typeid(Branch)) {
				branches.Add((Branch*)current);
			}
			i++;
		}
		cout << endl;
		i = 0;
		j++;
	}
	cout << "    �����Ȱ�" << endl;
	branches.Clear();
	j = 0;
	i = 0;
	branches.Add(clone);
	while (j < branches.GetLength()) {
		currentBranch = branches.GetAt(j);
		cout << currentBranch->GetContent() << "  :  ";
		while (i < currentBranch->GetLength()) {
			current = currentBranch->GetAt(i);
			cout << current->GetContent() << " ";
			if (typeid(*current) == typeid(Branch)) {
				branches.Add((Branch*)current);
			}
			i++;
		}
		cout << endl;
		i = 0;
		j++;
	}

	//isShown ���� �׽�Ʈ
	Branch *copy_branch1_1;
	BranchCopyTraverser testIsShown(&branch1_1);
	testIsShown.Traverse();
	copy_branch1_1 = traverser.GetClone();

	if (branch1_1.GetIsShown())
	{
		cout << " branch1_1 : isShown = true " << endl;
	}
	else {
		cout << "branch1_1 : isShown = false " << endl;
	}

	if (copy_branch1_1->GetIsShown())
	{
		cout << "copy_branch1_1 : isShown = true " << endl;
	}
	else {
		cout << "copy_branch1_1 : isShown = false " << endl;
	}

	return 0;
}

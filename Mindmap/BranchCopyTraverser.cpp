#include "BranchCopyTraverser.h"
#include "Branch.h"
#include "Topic.h"
#include "Line.h"
#include "Mark.h"

BranchCopyTraverser::BranchCopyTraverser(Branch *branch)
	:BranchTraverser(branch)
{
	Long capacity;
	bool isShown;
	Long x;
	Long y;
	Long width;
	Long height;
	string content;
	Branch* ownerBranch;

	//���� branch�� ������ �����´�.
	capacity = branch->GetCapacity();
	x = branch->GetX();
	y = branch->GetY();
	width = branch->GetWidth();
	height = branch->GetHeight();
	content = branch->GetContent();
	isShown = branch->GetIsShown();
	ownerBranch = branch->GetOwnerBranch();

	//�� �귣ġ�� �Ҵ��Ѵ�.
	this->clone = new Branch(capacity);

	//�� �귣ġ�� �����°����� �����Ѵ�.

	this->clone->SetX(x);
	this->clone->SetY(y);
	this->clone->SetWidth(width);
	this->clone->SetHeight(height);
	this->clone->SetContent(content);
	this->clone->SetIsShown(isShown);
	this->clone->SetOwnerBranch(ownerBranch);
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
		this->clone->Add(mark);
	}
	if (typeid(*shape) == typeid(Topic)) {
		topic = new Topic(*(Topic*)shape);
		this->clone->Add(topic);
	}
	if (typeid(*shape) == typeid(Line)) {
		line = new Line(*(Line*)shape);
		this->clone->Add(line);
	}
	if (typeid(*shape) == typeid(Branch)) {
		BranchCopyTraverser traverser((Branch*)shape);
		traverser.Traverse();
		branch = traverser.GetClone();
		this->clone->Add(branch);
	}
	return ret;
}

/*
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
	branch.SetIsShown(false);
	//1
	Branch branch1; Line line1(0, 0, 0, 0, "line1"); Topic topic1(0, 0, 0, 0, "topic1");  Mark mark1(0, 0, 0, 0, "mark1");
	branch1.Add(&line1); branch1.Add(&topic1); branch1.Add(&mark1);
	branch1.SetContent("branch1");
	//1_1
	Branch branch1_1; Line line1_1(0, 0, 0, 0, "line1_1"); Topic topic1_1(0, 0, 0, 0, "topic1_1"); Mark mark1_1(0, 0, 0, 0, "mark1_1");
	branch1_1.Add(&line1_1); branch1_1.Add(&topic1_1); branch1_1.Add(&mark1_1);
	branch1_1.SetContent("branch1_1");

	//1_2
	Branch branch1_2;	Line line1_2(0, 0, 0, 0, "line1_2");	Topic topic1_2(0, 0, 0, 0, "topic1_2");	Mark mark1_2(0, 0, 0, 0, "mark1_2");
	branch1_2.Add(&line1_2); branch1_2.Add(&topic1_2); branch1_2.Add(&mark1_2);
	branch1_2.SetContent("branch1_2");

	//branch�� branch �ֱ�
	branch.Add(&branch1); branch1.Add(&branch1_1); branch1.Add(&branch1_2);
	///////////////////////////////////////////////////////////////////////////////

	//�ʱⰪ ���( branch ���� ��� �ڵ�)

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
	clone->SetContent("this->clone");

	//this->clone ���

	cout << "    ����Ȱ�" << endl;
	branches.Clear();
	j = 0;
	i = 0;
	branches.Add(clone);
	while (j < branches.GetLength()) {
		currentBranch = branches.GetAt(j);
		cout << currentBranch->GetContent() << "  :  ";
		while (i < currentBranch->GetLength()) {
			current = currentBranch->GetAt(i);
			//isShown�� Ʈ��� ���̵���
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

	//this->clone ������ ������ �ȹٲ���� �׽�Ʈ

	//����Ȱ� ����
	cout << "����Ȱ� ����" << endl;
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
	cout << "    ����Ȱ�" << endl;
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

	return 0;
}
*/
#include "Clipboard.h"
#include "Selection.h"

Clipboard::Clipboard(Selection *selection, Long capacity)
	:clipboard(capacity)
{
	this->selection = selection;
}

Clipboard::Clipboard(const Clipboard & source)
	: clipboard(source.clipboard)
{
	this->selection = source.selection;
}

Clipboard::~Clipboard()
{
}

void Clipboard::Copy()
{
	Long index;
	Long i = 0;
	Branch *current;
	Branch *clone;

	clipboard.Clear();
	this->selection->GetLength();
	while (i < this->selection->GetLength()) {
		current = selection->GetAt(i);
		clone = current->Clone();
		this->clipboard.Add(clone);
		i++;
	}
}

void Clipboard::Paste()
{
	Long i = 0;
	Branch *targetBranch;//�ٿ��־����� �귣ġ
	Branch *current; //������ �귣ġ

	targetBranch = this->selection->GetLastSelection();

	while (i < this->selection->GetLength()) {
		current = this->selection->GetAt(i);
		targetBranch->Add(current);
		i++;
	}
}

Clipboard& Clipboard::operator=(const Clipboard & source)
{
	this->clipboard = source.clipboard;
	this->selection = source.selection;
	return *this;
}

#include <iostream>
#include <string>
#include "Topic.h"
#include "Branch.h"
#include "BranchArray.h"
using namespace std;

int main(int argc, char argv[]) {
	Long i = 0;
	BranchArray branches;

	//�귣ġ, ���� ����
	Branch branch1;
	Branch branch2;
	Branch branch3;
	Topic topic1(1, 1, 1, 1, "topic1");
	Topic topic2(1, 1, 1, 1, "topic2");
	Topic topic3(1, 1, 1, 1, "topic3");
	branch1.SetContent("branch1");
	branch1.Add(&topic1);
	branch2.SetContent("branch2");
	branch2.Add(&topic2);
	branch3.SetContent("branch3");
	branch3.Add(&topic3);

	//Selection ����
	Selection selection;
	selection.Add(&branch2);
	selection.Add(&branch3);

	//Clipboard ����
	Clipboard clipboard(&selection);

	//����
	clipboard.Copy();

	//���� Ȯ��
	Branch *current;
	branches = clipboard.GetClipboard();

	while (i < branches.GetLength()) {
		current = branches.GetAt(i);
		cout << i + 1 << " " << current->GetTopic()->GetContent() << endl;
		current->GetTopic()->SetContent("copied");
		i++;
	}
	cout << " ���� :  " << (branch1.GetTopic())->GetContent() << " " << (branch2.GetTopic())->GetContent() << " " << (branch3.GetTopic())->GetContent() << endl;

	//�ٿ��ֱ�
	selection.Clear();
	selection.Add(&branch1);
	//clipboard.Paste();

	return 0;
}
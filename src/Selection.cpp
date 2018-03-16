#include "Selection.h"
#include "SubBranchDeselect.h"
#include "OwnerCheckVisitor.h"

Selection::Selection(Long capacity)
	:selections(capacity)
{
	this->capacity = capacity;
	this->length = 0;
}

Selection::Selection(const Selection & source)
	:selections(source.selections)
{
	this->capacity = source.capacity;
	this->length = source.length;
}

Selection::~Selection()
{
}

Long Selection::Add(Branch * branch)
{
	Long index;
	Long i = 0;
	bool isFound = false;
	Shape *current = NULL;

	//���õ� �귣ġ�� ���������� ������ ���õ� �귣ġ�� ��ũ�� ���̰� �Ѵ�.
	while (i < branch->GetLength() && isFound == false)
	{
		current = branch->GetAt(i);
		if (typeid(*current) == typeid(Branch)) {
			branch->GetMark()->Show();
			isFound = true;
		}
		i++;
	}

	// branch�� �迭�� �߰��Ѵ�.
	if (this->length < this->capacity) {
		index = this->selections.Store(this->length, branch);
	}
	else {
		index = this->selections.AppendFromRear(branch);
		this->capacity++;
	}

	this->length++;
	return index;
}

Long Selection::Remove(Branch * branch)
{
	Long index = -1;

	//ã�´�.
	index = this->selections.LinearSearchUnique(&branch, CompareBranches);

	//ã���� ��ũ�� ���ְ� �����.
	if (index != -1) {
		branch->GetMark()->Hide();

		this->selections.Delete(index);
		index = -1;
		this->length--;
	}
	return index;
}

Long Selection::RemoveSubBranch(Branch * branch)
{
	SubBranchDeselect subBranchDeselect(branch, this);
	subBranchDeselect.Traverse();
	return -1;
}

void Selection::Replace(Branch * before, Branch * after)
{
	Long index;
	index = this->selections.LinearSearchUnique(&before, CompareBranches);
	this->selections.Modify(index, after);
}

Long Selection::Correct(Long index, Branch * branch)
{
	index = this->selections.Modify(index, branch);
	return index;
}

void Selection::Clear()
{
	Branch* branch;
	Long i = 0;

	while (i < this->length) {
		//��ũǥ�ø� �����.
		branch = this->selections.GetAt(i);
		branch->GetMark()->Hide();
		i++;
	}
	i = 0;
	while (i < this->length) {
		//���� �����Ѵ�.
		this->selections.Delete(i);
		i++;
	}
	this->length = 0;
}

Branch * Selection::GetLastSelection()
{
	Branch *selection = NULL;
	if (this->length > 0) {
		selection = this->selections.GetAt(this->length - 1);
	}
	return selection;
}

Branch* Selection::GetAt(Long index)
{
	Branch *branch;
	branch = this->selections.GetAt(index);
	return branch;
}

bool Selection::IsSelected(Branch *branch)
{
	bool ret = false;
	Long index = -1;

	index = this->selections.LinearSearchUnique(&branch, CompareBranches);
	if (index != -1) {
		ret = true;
	}
	return ret;
}

bool Selection::IsOwnerExist(Long index)
{
	//�ش� index�� �ִ� �귣ġ�� ownerBranch�� selection�� �ִ��� Ȯ���ϴ� ���� (�����̵����� ���)
	bool ret = false;
	Branch *branch;

	branch = this->selections.GetAt(index);
	OwnerCheckVisitor visitor(&this->selections);
	branch->Accept(visitor);
	if (visitor.GetIsOwner())
	{
		ret = true;
	}

	return ret;
}

Selection& Selection::operator=(const Selection & source)
{
	this->selections = source.selections;
	this->capacity = source.capacity;
	this->length = source.length;

	return *this;
}

int CompareBranches(void *one, void *other) {
	int ret = -1;
	if (*((Branch**)one) == *((Branch**)other)) {
		ret = 0;
	}
	return ret;
}
/*
#include <iostream>
#include <string>
#include "Topic.h"
using namespace std;

int main(int argc, char argv[]) {
	bool ret;
	//���� ����
	Selection selection;
	Selection selection2(3);

	//���� ����
	Topic mainTopic(1, 1, 1, 1, "mainTopic");
	Topic subTopic1(1, 1, 1, 1, "subTopic1");
	Topic subTopic2(1, 1, 1, 1, "subTopic2");
	Topic replaceTopic(1, 1, 1, 1, "replace");

	//�귣ġ����
	Branch mainBranch(111);
	Branch subBranch1;
	Branch subBranch2;
	Branch replace;

	//�귣ġ�� �����߰�
	mainBranch.Add(&mainTopic);
	subBranch1.Add(&subTopic1);
	subBranch2.Add(&subTopic2);
	replace.Add(&replaceTopic);

	//���� ���� Ȯ��
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	cout << "selection2 capacity: " << selection2.GetCapacity() << "  length :  " << selection2.GetLength() << endl;

	//Add ,IsSelected  Test
	ret = selection.IsSelected(&mainBranch);
	if (ret == true) {
		cout << " ���κ귣ġ�� �ֽ��ϴ�." << endl;
	}
	else {
		cout << "���κ귣ġ�� �����ϴ�." << endl;
	}
	selection.Add(&mainBranch);
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	cout << "content : " << selection.GetLastSelection()->GetTopic()->GetContent() << endl;

	ret = selection.IsSelected(&mainBranch);
	if (ret == true) {
		cout << "���κ귣ġ�� �ֽ��ϴ�." << endl;
	}
	else {
		cout << "���κ귣ġ�� �����ϴ�." << endl;
	}
	ret = selection.IsSelected(&subBranch1);
	if (ret == true) {
		cout << "���귣ġ1 �ֽ��ϴ�." << endl;
	}
	else {
		cout << "���귣ġ1 �����ϴ�." << endl;
	}
	selection.Add(&subBranch1);
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	cout << "content : " << selection.GetLastSelection()->GetTopic()->GetContent() << endl;
	ret = selection.IsSelected(&subBranch1);
	if (ret == true) {
		cout << "���귣ġ1�ֽ��ϴ�." << endl;
	}
	else {
		cout << "���귣ġ1�����ϴ�." << endl;
	}
	selection.Add(&subBranch2);
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	cout << "content : " << selection.GetAt(2)->GetTopic()->GetContent() << endl;

	//Replace �׽�Ʈ

	selection.Replace(&subBranch2, &replace);
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	cout << "content : " << selection.GetAt(2)->GetTopic()->GetContent() << endl;

	//���������,Clear Test
	selection2 = selection;
	cout << endl << "selection2 capacity: " << selection2.GetCapacity() << "  length :  " << selection2.GetLength() << endl;
	cout << "content : " << selection.GetLastSelection()->GetTopic()->GetContent() << endl;
	selection2.Clear();
	cout << "selection2 capacity: " << selection2.GetCapacity() << "  length :  " << selection2.GetLength() << endl << endl;

	//Remove Test
	selection.Remove(&subBranch2);
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	cout << "content : " << selection.GetLastSelection()->GetTopic()->GetContent() << endl;
	selection.Remove(&subBranch1);
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	cout << "content : " << selection.GetLastSelection()->GetTopic()->GetContent() << endl;
	ret = selection.IsSelected(&mainBranch);
	if (ret == true) {
		cout << "���κ귣ġ�� �ֽ��ϴ�." << endl;
	}
	else {
		cout << "���κ귣ġ�� �����ϴ�." << endl;
	}
	selection.Remove(&mainBranch);
	cout << "selection capacity: " << selection.GetCapacity() << "  length :  " << selection.GetLength() << endl;
	ret = selection.IsSelected(&mainBranch);
	if (ret == true) {
		cout << "���κ귣ġ�� �ֽ��ϴ�." << endl;
	}
	else {
		cout << "���κ귣ġ�� �����ϴ�." << endl;
	}
	//cout << "content : " << selection.GetLastSelection()->GetTopic()->GetContent() << endl;

	return 0;
}
*/
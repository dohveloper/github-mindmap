#include "BranchArray.h"

BranchArray::BranchArray(Long capacity)
	:branches(capacity)
{
	this->capacity = capacity;
	this->length = 0;
}

BranchArray::BranchArray(const BranchArray & source)
	:branches(source.branches)
{
	this->capacity = source.capacity;
	this->length = source.length;
}

BranchArray::~BranchArray()
{
}

Long BranchArray::Add(Branch * branch)
{
	Long index;
	Long i = 0;
	bool isFound = false;
	Shape *current = NULL;

	// branch�� �迭�� �߰��Ѵ�.
	if (this->length < this->capacity) {
		index = this->branches.Store(this->length, branch);
	}
	else {
		index = this->branches.AppendFromRear(branch);
		this->capacity++;
	}
	this->length++;
	return index;
}

Long BranchArray::Remove(Branch * branch)
{
	Long index = -1;

	//ã�´�.
	index = this->branches.LinearSearchUnique(&branch, CompareBranchLinkes);

	//ã���� ��ũ�� ���ְ� �����.
	if (index != -1) {
		branch->GetMark()->Hide();

		this->branches.Delete(index);
		index = -1;
		this->length--;
	}
	return index;
}

void BranchArray::Clear()
{
	Branch* branch;
	Long i = 0;

	while (i < this->length) {
		this->branches.Delete(i);
		i++;
	}
	this->length = 0;
}

Branch * BranchArray::GetLastBranchArray()
{
	Branch *selection = NULL;
	if (this->length > 0) {
		selection = this->branches.GetAt(this->length - 1);
	}
	return selection;
}

Branch* BranchArray::GetAt(Long index)
{
	Branch *branch;
	branch = this->branches.GetAt(index);
	return branch;
}

BranchArray& BranchArray::operator=(const BranchArray & source)
{
	this->branches = source.branches;
	this->capacity = source.capacity;
	this->length = source.length;

	return *this;
}

int CompareBranchLinkes(void *one, void *other) {
	int ret = -1;
	if (*((Branch**)one) == *((Branch**)other)) {
		ret = 0;
	}
	return ret;
}
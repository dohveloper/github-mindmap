//SingleSelect.cpp
#include "SingleSelect.h"
#include "Selection.h"


SingleSelect::SingleSelect()
{
}

SingleSelect::SingleSelect(const SingleSelect & source)
{
}

SingleSelect::~SingleSelect()
{
}

void SingleSelect::SelectBranch(Selection *selection, Branch *branch)
{
	//1.���� ���õ� �귣ġ���� ��� ���������ϴ�.
	selection->Clear();

	//2.Ŭ���� �귣ġ�� �߰��ϴ�.
	selection->Add(branch);
}

SingleSelect& SingleSelect::operator=(const SingleSelect& source)
{
	return *this;
}

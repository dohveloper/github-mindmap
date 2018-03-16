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
	Long i = 0;

	//���� ���õ� �귣ġ���� ��� ���������ϴ�.
	selection->Clear();

	//Ŭ���� �귣ġ�� �߰��ϴ�.
	selection->Add(branch);
}

SingleSelect& SingleSelect::operator=(const SingleSelect& source)
{
	return *this;
}
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

	//���õ� �귣ġ�� ��� ��ũǥ���� �����.
	while (i < selection->GetLength())
	{
		selection->GetAt(i)->GetMark().HideMark();
		i++;
	}
	//1.���� ���õ� �귣ġ���� ��� ���������ϴ�.
	selection->Clear();

	//2.Ŭ���� �귣ġ�� �߰��ϴ�.
	selection->Add(branch);

	//���õ� �귣ġ�� ��� ��ũǥ���� �巯����.
	i = 0;
	while (i < selection->GetLength())
	{
		selection->GetAt(i)->GetMark().ShowMark();
		i++;
	}
}

SingleSelect& SingleSelect::operator=(const SingleSelect& source)
{
	return *this;
}

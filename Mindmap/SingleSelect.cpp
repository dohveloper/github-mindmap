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
		selection->GetAt(i)->GetMark()->Hide();
		i++;
	}
	//���� ���õ� �귣ġ���� ��� ���������ϴ�.
	selection->Clear();

	//Ŭ���� �귣ġ�� �߰��ϴ�.
	selection->Add(branch);

	//���õ� �귣ġ�� ��ũǥ���� �巯����.
	branch->GetMark()->Show();
}

SingleSelect& SingleSelect::operator=(const SingleSelect& source)
{
	return *this;
}
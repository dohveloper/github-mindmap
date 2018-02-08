//MultiSelect.cpp
#include "MultiSelect.h"
#include "Selection.h"


MultiSelect::MultiSelect()
{
}

MultiSelect::MultiSelect(const MultiSelect & source)
{
}

MultiSelect::~MultiSelect()
{
}

void MultiSelect::SelectBranch(Selection *selection, Branch *branch)
{
	bool isSelected = false;

	isSelected = selection->IsSelected(branch);

	if (isSelected == true)
	{
		branch->GetMark()->Hide(); // �ش� �귣ġ��ũ ����
		selection->Remove(branch);
	}
	else
	{
		branch->GetMark()->Show(); // �ش� �귣ġ��ũ ����
		selection->Add(branch);
	}
}

MultiSelect& MultiSelect::operator=(const MultiSelect& source)
{
	return *this;
}

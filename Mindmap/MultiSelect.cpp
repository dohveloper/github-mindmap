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
		selection->Remove(branch);
	}
	else
	{
		selection->Add(branch);
	}
	
}

MultiSelect& MultiSelect::operator=(const MultiSelect& source)
{
	return *this;
}

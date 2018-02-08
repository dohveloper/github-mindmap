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
		branch->GetMark()->Hide(); // 해당 브랜치마크 숨김
		selection->Remove(branch);
	}
	else
	{
		branch->GetMark()->Show(); // 해당 브랜치마크 보임
		selection->Add(branch);
	}
}

MultiSelect& MultiSelect::operator=(const MultiSelect& source)
{
	return *this;
}

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

	//선택된 브랜치의 모든 마크표식을 숨긴다.
	while (i < selection->GetLength())
	{
		selection->GetAt(i)->GetMark().HideMark();
		i++;
	}
	//1.이전 선택된 브랜치들을 모두 선택해제하다.
	selection->Clear();

	//2.클릭된 브랜치를 추가하다.
	selection->Add(branch);

	//선택된 브랜치의 모든 마크표식을 드러낸다.
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

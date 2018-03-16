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

	//이전 선택된 브랜치들을 모두 선택해제하다.
	selection->Clear();

	//클릭된 브랜치를 추가하다.
	selection->Add(branch);
}

SingleSelect& SingleSelect::operator=(const SingleSelect& source)
{
	return *this;
}
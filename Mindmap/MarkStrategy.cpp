////MarkStrategy.cpp

#include "MarkStrategy.h"
#include "SingleSelect.h"
#include "MultiSelect.h"
#include "Select.h"

MarkStrategy::MarkStrategy()
{
}
MarkStrategy::~MarkStrategy()
{
}
void MarkStrategy::OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Branch *branch)
{
	string markContent;

	markContent = branch->GetMark().GetContent();

	if (markContent == "+")
	{
		//branch->UnFold();	//펼친다.
		branch->GetMark().SetContent("-");
		//하위 브랜치를 펼친다.
	}
	else if (markContent == "-")
	{
		//branch->Fold();	//접는다.
		branch->GetMark().SetContent("+");
		//하위 브랜치를 접는다.
	}
}
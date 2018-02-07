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
	string type;

	if (branch->GetMark().GetContent() == "+")
	{
		branch->UnFold();//펼친다.
		type = "-";
		branch->GetMark().setContent(type);
		//하위 브랜치를 펼친다. 비지터 사용?
	}
	else
	{
		branch->Fold();//접는다.
		type = "+";
		branch->GetMark().setContent(type);
		//하위 브랜치를 접는다.
	}

}



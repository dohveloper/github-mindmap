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
		branch->UnFold();//��ģ��.
		type = "-";
		branch->GetMark().setContent(type);
		//���� �귣ġ�� ��ģ��. ������ ���?
	}
	else
	{
		branch->Fold();//���´�.
		type = "+";
		branch->GetMark().setContent(type);
		//���� �귣ġ�� ���´�.
	}

}



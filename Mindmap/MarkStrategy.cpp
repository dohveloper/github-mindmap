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
		//branch->UnFold();	//��ģ��.
		branch->GetMark().SetContent("-");
		//���� �귣ġ�� ��ģ��.
	}
	else if (markContent == "-")
	{
		//branch->Fold();	//���´�.
		branch->GetMark().SetContent("+");
		//���� �귣ġ�� ���´�.
	}
}
////MarkStrategy.cpp

#include "MarkStrategy.h"
#include "SingleSelect.h"
#include "MultiSelect.h"
#include "FoldVisitor.h"
#include "UnFoldVisitor.h"
#include "Selection.h"
#include "PageForm.h"

MarkStrategy::MarkStrategy()
{
}
MarkStrategy::~MarkStrategy()
{
}
void MarkStrategy::OnLButtonDown(PageForm *pageForm, CPoint point, UINT nFlags, Shape *shape)
{
	string markContent;

	markContent = shape->GetContent();

	if (markContent == "+")
	{
		UnFoldVisitor visitor;
		shape->GetOwnerBranch()->GetMark()->SetContent("-");
		shape->GetOwnerBranch()->Accept(visitor);//���� �귣ġ�� ��ģ��.
	}
	else if (markContent == "-")
	{
		FoldVisitor visitor;
		shape->GetOwnerBranch()->GetMark()->SetContent("+");
		shape->GetOwnerBranch()->Accept(visitor);//���� �귣ġ�� ���´�.
		selection->RemoveSubBranch(shape->GetOwnerBranch());
	}
}
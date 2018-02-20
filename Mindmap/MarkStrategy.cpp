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
		shape->GetOwnerBranch()->Accept(visitor);//하위 브랜치를 펼친다.
	}
	else if (markContent == "-")
	{
		FoldVisitor visitor;
		shape->GetOwnerBranch()->GetMark()->SetContent("+");
		shape->GetOwnerBranch()->Accept(visitor);//하위 브랜치를 접는다.
		selection->RemoveSubBranch(shape->GetOwnerBranch());
	}
}
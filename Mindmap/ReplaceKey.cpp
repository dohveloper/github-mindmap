//ReplaceKey.CPP

#include "ReplaceKey.h"
#include "SearchVisitor.h"
#include "Selection.h"
#include "PageForm.h"
#include "BranchArray.h"
#include "Topic.h"

ReplaceKey::ReplaceKey()
{
}

ReplaceKey::~ReplaceKey()
{
}

void ReplaceKey::KeyDown(PageForm *pageForm)
{
	pageForm->branchArray.Clear();

	SearchVisitor visitor(pageForm);
	pageForm->branch->Accept(visitor);

	if (pageForm->branchArray.GetLength() > 0)
	{
		pageForm->branchArray.GetAt(0)->GetTopic()->SetContent("����");//���ڸ��� ã�� �ܾ� �ִ� ���� �Է�
		pageForm->selection.Clear();
		pageForm->selection.Add(pageForm->branchArray.GetAt(0));
	}
}
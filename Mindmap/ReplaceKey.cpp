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
		pageForm->branchArray.GetAt(0)->GetTopic()->SetContent("토픽");//이자리에 찾을 단어 넣는 수식 입력
		pageForm->selection.Clear();
		pageForm->selection.Add(pageForm->branchArray.GetAt(0));
	}
}
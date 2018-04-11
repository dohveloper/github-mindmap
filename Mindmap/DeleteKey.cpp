//DeleteKey.CPP

#include "DeleteKey.h"
#include "DeleteVisitor.h"
#include "Selection.h"
#include "PageForm.h"

DeleteKey::DeleteKey()
{
}

DeleteKey::~DeleteKey()
{
}

void DeleteKey::KeyDown(PageForm * pageForm)
{
	Long i = 0;
	Long length;

	DeleteVisitor visitor;
	length = pageForm->selection.GetLength();

	while (i < length) //반복하며 선택브랜치 삭제
	{
		visitor.TakeBranch(pageForm->selection.GetAt(i));
		pageForm->branch->Accept(visitor);
		i++;
	}

	Branch *compare = NULL;
	Branch *temp = NULL;

	if (0 < length)
	{
		temp = pageForm->selection.GetLastSelection()->GetOwnerBranch();//마지막 선택브랜치의 오너브랜치값 저장
		compare = temp;
	}

	while (compare != NULL && compare != pageForm->branch)//마지막 선택브랜치의 상위브랜치가 선택배열안에 있는경우 최상위 브랜치의 오너브랜치 선택
	{
		i = 0;
		while (i < length)
		{
			if (pageForm->selection.GetAt(i) == compare)
			{
				compare = pageForm->selection.GetAt(i)->GetOwnerBranch();
				temp = compare;
				i = -1;
			}
			i++;
		}
		compare = compare->GetOwnerBranch();
	}

	if (0 < length)//선택브랜치가 있는 경우 배열을 비우고 저장된 임시브랜치 추가.
	{
		pageForm->selection.Clear();
		pageForm->selection.Add(temp);
	}
}

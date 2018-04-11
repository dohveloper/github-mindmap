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

	while (i < length) //�ݺ��ϸ� ���ú귣ġ ����
	{
		visitor.TakeBranch(pageForm->selection.GetAt(i));
		pageForm->branch->Accept(visitor);
		i++;
	}

	Branch *compare = NULL;
	Branch *temp = NULL;

	if (0 < length)
	{
		temp = pageForm->selection.GetLastSelection()->GetOwnerBranch();//������ ���ú귣ġ�� ���ʺ귣ġ�� ����
		compare = temp;
	}

	while (compare != NULL && compare != pageForm->branch)//������ ���ú귣ġ�� �����귣ġ�� ���ù迭�ȿ� �ִ°�� �ֻ��� �귣ġ�� ���ʺ귣ġ ����
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

	if (0 < length)//���ú귣ġ�� �ִ� ��� �迭�� ���� ����� �ӽú귣ġ �߰�.
	{
		pageForm->selection.Clear();
		pageForm->selection.Add(temp);
	}
}

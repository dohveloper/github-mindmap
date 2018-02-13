#include "SelectionStrategy.h"
#include "SingleSelect.h"
#include "MultiSelect.h"
#include "Select.h"
#include "Selection.h"
#include "MoveVisitor.h"

SelectionStrategy::SelectionStrategy() {
	this->select = NULL;
}
SelectionStrategy::~SelectionStrategy() {
}
void SelectionStrategy::OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape) {
	Branch *branch;

	//�Ҵ�����
	if (this->select != NULL) {
		delete this->select;
		this->select = NULL;
	}

	if (nFlags == MK_CONTROL + MK_LBUTTON)
	{
		this->select = new MultiSelect;
	}
	else
	{
		this->select = new SingleSelect;
	}

	branch = shape->GetOwnerBranch();
	this->select->SelectBranch(selection, branch);

	//�׽�Ʈ

	//Ŭ���� ��ǥ�� ����Ѵ�.
	this->clicked = point;

	//���õ� �귣ġ�� ����Ѵ�
	Branch *selectedBranch;
	Branch *copiedBranch;
	Long i = 0;

	while (i < selection->GetLength()) {
		selectedBranch = selection->GetAt(i);
		copiedBranch = new Branch(*selectedBranch);
		this->unmovedBranches.Add(copiedBranch);
		i++;
	}
}

void SelectionStrategy::OnMouseMove(CPoint point, UINT nFlags)
{
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON) {
		Topic *newTopic;

		//�� ���������� ���� ���Ѵ�.
		Long movedX = this->clicked.x - point.x;
		Long movedY = this->clicked.y - point.y;

		//Ŀ���� �����θ�ŭ �̵��Ѵ�.

		MoveVisitor visitor(movedX, movedY);
		Branch *branch;
		Long i = 0;
		while (i < 0) {
			branch = (Branch*)this->unmovedBranches.GetAt(i);
			branch->Accept(visitor);
			i++;
		}
	}
}

void SelectionStrategy::OnLButtonUp(Selection * selection, UINT nFlags, Branch * branch)
{
}
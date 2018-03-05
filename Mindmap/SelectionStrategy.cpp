#include "SelectionStrategy.h"
#include "SingleSelect.h"
#include "MultiSelect.h"
#include "Select.h"
#include "Selection.h"
#include "MoveVisitor.h"
#include "Topic.h"

SelectionStrategy::SelectionStrategy() {
	this->select = NULL;
}
SelectionStrategy::~SelectionStrategy() {
}
void SelectionStrategy::OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape) {
	Branch *branch;
	Branch *selectedBranch;
	Branch *clone;
	Long i = 0;
	
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

	//Ŭ���� ��ǥ�� �����Ѵ�.
	this->clicked = point;

	//���õ� �귣ġ�� �����Ѵ�


	while (i < selection->GetLength()) {
		selectedBranch = selection->GetAt(i);
		clone = selectedBranch->Clone();
		this->unmovedBranches.Add(clone);
		i++;
	}

	this->selection = selection;
}

void SelectionStrategy::OnMouseMove(CPoint point, UINT nFlags)
{
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON) {
		//���� ���������� ���� ���Ѵ�.
		Long movedX = this->clicked.x - point.x;
		Long movedY = this->clicked.y - point.y;

		//Ŀ���� �����θ�ŭ �̵��Ѵ�.
		MoveVisitor visitor(movedX, movedY);
		Branch *movedBranch;
		Branch *selectedBranch;
		Branch *ownerBranch;
		Long index;
		Long i = 0;

		//ownerBranch = selectedBranch->GetOwnerBranch();

		while (i < unmovedBranches.GetLength()) {
			selectedBranch = this->selection->GetAt(i);
			ownerBranch = selectedBranch->GetOwnerBranch();

			movedBranch = (Branch*)this->unmovedBranches.GetAt(i);
			movedBranch->Accept(visitor);

			//�귣ġ ����
			index = ownerBranch->Find(selectedBranch);
			ownerBranch->Correct(index, movedBranch);

			//selection ����
			this->selection->Correct(i, movedBranch);
			i++;
		}

		//
	}
}

void SelectionStrategy::OnLButtonUp(Selection * selection, UINT nFlags, Branch * branch)
{
}

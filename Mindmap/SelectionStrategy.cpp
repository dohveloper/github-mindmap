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

	//�̵��ϱ�
	Long i = 0;
	Branch *clone;
	this->selection = selection;

	//�� �ʱ�ȭ
	this->unmovedBranches.Clear();

	// 1.point�� ����Ѵ�.
	this->clickedPoint = point;

	// 2.���õ� �귣ġ ����ŭ �ݺ��Ѵ�.
	while (i < selection->GetLength()) {
		clone = selection->GetAt(i)->Clone();
		this->unmovedBranches.Add(clone); //�귣ġ�� ����Ѵ�.
		i++;
	}
}

void SelectionStrategy::OnMouseMove(CPoint point, UINT nFlags)
{
	Long movedX = 0;
	Long movedY = 0;
	Long i = 0;
	Branch *current;
	Branch *selectedBranch;
	Branch *ownerBranch;

	Branch *clone;
	Long centerX;
	Long centerY;

	if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
	{
		//1.�̵����� ���ϴ�.
		movedX = this->clickedPoint.x - point.x;
		movedY = this->clickedPoint.y - point.y;

		MoveVisitor visitor(movedX, movedY);
		// 2.���õ� �귣ġ ����ŭ �ݺ��Ѵ�.
		while (i < this->selection->GetLength()) {
			//2.1 ����� �귣ġ�� �̵�����ŭ �̵��Ѵ�.
			current = this->unmovedBranches.GetAt(i);
			clone = current->Clone();
			clone->Accept(visitor);

			//2.2 ���õ� �귣ġ�� �̵��� �귣ġ�� �ٲٴ�.
			selectedBranch = this->selection->GetAt(i);
			ownerBranch = selectedBranch->GetOwnerBranch();
			ownerBranch->Replace(selectedBranch, clone);
			selection->Replace(selectedBranch, clone);

			i++;
		}
	}
}

void SelectionStrategy::OnLButtonUp(Selection * selection, UINT nFlags, Branch * branch)
{
}
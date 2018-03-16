#include "SingleSelectionStrategy.h"
#include "SingleSelect.h"
#include "MultiSelect.h"
#include "Select.h"
#include "Selection.h"
#include "MoveVisitor.h"
#include "Topic.h"
#include "UpdateTraverser.h"
#define CENTERLINE 700

SingleSelectionStrategy::SingleSelectionStrategy() {
	this->isMoved = false;
}
SingleSelectionStrategy::~SingleSelectionStrategy() {
}
void SingleSelectionStrategy::OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape) {
	Branch *branch;
	bool isSelected;
	SingleSelect select;
	//���ϼ���

	branch = shape->GetOwnerBranch();
	isSelected = selection->IsSelected(branch);
	if (!isSelected)
	{
		select.SelectBranch(selection, branch);
	}
	this->clickedBranch = branch;

	//�̵��ϱ�
	Long i = 0;
	Branch *clone;
	Branch *current;
	this->selection = selection;

	//�� �ʱ�ȭ
	this->unmovedBranches.Clear();

	// 1.point�� ����Ѵ�.
	this->clickedPoint = point;

	// 2.���õ� �귣ġ ����ŭ �ݺ��Ѵ�.
	while (i < selection->GetLength()) {
		current = selection->GetAt(i);
		clone = selection->GetAt(i)->Clone();
		this->unmovedBranches.Add(clone); //�귣ġ�� ����Ѵ�.
		i++;
	}
}

void SingleSelectionStrategy::OnMouseMove(CPoint point, UINT nFlags)
{
	Long movedX = 0;
	Long movedY = 0;
	Long i = 0;
	Long j = 0;
	Branch *current;
	Branch *selectedBranch;

	Branch *clone;
	bool isMain;
	bool isOwnerExist = false;

	if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
	{
		//1.�̵����� ���ϴ�.
		movedX = this->clickedPoint.x - point.x;
		movedY = this->clickedPoint.y - point.y;

		MoveVisitor visitor(CENTERLINE, movedX, movedY);
		// 2.���õ� �귣ġ ����ŭ �ݺ��Ѵ�.
		while (i < this->unmovedBranches.GetLength()) {
			current = this->unmovedBranches.GetAt(i);

			//[ 1.���κ귣ġ�� ��� 2. ���õ� �귣ġ�� Owner�� selection�� �ִ� ��� ] ����  �̵��ϸ� �ȵ�
			isMain = current->IsMain();
			isOwnerExist = this->selection->IsOwnerExist(i);
			if (!isMain && !isOwnerExist) {
				//2.1 �̵��Ѵ�.
				clone = current->Clone();
				clone->Accept(visitor);

				//2.2 �̵��� �귣ġ�� ������Ʈ
				selectedBranch = this->selection->GetAt(i);
				UpdateTraverser traverser(selectedBranch, clone);
				traverser.Traverse();
			}
			i++;
		}
		this->isMoved = true;
	}
}

void SingleSelectionStrategy::OnLButtonUp(Selection * selection, UINT nFlags, Branch * branch)
{
	SingleSelect select;
	if (this->isMoved == false) {
		select.SelectBranch(selection, this->clickedBranch);
	}
}
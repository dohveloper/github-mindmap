#include "SingleSelectionStrategy.h"
#include "SingleSelect.h"
#include "MultiSelect.h"
#include "Select.h"
#include "Selection.h"
#include "MoveVisitor.h"
#include "Topic.h"

#define CENTERLINE 700

SingleSelectionStrategy::SingleSelectionStrategy() {
}
SingleSelectionStrategy::~SingleSelectionStrategy() {
}
void SingleSelectionStrategy::OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape) {
	Branch *branch;

	SingleSelect select;
	//���ϼ���
	branch = shape->GetOwnerBranch();
	select.SelectBranch(selection, branch);

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
		//���κ귣ġ�� �����ϰ� ����
		if (!current->IsMain()) {
			clone = selection->GetAt(i)->Clone();
			this->unmovedBranches.Add(clone); //�귣ġ�� ����Ѵ�.
		}
		i++;
	}
}

void SingleSelectionStrategy::OnMouseMove(CPoint point, UINT nFlags)
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

		MoveVisitor visitor(CENTERLINE, movedX, movedY);
		// 2.���õ� �귣ġ ����ŭ �ݺ��Ѵ�.
		while (i < this->unmovedBranches.GetLength()) {
			//2.1 ����� �귣ġ�� �̵�����ŭ �̵��Ѵ�.
			current = this->unmovedBranches.GetAt(i);
			clone = current->Clone();
			clone->Accept(visitor);

			//2.2 ���õ� �귣ġ�� �̵��� �귣ġ�� �ٲٴ�.
			selectedBranch = this->selection->GetAt(i);
			ownerBranch = selectedBranch->GetOwnerBranch();
			ownerBranch->Replace(selectedBranch, clone);
			selection->Replace(selectedBranch, clone);
		}

		i++;
	}
}

void SingleSelectionStrategy::OnLButtonUp(Selection * selection, UINT nFlags, Branch * branch)
{
}
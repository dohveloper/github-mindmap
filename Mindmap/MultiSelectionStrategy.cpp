#include "MultiSelectionStrategy.h"
#include "SingleSelect.h"
#include "MultiSelect.h"
#include "Select.h"
#include "Selection.h"
#include "MoveVisitor.h"
#include "Topic.h"

#define CENTERLINE 700

MultiSelectionStrategy::MultiSelectionStrategy() {
	this->select = NULL;
}
MultiSelectionStrategy::~MultiSelectionStrategy() {
}
void MultiSelectionStrategy::OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape) {
	Branch *branch;
	bool isSelected;
	MultiSelect select;
	Long i = 0;
	Branch *clone;
	Branch *current;

	//다중선택

	branch = shape->GetOwnerBranch();
	isSelected = selection->IsSelected(branch);
	if (!isSelected)
	{
		select.SelectBranch(selection, branch);
	}
	this->clickedBranch = branch;

	//값 초기화
	this->unmovedBranches.Clear();

	//이동하기
	// 1.기억한다.
	this->clickedPoint = point;
	this->selection = selection;

	// 2.선택된 브랜치 수만큼 반복한다.
	while (i < selection->GetLength()) {
		current = selection->GetAt(i);
		//메인브랜치를 제외하고 복사
		if (!current->IsMain()) {
			clone = current->Clone();
			this->unmovedBranches.Add(clone); //브랜치를 기억한다.
		}
		i++;
	}
}

void MultiSelectionStrategy::OnMouseMove(CPoint point, UINT nFlags)
{
	Long movedX = 0;
	Long movedY = 0;
	Long i = 0;
	Branch *current;
	Branch *selectedBranch;
	Branch *ownerBranch;

	Branch *clone;

	if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
	{
		//1.이동값을 구하다.
		movedX = this->clickedPoint.x - point.x;
		movedY = this->clickedPoint.y - point.y;

		MoveVisitor visitor(CENTERLINE, movedX, movedY);
		// 2.선택된 브랜치 수만큼 반복한다.
		while (i < this->unmovedBranches.GetLength()) {
			//2.1 기억한 브랜치를 이동값만큼 이동한다.
			current = this->unmovedBranches.GetAt(i);
			clone = current->Clone();
			clone->Accept(visitor);

			//2.2 선택된 브랜치를 이동된 브랜치로 바꾸다.
			selectedBranch = this->selection->GetAt(i);
			ownerBranch = selectedBranch->GetOwnerBranch();
			ownerBranch->Replace(selectedBranch, clone);
			this->selection->Replace(selectedBranch, clone);

			i++;
		}
		this->isMoved = true;
	}
}

void MultiSelectionStrategy::OnLButtonUp(Selection * selection, UINT nFlags, Branch * branch)
{
	MultiSelect select;
	if (this->isMoved == false) {
		select.SelectBranch(selection, this->clickedBranch);
	}
}
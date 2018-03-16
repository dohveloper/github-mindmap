#include "MultiSelectionStrategy.h"
#include "SingleSelect.h"
#include "MultiSelect.h"
#include "Select.h"
#include "Selection.h"
#include "MoveVisitor.h"
#include "Topic.h"
#include "UpdateTraverser.h"

#define CENTERLINE 700

MultiSelectionStrategy::MultiSelectionStrategy() {
	this->select = NULL;
	this->isMoved = false;
}
MultiSelectionStrategy::~MultiSelectionStrategy() {
}
void MultiSelectionStrategy::OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape) {
	Branch *branch;
	MultiSelect select;
	Long i = 0;
	Branch *clone;
	Branch *current;

	//다중선택

	branch = shape->GetOwnerBranch();
	this->isSelected = selection->IsSelected(branch);
	if (!this->isSelected)
	{
		select.SelectBranch(selection, branch);
	}
	this->clickedBranch = branch;

	//값 초기화
	this->unmovedBranches.Clear();
	this->isMoved = false;

	//이동하기
	// 1.기억한다.
	this->clickedPoint = point;
	this->selection = selection;

	// 2.선택된 브랜치 수만큼 반복한다.
	while (i < selection->GetLength()) {
		current = selection->GetAt(i);
		clone = selection->GetAt(i)->Clone();
		this->unmovedBranches.Add(clone); //브랜치를 기억한다.
		i++;
	}
}

void MultiSelectionStrategy::OnMouseMove(CPoint point, UINT nFlags)
{
	Long movedX = 0;
	Long movedY = 0;
	Long i = 0;
	Long j = 0;
	Branch *current;
	Branch *selectedBranch;

	Branch *clone;
	bool isMain = false;
	bool isOwnerExist = false;

	if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
	{
		//1.이동값을 구하다.
		movedX = this->clickedPoint.x - point.x;
		movedY = this->clickedPoint.y - point.y;

		MoveVisitor visitor(CENTERLINE, movedX, movedY);
		// 2.선택된 브랜치 수만큼 반복한다.
		while (i < this->unmovedBranches.GetLength()) {
			current = this->unmovedBranches.GetAt(i);

			//[ 1.메인브랜치인 경우 2. 선택된 브랜치의 Owner가 selection에 있는 경우 ] 에는  이동하면 안됨
			isMain = current->IsMain();
			isOwnerExist = this->selection->IsOwnerExist(i);
			if (!isMain && !isOwnerExist) {
				//2.1 이동한다.
				clone = current->Clone();
				clone->Accept(visitor);

				//2.2 이동된 브랜치로 업데이트
				selectedBranch = this->selection->GetAt(i);
				UpdateTraverser traverser(selectedBranch, clone);
				traverser.Traverse();
			}
			i++;
		}
		this->isMoved = true;
	}
}

void MultiSelectionStrategy::OnLButtonUp(Selection * selection, UINT nFlags, Branch * branch)
{
	MultiSelect select;
	if (this->isSelected&&this->isMoved == false)
	{
		select.SelectBranch(selection, this->clickedBranch);
	}
}
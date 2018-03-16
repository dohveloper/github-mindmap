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
	//단일선택

	branch = shape->GetOwnerBranch();
	isSelected = selection->IsSelected(branch);
	if (!isSelected)
	{
		select.SelectBranch(selection, branch);
	}
	this->clickedBranch = branch;

	//이동하기
	Long i = 0;
	Branch *clone;
	Branch *current;
	this->selection = selection;

	//값 초기화
	this->unmovedBranches.Clear();

	// 1.point를 기억한다.
	this->clickedPoint = point;

	// 2.선택된 브랜치 수만큼 반복한다.
	while (i < selection->GetLength()) {
		current = selection->GetAt(i);
		clone = selection->GetAt(i)->Clone();
		this->unmovedBranches.Add(clone); //브랜치를 기억한다.
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

void SingleSelectionStrategy::OnLButtonUp(Selection * selection, UINT nFlags, Branch * branch)
{
	SingleSelect select;
	if (this->isMoved == false) {
		select.SelectBranch(selection, this->clickedBranch);
	}
}
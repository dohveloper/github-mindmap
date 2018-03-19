#include "MultiSelectionStrategy.h"
#include "SingleSelect.h"
#include "MultiSelect.h"
#include "Select.h"
#include "Selection.h"
#include "MoveVisitor.h"
#include "Topic.h"
#include "UpdateTraverser.h"

#define CENTERLINE 5000

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

	select.SelectBranch(selection, branch);

	this->clickedBranch = branch;

	//값 초기화
	this->unmovedBranches.Clear();
	this->isMoved = false;
}

void MultiSelectionStrategy::OnMouseMove(CPoint point, UINT nFlags)
{
}

void MultiSelectionStrategy::OnLButtonUp(Selection * selection, UINT nFlags, Branch * branch)
{
}
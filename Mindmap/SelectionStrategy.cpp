#include "SelectionStrategy.h"
#include "SingleSelect.h"
#include "MultiSelect.h"
#include "Select.h"
#include "PageForm.h"

SelectionStrategy::SelectionStrategy() {
	this->select = NULL;
}
SelectionStrategy::~SelectionStrategy() {
}
void SelectionStrategy::OnLButtonDown(PageForm *pageForm, CPoint point, UINT nFlags, Shape *shape) {
	Branch *branch;

	//할당해제
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
}
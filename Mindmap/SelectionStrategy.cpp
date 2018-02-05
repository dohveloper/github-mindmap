#include "SelectionStrategy.h"
#include "SingleSelect.h"
#include "MultiSelect.h"
#include "Select.h"

SelectionStrategy::SelectionStrategy() {

}
SelectionStrategy::~SelectionStrategy() {

}
void SelectionStrategy::OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Branch *branch) {

	//할당해제
	if (this->select != NULL) {
		//delete this->select;
		//this->select = NULL;
	}

	if (nFlags == MK_CONTROL+ MK_LBUTTON)
	{
		this->select = new MultiSelect;
	}
	else
	{
		this->select = new SingleSelect;
	}

		this->select->SelectBranch(selection, branch);
		
}



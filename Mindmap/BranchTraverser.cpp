#include "BranchTraverser.h"
#include "afxwin.h"
#include "typeinfo.h"

BranchTraverser::BranchTraverser(Branch *branch)
	:iterator(branch)
{
}

bool BranchTraverser::Traverse()
{
	bool result = false;

	for (iterator.First(); !iterator.IsDone(); iterator.Next()) {

		///주석
		//Shape *shape = iterator.CurrentItem();
		//string type = typeid(*shape).name();
		//AfxMessageBox(type.c_str());


		result = ProcessItem(iterator.CurrentItem());
		if (result == false) {
			break;
		}
	}
	return result;
}

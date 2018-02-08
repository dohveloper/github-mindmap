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
		result = ProcessItem(iterator.CurrentItem());
		if (result == false) {
			break;
		}
	}
	return result;
}
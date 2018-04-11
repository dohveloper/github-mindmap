//SearchKey.CPP

#include "SearchKey.h"
#include "SearchVisitor.h"
#include "Selection.h"
#include "PageForm.h"
#include "BranchArray.h"

SearchKey::SearchKey()
{
}

SearchKey::~SearchKey()
{
}

void SearchKey::KeyDown(PageForm *pageForm)
{
	pageForm->branchArray.Clear();

	SearchVisitor visitor(pageForm);
	pageForm->branch->Accept(visitor);

	if (pageForm->branchArray.GetLength() > 0)
	{	
		pageForm->selection.Clear();
		pageForm->selection.Add(pageForm->branchArray.GetAt(0));
	}
}

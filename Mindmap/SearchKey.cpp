//SearchKey.CPP

#include "SearchKey.h"
#include "SearchVisitor.h"
#include "Selection.h"
#include "PageForm.h"

SearchKey::SearchKey()
{
}

SearchKey::~SearchKey()
{
}

void SearchKey::KeyDown(PageForm *pageForm)
{
	//pageForm->branchArray->Clear();
	SearchVisitor visitor(pageForm->branchArray);
	pageForm->branch->Accept(visitor);

	pageForm->selection.Clear();
	
	if (pageForm->branchArray->GetLength() > 0)
	{
		pageForm->selection.Add(pageForm->branchArray->GetAt(1));
	}
}

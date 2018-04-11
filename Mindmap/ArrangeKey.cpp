//ArrangeKey.CPP

#include "Topic.h"
#include "ArrangeKey.h"
#include "ArrangeVisitor.h"
#include "TotalHeightVisitor.h"
#include "HeightClearVisitor.h"
#include "PageForm.h"

ArrangeKey::ArrangeKey()
{
}

ArrangeKey::~ArrangeKey()
{
}

void ArrangeKey::KeyDown(PageForm *pageForm)
{
	
	Long i = 0;
	HeightClearVisitor heightClearVisitor;
	heightClearVisitor.VisitBranch(pageForm->branch);
	TotalHeightVisitor totalHeightVisitor;
	totalHeightVisitor.VisitBranch(pageForm->branch);
	ArrangeVisitor arrangeVisitor(pageForm->branch->GetTopic()->GetX());
	arrangeVisitor.VisitBranch(pageForm->branch);
	//selection->GetLastSelection()->Accept(arrangeVisitor);
}

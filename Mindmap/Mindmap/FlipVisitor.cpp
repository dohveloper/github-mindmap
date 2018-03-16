#include "FlipVisitor.h"
#include "FlipTraverser.h"
#include "Branch.h"
#include "Topic.h"

FlipVisitor::FlipVisitor()
{
}

FlipVisitor::~FlipVisitor()
{
}

void FlipVisitor::VisitBranch(Branch * branch)
{
	Shape *current;
	Long length;
	Long i = 0;
	length = branch->GetLength();

	while (i < length) {
		current = branch->GetAt(i);
		if (typeid(*current) == typeid(Branch)) {
			FlipTraverser traverser((Branch*)current, branch);
			traverser.Traverse();
		}
		i++;
	}
}
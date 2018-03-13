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
	Long centerX;
	Shape *current;
	Long length;
	Long i = 0;
	length = branch->GetLength();

	centerX = branch->GetTopic()->GetX();

	while (i < length) {
		current = branch->GetAt(i);
		if (typeid(*current) == typeid(Branch)) {
			FlipTraverser traverser((Branch*)current, centerX);
			traverser.Traverse();
		}
		i++;
	}
}
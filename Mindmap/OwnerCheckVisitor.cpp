#include "OwnerCheckVisitor.h"
#include "Branch.h"
#include "Array.h"

OwnerCheckVisitor::OwnerCheckVisitor(Array<Branch*> *targets) {
	this->targets = targets;
	this->isOwner = false;
}

OwnerCheckVisitor::~OwnerCheckVisitor() {
}

void OwnerCheckVisitor::VisitBranch(Branch *branch)
{
	//target이 branch의 owner 인지 확인하는 연산
	Long i = 0;
	Branch *owner;
	Branch *current;
	Branch *target;

	while (i < targets->GetLength() && this->isOwner == false) {
		target = this->targets->GetAt(i);
		current = branch;
		owner = current->GetOwnerBranch();
		if (owner == target) {
			this->isOwner = true;
		}
		while (current != owner && this->isOwner == false) {
			current = owner;
			owner = current->GetOwnerBranch();
			if (owner == target) {
				this->isOwner = true;
			}
		}
		if (target->IsMain()) {
			this->isOwner = false;
		}
		i++;
	}
}

bool OwnerCheckVisitor::GetIsOwner()
{
	return this->isOwner;
}
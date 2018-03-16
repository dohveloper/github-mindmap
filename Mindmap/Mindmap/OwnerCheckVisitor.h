#ifndef _OWNERCHECKVISITOR_H
#define _OWNERCHECKVISITOR_H

#include "Array.h"
#include "ShapeVisitor.h"
#include <afxwin.h>

typedef signed long int Long;
class Branch;

class OwnerCheckVisitor : public ShapeVisitor {
public:
	OwnerCheckVisitor(Array<Branch*> *targets);
	virtual ~OwnerCheckVisitor();
	virtual void VisitBranch(Branch *branch);

	bool GetIsOwner();

private:
	Array<Branch*> *targets;
	bool isOwner;
};

#endif _OWNERCHECKVISITOR_H

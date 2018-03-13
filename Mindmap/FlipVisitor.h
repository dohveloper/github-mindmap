#ifndef _FLIPVISITOR_H
#define _FLIPVISITOR_H
#include "ShapeVisitor.h"

typedef signed long int Long;
class Branch;

class FlipVisitor : public ShapeVisitor {
public:
	FlipVisitor();
	virtual ~FlipVisitor();
	virtual void VisitBranch(Branch *branch);

private:
};

#endif _FLIPVISITOR_H

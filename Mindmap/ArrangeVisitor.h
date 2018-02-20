//ArrangeVisitor.h

#ifndef ARRANGEVISITOR_H
#define ARRANGEVISITOR_H
#include "ShapeVisitor.h"
#include <afxwin.h>

class Branch;
class ArrangeVisitor : public ShapeVisitor
{
public:
	ArrangeVisitor();
	~ArrangeVisitor();
	virtual void VisitBranch(Branch *branch);

private:

};

#endif // !ARRANGEVISITOR_H



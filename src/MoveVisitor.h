#ifndef _MOVEVISITOR_H
#define _MOVEVISITOR_H
#include "ShapeVisitor.h"
#include <afxwin.h>

typedef signed long int Long;
class Branch;

class MoveVisitor : public ShapeVisitor {
public:
	MoveVisitor(Long centerX, Long x, Long y);
	virtual ~MoveVisitor();
	virtual void VisitBranch(Branch *branch);

private:
	Long centerLine;
	Long x;
	Long y;
};

#endif _MOVEVISITOR_H

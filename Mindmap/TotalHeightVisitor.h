//TotalHeightVisitor.h

#ifndef _TOTALHEIGHTVISITOR_H
#define _TOTALHEIGHTVISITOR_H
#include "ShapeVisitor.h"
typedef signed long int Long;

class Branch;
class TotalHeightVisitor : public ShapeVisitor
{
public:
	TotalHeightVisitor();
	TotalHeightVisitor(Long totalHeight);
	~TotalHeightVisitor();
	virtual void VisitBranch(Branch *branch);
};

#endif // _TOTALHEIGHTVISITOR_H


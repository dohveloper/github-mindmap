//HeightClearVisitor.h

#ifndef _HEIGHTCLEARVISITOR_H
#define _HEIGHTCLEARVISITOR_H
#include "ShapeVisitor.h"
typedef signed long int Long;

class Branch;
class HeightClearVisitor : public ShapeVisitor
{
public:
	HeightClearVisitor();
	HeightClearVisitor(Long totalHeight);
	~HeightClearVisitor();
	virtual void VisitBranch(Branch *branch);
};

#endif // _HEIGHTCLEARVISITOR_H


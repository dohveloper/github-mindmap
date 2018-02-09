//FoldVisitor.h

#ifndef _FOLDVISITOR_H
#define _FOLDVISITOR_H
#include "ShapeVisitor.h"
#include <afxwin.h>

typedef signed long int Long;
class Topic;
class Line;
class Branch;

class FoldVisitor : public ShapeVisitor {
public:
	FoldVisitor();
	FoldVisitor(Long x, Long y, Long height, Long width);
	virtual ~FoldVisitor();
	virtual void VisitBranch(Branch *branch);

private:
	Long x;
	Long y;
	Long width;
	Long height;
	bool isOverlapped;
};

#endif //_FOLDVISITOR_H

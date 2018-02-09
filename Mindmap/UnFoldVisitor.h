//UnFoldVisitor.h

#ifndef _UNFOLDVISITOR_H
#define _UNFOLDVISITOR_H
#include "ShapeVisitor.h"
#include <afxwin.h>

typedef signed long int Long;
class Topic;
class Line;
class Branch;

class UnFoldVisitor : public ShapeVisitor {
public:
	UnFoldVisitor();
	UnFoldVisitor(Long x, Long y, Long height, Long width);
	virtual ~UnFoldVisitor();
	virtual void VisitBranch(Branch *branch);

private:
	Long x;
	Long y;
	Long width;
	Long height;
	bool isOverlapped;
};

#endif //_UNFOLDVISITOR_H

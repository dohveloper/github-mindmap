#ifndef _HITTESTVISITOR_H
#define _HITTESTVISITOR_H
#include "ShapeVisitor.h"
#include <afxwin.h>

typedef signed long int Long;
class Topic;
class Line;
class Branch;
class MouseAction;

class HitTestVisitor : public ShapeVisitor {
public:
	HitTestVisitor();
	HitTestVisitor(CPoint point, MouseAction *mouseAction, Branch **clickedBranch);
	virtual ~HitTestVisitor();
	virtual void VisitTopic(Topic *topic);
	virtual void VisitBranch(Branch *branch);
	
private:
	CPoint point;
	MouseAction *mouseAction;
	Branch **clickedBranch;

};

#endif _HITTESTVISITOR_H

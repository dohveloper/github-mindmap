//ScrollingVisitor.h

#ifndef _SCROLLINGVISITOR_H
#define _SCROLLINGVISITOR_H


#include <afxwin.h>
#include "ShapeVisitor.h"
class Topic;
class Line;
class PageForm;

class ScrollingVisitor: public ShapeVisitor{
public:
	ScrollingVisitor();
	ScrollingVisitor(CPaintDC *dc);
	virtual ~ScrollingVisitor();
	virtual void VisitTopic(Topic *topic);
	virtual void VisitLine(Line *line);
	virtual void VisitBranch(Branch *branch);

private:
	CPaintDC *dc;
};

#endif _SCROLLINGVISITOR_H
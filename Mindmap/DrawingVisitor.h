#ifndef _DRAWINGVISITOR_H
#define _DRAWINGVISITOR_H


#include <afxwin.h>
#include "ShapeVisitor.h"
class Topic;
class Line;
class PageForm;

class DrawingVisitor: public ShapeVisitor{
public:
	DrawingVisitor();
	DrawingVisitor(CPaintDC *dc);
	virtual ~DrawingVisitor();
	virtual void VisitTopic(Topic *topic);
	virtual void VisitLine(Line *line);
	virtual void VisitBranch(Branch *branch);

private:
	CPaintDC *dc;
};

#endif _DRAWINGVISITOR_H
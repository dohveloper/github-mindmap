#ifndef _DRAWINGVISITOR_H
#define _DRAWINGVISITOR_H

#include <afxwin.h>
#include "ShapeVisitor.h"
class PageForm;
class Branch;
class DrawingVisitor: public ShapeVisitor{
public:
	DrawingVisitor();
	DrawingVisitor(CPaintDC *dc);
	virtual ~DrawingVisitor();
	virtual void VisitBranch(Branch *branch);

private:
	CPaintDC *dc;
};

#endif _DRAWINGVISITOR_H
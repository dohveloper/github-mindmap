//DrawingVisitor.h

#ifndef _DRAWINGVISITOR_H
#define _DRAWINGVISITOR_H

#include <afxwin.h>
#include "ShapeVisitor.h"
typedef signed long int Long;

class PageForm;
class Branch;
class DrawingVisitor: public ShapeVisitor{
public:
	DrawingVisitor();
	DrawingVisitor(CPaintDC *dc, Long movedX, Long movedY);
	virtual ~DrawingVisitor();
	virtual void VisitBranch(Branch *branch);

private:
	CPaintDC *dc;
	Long movedX;
	Long movedY;
};

#endif _DRAWINGVISITOR_H
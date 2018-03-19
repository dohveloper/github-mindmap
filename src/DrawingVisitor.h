//DrawingVisitor.h

#ifndef _DRAWINGVISITOR_H
#define _DRAWINGVISITOR_H

#include <afxwin.h>
#include "ShapeVisitor.h"
typedef signed long int Long;

class PageForm;
class Branch;
class View;
class DrawingVisitor : public ShapeVisitor {
public:
	DrawingVisitor();
	DrawingVisitor(CDC *dc, View *view);
	virtual ~DrawingVisitor();
	virtual void VisitBranch(Branch *branch);

private:
	CDC * dc;
	View *view;
};

#endif _DRAWINGVISITOR_H
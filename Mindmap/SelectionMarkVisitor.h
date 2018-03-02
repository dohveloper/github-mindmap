#ifndef _SELECTIONMARKVISITOR_H
#define _SELECTIONMARKVISITOR_H
#include "ShapeVisitor.h"
#include "Selection.h"
#include <afxwin.h>

typedef signed long int Long;
class Topic;
class Line;
class Branch;
class MouseAction;

class SelectionMarkVisitor : public ShapeVisitor {
public:
	SelectionMarkVisitor();
	SelectionMarkVisitor(Selection *selection,CPaintDC *dc, Long movedX, Long movedY);
	virtual ~SelectionMarkVisitor();
	virtual void VisitTopic(Topic *topic);

private:
	CPaintDC *dc;
	Selection *selection;
	Long movedX;
	Long movedY;
};

#endif _SelectionMarkVisitor_H

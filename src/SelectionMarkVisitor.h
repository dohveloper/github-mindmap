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
class View;

class SelectionMarkVisitor : public ShapeVisitor {
public:
	SelectionMarkVisitor();
	SelectionMarkVisitor(Selection *selection, CDC *dc, View *view);
	virtual ~SelectionMarkVisitor();
	virtual void VisitTopic(Topic *topic);

private:
	CDC * dc;
	Selection *selection;
	View *view;
};

#endif _SelectionMarkVisitor_H

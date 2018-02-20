#ifndef _MOUSESTRATEGY_H
#define _MOUSESTRATEGY_H
#include "Branch.h"
#include <afxwin.h>

class Selection;
class PageForm;

class MouseStrategy {
public:
	MouseStrategy();
	virtual ~MouseStrategy() = 0;
	virtual void OnLButtonDown(PageForm *pageForm, CPoint point, UINT nFlags, Shape *shape);
	virtual void OnMouseMove(PageForm *pageForm, CPoint point);
	virtual void OnLButtonUp(PageForm *pageForm, UINT nFlags, Branch *branch);
};

#endif
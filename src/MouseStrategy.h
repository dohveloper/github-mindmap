#ifndef _MOUSESTRATEGY_H
#define _MOUSESTRATEGY_H
#include "Branch.h"
#include <afxwin.h>

class Selection;

class MouseStrategy {
public:
	MouseStrategy();
	virtual ~MouseStrategy() = 0;
	virtual void OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape);
	virtual void OnMouseMove(CPoint point, UINT nFlags);
	virtual void OnLButtonUp(Selection *selection, UINT nFlags, Branch *branch);
};

#endif

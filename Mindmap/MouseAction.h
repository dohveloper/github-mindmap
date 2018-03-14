#ifndef _MOUSEACTION_H
#define _MOUSEACTION_H
#include "Branch.h"
#include <afxwin.h>

class Selection;
class MouseStrategy;

class MouseAction {
public:
	MouseAction();
	void OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape);
	void OnMouseMove(CPoint point, UINT nFlags);
	void OnLButtonUp(Selection *selection, UINT nFlags, Branch *branch);

	void SetStrategy(Shape *shape, UINT nFlags);
	void SetStrategy(string strategy);
	Shape* GetClickedObject(Branch *branch, CPoint point);

private:
	MouseStrategy * mouseStrategy;
};

#endif // _MOUSEACTION_H

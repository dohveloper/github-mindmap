#ifndef _MOUSEACTION_H
#define _MOUSEACTION_H
#include "Branch.h"
#include <afxwin.h>

class Selection;
class MouseStrategy;

class MouseAction {
public:
	MouseAction();
	void OnLButtonDown(CPoint point, UINT flags, Selection *selection, Shape *shape);
	void OnMouseMove(CPoint point);
	void OnLButtonUp(Selection *selection, UINT nFlags);

	void SetStrategy(Shape *shape);
	Shape* GetClickedObject(Branch *branch, CPoint point);

private:
	MouseStrategy * mouseStrategy;
};

#endif // _MOUSEACTION_H

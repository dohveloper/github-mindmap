2. mouoseAction ¼öÁ¤

#ifndef _MOUSEACTION_H
#define _MOUSEACTION_H
#include "Branch.h"
#include <afxwin.h>

class Selection;
class MouseStrategy;
class PageForm;

class MouseAction {
public:
	MouseAction();
	void OnLButtonDown(PageForm *pageForm, CPoint point, UINT nFlags, Shape *shape);
	void OnMouseMove(PageForm *pageForm, CPoint point);
	void OnLButtonUp(PageForm *pageForm, UINT nFlags, Branch *branch);

	void SetStrategy(Shape *shape);
	Shape* GetClickedObject(Branch *branch, CPoint point);

private:
	MouseStrategy * mouseStrategy;
};

#endif // _MOUSEACTION_H

#ifndef _MOUSEACTION_H
#define _MOUSEACTION_H
#include "Branch.h"
#include "Selection.h"
#include <afxwin.h>

template<typename T> class Array;
class MouseState;

class MouseAction {
public:
	MouseAction();
	void OnLButtonDown(CPoint point,Selection *selection, Branch *branch);
	void OnMouseMove(CPoint point);
	void OnLButtonUp(Selection *selection);
	void ChangeState(MouseState* mouseState);

private:
	friend class MouseState;
	
	
private:
	MouseState* state;

};

#endif

#ifndef _MOUSESTATE_H
#define _MOUSESTATE_H
#include "Branch.h"
#include <afxwin.h>
#include "MouseAction.h"

template<typename T> class Array;

class MouseState {
public:
	MouseState();
	virtual ~MouseState() = 0;
	virtual void OnLButtonDown(MouseAction *mouseAction, CPoint point, Selection *selection, Branch *branch);
	virtual void OnMouseMove(MouseAction *mouseAction, CPoint point);
	virtual void OnLButtonUp(MouseAction *mouseAction, Selection *selection);

protected:
	void ChangeState(MouseAction *mouseAction,MouseState* mouseState);

};

#endif

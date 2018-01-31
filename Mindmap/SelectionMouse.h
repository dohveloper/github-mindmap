#ifndef _SELECTIONMOUSE_H
#define _SELECTIONMOUSE_H
#include "MouseState.h"

template<typename T> class Array;
class SelectionMouse: public MouseState {
public:
	static MouseState* Instance();

	SelectionMouse();
	~SelectionMouse();
	virtual void OnLButtonDown(MouseAction *mouseAction, CPoint point, Selection *selection, Branch *branch);
	virtual void OnLButtonUp(MouseAction *mouseAction, Selection *selection);
};

#endif

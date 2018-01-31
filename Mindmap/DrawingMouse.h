#ifndef _DRAWINGMOUSE_H
#define _DRAWINGMOUSE_H
#include "MouseState.h"
//기능추가 예시

//브랜치기능추가

template<typename T> class Array;
class DrawingMouse : public MouseState {
public:
	static MouseState* Instance();

	DrawingMouse();
	~DrawingMouse();
	virtual void OnLButtonDown(MouseAction *mouseAction, CPoint point, Selection *selection, Branch *branch);
	virtual void OnMouseMove(MouseAction *mouseAction, CPoint point);
	virtual void OnLButtonUp(MouseAction *mouseAction, Selection *selection);

private:
	Long x;
	Long y;
	Long width;
	Long height;
};

#endif

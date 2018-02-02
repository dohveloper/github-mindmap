#ifndef _MOUSESTRATEGY_H
#define _MOUSESTRATEGY_H
#include "Branch.h"
#include <afxwin.h>
#include "MouseAction.h"

template<typename T> class Array;

class MouseStrategy {
public:
	MouseStrategy();
	virtual ~MouseStrategy() = 0;
	virtual void OnLButtonDown(CPoint point,UINT flags, Selection *selection, Branch *branch);
	virtual void OnMouseMove(CPoint point);
	virtual void OnLButtonUp(Selection *selection, bool isOverlapped);


};

#endif

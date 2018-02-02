#ifndef _DRAWINGSTRATEGY_H
#define _DRAWINGSTRATEGY_H
#include "MouseStrategy.h"

class DrawingStrategy : public MouseStrategy {
public:
	DrawingStrategy();
	~DrawingStrategy();
	virtual void OnLButtonDown(CPoint point, UINT flags, Selection *selection, Branch *branch);
	virtual void OnMouseMove(CPoint point);
	virtual void OnLButtonUp(Selection *selection, bool isOverlapped);

private:
	Long x;
	Long y;
	Long width;
	Long height;
};

#endif

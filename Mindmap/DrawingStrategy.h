#ifndef _DRAWINGSTRATEGY_H
#define _DRAWINGSTRATEGY_H
#include "MouseStrategy.h"

class DrawingStrategy : public MouseStrategy {
public:
	DrawingStrategy();
	~DrawingStrategy();
	virtual void OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape);
	virtual void OnMouseMove(CPoint point);
	virtual void OnLButtonUp(Selection *selection, UINT nFlags);

private:
	Long x;
	Long y;
	Long width;
	Long height;
};

#endif

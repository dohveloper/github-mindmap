#ifndef _DRAWINGSTRATEGY_H
#define _DRAWINGSTRATEGY_H
#include "MouseStrategy.h"

class DrawingStrategy : public MouseStrategy {
public:
	DrawingStrategy();
	~DrawingStrategy();
	virtual void OnLButtonDown(PageForm *pageForm, CPoint point, UINT nFlags, Shape *shape);
	virtual void OnMouseMove(PageForm *pageForm, CPoint point);
	virtual void OnLButtonUp(PageForm *pageForm, UINT nFlags, Branch *branch);

private:
	Long x;
	Long y;
	Long width;
	Long height;
};

#endif
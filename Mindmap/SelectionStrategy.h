#ifndef _SELECTIONSTRATEGY_H
#define _SELECTIONSTRATEGY_H
#include "MouseStrategy.h"

class Select;

class SelectionStrategy : public MouseStrategy {
public:
	SelectionStrategy();
	~SelectionStrategy();
	virtual void OnLButtonDown(PageForm *pageForm, CPoint point, UINT nFlags, Shape *shape);
private:
	Select * select;
};

#endif
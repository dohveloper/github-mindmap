#ifndef _SELECTIONSTRATEGY_H
#define _SELECTIONSTRATEGY_H
#include "MouseStrategy.h"

class Select;

class SelectionStrategy: public MouseStrategy {
public:
	SelectionStrategy();
	~SelectionStrategy();
	virtual void OnLButtonDown(CPoint point,UINT nFlags, Selection *selection, Shape *shape);
private:
	Select *select;
};

#endif

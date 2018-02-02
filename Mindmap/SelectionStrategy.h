#ifndef _SELECTIONSTRATEGY_H
#define _SELECTIONSTRATEGY_H
#include "MouseStrategy.h"

class SelectionStrategy: public MouseStrategy {
public:
	SelectionStrategy();
	~SelectionStrategy();
	virtual void OnLButtonDown(CPoint point,UINT nFlags, Selection *selection, Branch *branch);
private:
	//SelectionMouse selectionMouse;
};

#endif

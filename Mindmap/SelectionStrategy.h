#ifndef _SELECTIONSTRATEGY_H
#define _SELECTIONSTRATEGY_H
#include "MouseStrategy.h"
class Branch;
class Select;

class SelectionStrategy : public MouseStrategy {
public:
	SelectionStrategy();
	~SelectionStrategy();
	virtual void OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape);
	virtual void OnMouseMove(CPoint point, UINT nFlags);
	virtual void OnLButtonUp(Selection *selection, UINT nFlags, Branch *branch);

private:
	Select * select;
	CPoint clicked;
	Branch unmovedBranches;
};

#endif

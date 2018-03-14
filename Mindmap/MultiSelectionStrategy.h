#ifndef _MULTISELECTIONSTRATEGY_H
#define _MULTISELECTIONSTRATEGY_H
#include "MouseStrategy.h"
#include "BranchArray.h"
class Branch;
class Select;

class MultiSelectionStrategy : public MouseStrategy {
public:
	MultiSelectionStrategy();
	~MultiSelectionStrategy();
	virtual void OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape);
	virtual void OnMouseMove(CPoint point, UINT nFlags);
	virtual void OnLButtonUp(Selection *selection, UINT nFlags, Branch *branch);

private:
	Select * select;
	Selection *selection;
	CPoint clickedPoint;
	BranchArray unmovedBranches;
	CPoint start;
	CPoint end;
};

#endif //_MULTISELECTIONSTRATEGY_H

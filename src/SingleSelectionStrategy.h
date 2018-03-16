#ifndef _SINGLESELECTIONSTRATEGY_H
#define _SINGLESELECTIONSTRATEGY_H
#include "MouseStrategy.h"
#include "BranchArray.h"
class Branch;

class SingleSelectionStrategy : public MouseStrategy {
public:
	SingleSelectionStrategy();
	~SingleSelectionStrategy();
	virtual void OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape);
	virtual void OnMouseMove(CPoint point, UINT nFlags);
	virtual void OnLButtonUp(Selection *selection, UINT nFlags, Branch *branch);

private:
	Branch * clickedBranch;
	Selection * selection;
	CPoint clickedPoint;
	BranchArray unmovedBranches;
	bool isMoved;
};

#endif //_SINGLESELECTIONSTRATEGY_H

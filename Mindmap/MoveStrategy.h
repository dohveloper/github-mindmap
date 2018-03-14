#ifndef _MOVESTRATEGY_H
#define _MOVESTRATEGY_H
#include "MouseStrategy.h"
#include "BranchArray.h"
class Branch;

class MoveStrategy : public MouseStrategy {
public:
	MoveStrategy();
	~MoveStrategy();
	virtual void OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape);
	virtual void OnMouseMove(CPoint point, UINT nFlags);
	virtual void OnLButtonUp(Selection *selection, UINT nFlags, Branch *branch);

private:
	Selection * selection;
	CPoint clickedPoint;
	BranchArray unmovedBranches;
};

#endif //_MOVESTRATEGY_H

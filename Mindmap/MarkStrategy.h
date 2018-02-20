//MarkStrategy.h

#ifndef _MARKSTRATEGY_H
#define _MARKSTRATEGY_H
#include "MouseStrategy.h"

class Selection;
class MarkStrategy : public MouseStrategy {
public:
	MarkStrategy();
	~MarkStrategy();
	virtual void OnLButtonDown(PageForm *pageForm, CPoint point, UINT nFlags, Shape *shape);
};

#endif //MARKSTRATEGY_H

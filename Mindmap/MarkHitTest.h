#ifndef _MARKHITTEST_H
#define _MARKHITTEST_H
#include "BranchTraverser.h"
#include <afxwin.h>

typedef signed long int Long;
class Topic;
class Mark;
class MarkHitTest :public BranchTraverser {
public:
	MarkHitTest(Branch *branch, CPoint point);

	Mark* GetHitMark() const;
	bool GetIsHit() const;

protected:
	virtual bool ProcessItem(Shape *shape);

private:
	CPoint point;
	Mark * hitMark;
	bool isHit;
};

inline Mark* MarkHitTest::GetHitMark() const {
	return const_cast<Mark*>(this->hitMark);
}

inline bool MarkHitTest::GetIsHit() const {
	return this->isHit;
}

#endif // _MARKHITTEST_H

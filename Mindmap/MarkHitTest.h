#ifndef _MARKHITTEST_H
#define _MARKHITTEST_H
#include "BranchTraverser.h"
#include <afxwin.h>

typedef signed int long;
class Topic;
class MarkHitTest :public BranchTraverser {
public:
	MarkHitTest(Branch *branch, CPoint point);

	Topic* GetHitMark() const;
	bool GetIsHit() const;

protected:
	virtual bool ProcessItem(Shape *shape);

private:
	CPoint point;
	Mark * hitMark;
	bool isHit;
};

inline Topic* MarkHitTest::GetHitMark() const {
	return const_cast<Topic*>(this->hitMark);
}

inline bool MarkHitTest::GetIsHit() const {
	return this->isHit;
}

#endif // _MARKHITTEST_H

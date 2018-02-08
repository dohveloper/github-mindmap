#ifndef _TOPICHITTEST_H
#define _TOPICHITTEST_H
#include "BranchTraverser.h"
#include <afxwin.h>

typedef signed long int Long;
class Topic;
class TopicHitTest :public BranchTraverser {
public:
	TopicHitTest(Branch *branch, CPoint point);

	Topic* GetHitTopic() const;
	bool GetIsHit() const;

protected:
	virtual bool ProcessItem(Shape *shape);

private:
	CPoint point;
	Topic * hitTopic;
	bool isHit;
};

inline Topic* TopicHitTest::GetHitTopic() const {
	return const_cast<Topic*>(this->hitTopic);
}

inline bool TopicHitTest::GetIsHit() const {
	return this->isHit;
}

#endif // _TOPICHITTEST_H

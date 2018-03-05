//OnHScrollLineLeft.h

#ifndef _ONHSCROLLLINELEFT_H
#define _ONHSCROLLLLINELEFT_H
#include "ScrollStrategy.h"
#include "Branch.h"

class OnHScrollLineLeft : public ScrollStrategy {
public:
	OnHScrollLineLeft();
	OnHScrollLineLeft(const OnHScrollLineLeft& source);
	~OnHScrollLineLeft();
	virtual void Scroll(PageForm *pageForm, Long nPos);
	OnHScrollLineLeft& operator=(const OnHScrollLineLeft& source);
};
#endif // ONHSCROLLLINELEFT_H

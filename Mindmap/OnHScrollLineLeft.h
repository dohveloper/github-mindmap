//OnHScrollLineLeft.h

#ifndef _ONHSCROLLLINELEFT_H
#define _ONHSCROLLLLINELEFT_H
#include "ScrollMove.h"
#include "Branch.h"

class OnHScrollLineLeft : public ScrollMove{
public:
	OnHScrollLineLeft();
	OnHScrollLineLeft(const OnHScrollLineLeft& source);
	~OnHScrollLineLeft();
	virtual void Scrolling(PageForm *pageForm);
	OnHScrollLineLeft& operator=(const OnHScrollLineLeft& source);
};
#endif // ONHSCROLLLINELEFT_H

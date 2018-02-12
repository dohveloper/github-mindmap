//OnHScrollPageLeft.h

#ifndef _ONHSCROLLPAGELEFT_H
#define _ONHSCROLLLPAGELEFT_H
#include "ScrollMove.h"
#include "Branch.h"

class OnHScrollPageLeft : public ScrollMove{
public:
	OnHScrollPageLeft();
	OnHScrollPageLeft(const OnHScrollPageLeft& source);
	~OnHScrollPageLeft();
	virtual void Scrolling(PageForm *pageForm);
	OnHScrollPageLeft& operator=(const OnHScrollPageLeft& source);
};
#endif // _ONHSCROLLLPAGELEFT_H

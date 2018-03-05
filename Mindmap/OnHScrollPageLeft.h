//OnHScrollPageLeft.h

#ifndef _ONHSCROLLPAGELEFT_H
#define _ONHSCROLLLPAGELEFT_H
#include "ScrollStrategy.h"
#include "Branch.h"

class OnHScrollPageLeft : public ScrollStrategy {
public:
	OnHScrollPageLeft();
	OnHScrollPageLeft(const OnHScrollPageLeft& source);
	~OnHScrollPageLeft();
	virtual void Scroll(PageForm *pageForm, Long nPos);
	OnHScrollPageLeft& operator=(const OnHScrollPageLeft& source);
};
#endif // _ONHSCROLLLPAGELEFT_H

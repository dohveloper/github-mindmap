//OnHScrollLeft.h

#ifndef _ONHSCROLLLEFT_H
#define _ONHSCROLLLEFT_H
#include "ScrollMove.h"

class OnHScrollLeft : public ScrollMove{
public:
	OnHScrollLeft();
	OnHScrollLeft(const OnHScrollLeft& source);
	~OnHScrollLeft();
	virtual void Scrolling(PageForm *pageForm);
	OnHScrollLeft& operator=(const OnHScrollLeft& source);
};
#endif // ONHSCROLLLEFT_H

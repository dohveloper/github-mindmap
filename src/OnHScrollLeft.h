//OnHScrollLeft.h

#ifndef _ONHSCROLLLEFT_H
#define _ONHSCROLLLEFT_H
#include "ScrollStrategy.h"

class OnHScrollLeft : public ScrollStrategy {
public:
	OnHScrollLeft();
	OnHScrollLeft(const OnHScrollLeft& source);
	~OnHScrollLeft();
	virtual void Scroll(PageForm *pageForm, Long nPos);
	OnHScrollLeft& operator=(const OnHScrollLeft& source);
};
#endif // ONHSCROLLLEFT_H

//OnHScrollRight.h

#ifndef _ONHSCROLLRIGHT_H
#define _ONHSCROLLRIGHT_H
#include "ScrollStrategy.h"

class OnHScrollRight : public ScrollStrategy {
public:
	OnHScrollRight();
	OnHScrollRight(const OnHScrollRight& source);
	~OnHScrollRight();
	virtual void Scroll(PageForm *pageForm, Long nPos);
	OnHScrollRight& operator=(const OnHScrollRight& source);
};
#endif // ONHSCROLLRIGHT_H
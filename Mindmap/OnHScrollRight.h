//OnHScrollRight.h

#ifndef _ONHSCROLLRIGHT_H
#define _ONHSCROLLRIGHT_H
#include "ScrollMove.h"

class OnHScrollRight : public ScrollMove{
public:
	OnHScrollRight();
	OnHScrollRight(const OnHScrollRight& source);
	~OnHScrollRight();
	virtual void Scrolling(PageForm *pageForm);
	OnHScrollRight& operator=(const OnHScrollRight& source);
};
#endif // ONHSCROLLRIGHT_H
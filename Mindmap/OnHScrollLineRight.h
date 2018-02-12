//OnHScrollLineRight.h

#ifndef _ONHSCROLLLINERIGHT_H
#define _ONHSCROLLLINERIGHT_H
#include "ScrollMove.h"

typedef signed long int Long;
class OnHScrollLineRight : public ScrollMove{
public:
	OnHScrollLineRight();
	OnHScrollLineRight(const OnHScrollLineRight& source);
	~OnHScrollLineRight();
	virtual void Scrolling(PageForm *pageForm);
	OnHScrollLineRight& operator=(const OnHScrollLineRight& source);

};
#endif // ONHSCROLLLINERIGHT_H
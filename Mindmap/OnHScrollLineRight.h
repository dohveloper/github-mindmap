//OnHScrollLineRight.h

#ifndef _ONHSCROLLLINERIGHT_H
#define _ONHSCROLLLINERIGHT_H
#include "ScrollStrategy.h"

typedef signed long int Long;
class OnHScrollLineRight : public ScrollStrategy {
public:
	OnHScrollLineRight();
	OnHScrollLineRight(const OnHScrollLineRight& source);
	~OnHScrollLineRight();
	virtual void Scroll(PageForm *pageForm, Long nPos);
	OnHScrollLineRight& operator=(const OnHScrollLineRight& source);

};
#endif // ONHSCROLLLINERIGHT_H
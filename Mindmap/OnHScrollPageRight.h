//OnHScrollPageRight.h

#ifndef _ONHSCROLLPAGERIGHT_H
#define _ONHSCROLLPAGERIGHT_H
#include "ScrollMove.h"

typedef signed long int Long;
class OnHScrollPageRight : public ScrollMove{
public:
	OnHScrollPageRight();
	OnHScrollPageRight(const OnHScrollPageRight& source);
	~OnHScrollPageRight();
	virtual void Scrolling(PageForm *pageForm);
	OnHScrollPageRight& operator=(const OnHScrollPageRight& source);

};
#endif // _ONHSCROLLPAGERIGHT_H
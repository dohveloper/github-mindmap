//OnHScrollPageRight.h

#ifndef _ONHSCROLLPAGERIGHT_H
#define _ONHSCROLLPAGERIGHT_H
#include "ScrollStrategy.h"

typedef signed long int Long;
class OnHScrollPageRight : public ScrollStrategy {
public:
	OnHScrollPageRight();
	OnHScrollPageRight(const OnHScrollPageRight& source);
	~OnHScrollPageRight();
	virtual void Scroll(PageForm *pageForm, Long nPos);
	OnHScrollPageRight& operator=(const OnHScrollPageRight& source);

};
#endif // _ONHSCROLLPAGERIGHT_H
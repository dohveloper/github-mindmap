//OnVScrollDown.h

#ifndef _ONVSCROLLDOWN_H
#define _ONVSCROLLDOWN_H
#include "ScrollStrategy.h"

class OnVScrollDown : public ScrollStrategy {
public:
	OnVScrollDown();
	~OnVScrollDown();
	OnVScrollDown(const OnVScrollDown& source);

	OnVScrollDown& operator=(const OnVScrollDown& socrce);
	virtual void Scroll(PageForm *pageForm, Long nPos);

};
#endif // _ONVSCROLLDOWN_H
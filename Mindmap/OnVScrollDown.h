//OnVScrollDown.h

#ifndef _ONVSCROLLDOWN_H
#define _ONVSCROLLDOWN_H
#include "ScrollMove.h"

class OnVScrollDown : public ScrollMove {
public:
	OnVScrollDown();
	~OnVScrollDown();
	OnVScrollDown(const OnVScrollDown& source);

	OnVScrollDown& operator=(const OnVScrollDown& socrce);
	virtual void Scrolling(PageForm *pageForm);

};
#endif // _ONVSCROLLDOWN_H
//OnVScrollLineDown.h

#ifndef _ONVSCROLLLINEDOWN_H
#define _ONVSCROLLLINEDOWN_H
#include "ScrollMove.h"

class OnVScrollLineDown : public ScrollMove{
public:
	OnVScrollLineDown();
	~OnVScrollLineDown();
	OnVScrollLineDown(const OnVScrollLineDown& source);

	OnVScrollLineDown& operator=(const OnVScrollLineDown& socrce);
	virtual void Scrolling(PageForm *pageForm);

};
#endif // ONVSCROLLLINEDOWN_H

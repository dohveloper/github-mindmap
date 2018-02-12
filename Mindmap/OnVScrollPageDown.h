//OnVScrollPageDown.h

#ifndef _ONVSCROLLPAGEDOW_H
#define _ONVSCROLLPAGEDOW_H
#include "ScrollMove.h"

class OnVScrollPageDown : public ScrollMove {
public:
	OnVScrollPageDown();
	~OnVScrollPageDown();
	OnVScrollPageDown(const OnVScrollPageDown& source);

	OnVScrollPageDown& operator=(const OnVScrollPageDown& socrce);
	virtual void Scrolling(PageForm *pageForm);

};
#endif // _ONVSCROLLPAGEDOW_H
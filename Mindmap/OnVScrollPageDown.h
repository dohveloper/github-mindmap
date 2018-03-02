//OnVScrollPageDown.h

#ifndef _ONVSCROLLPAGEDOW_H
#define _ONVSCROLLPAGEDOW_H
#include "ScrollStrategy.h"

class OnVScrollPageDown : public ScrollStrategy {
public:
	OnVScrollPageDown();
	~OnVScrollPageDown();
	OnVScrollPageDown(const OnVScrollPageDown& source);

	OnVScrollPageDown& operator=(const OnVScrollPageDown& socrce);
	virtual void Scroll(PageForm *pageForm, Long nPos);

};
#endif // _ONVSCROLLPAGEDOW_H
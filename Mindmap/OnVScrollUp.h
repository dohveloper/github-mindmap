//OnVScrollUp.h

#ifndef _ONVSCROLLUP_H
#define _ONVSCROLLUP_H
#include "ScrollMove.h"

class OnVScrollUp : public ScrollMove {
public:
	OnVScrollUp();
	~OnVScrollUp();
	OnVScrollUp(const OnVScrollUp& source);

	OnVScrollUp& operator=(const OnVScrollUp& socrce);
	virtual void Scrolling(PageForm *pageForm);

};
#endif // _ONVSCROLLUP_H
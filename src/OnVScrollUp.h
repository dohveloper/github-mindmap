//OnVScrollUp.h

#ifndef _ONVSCROLLUP_H
#define _ONVSCROLLUP_H
#include "ScrollStrategy.h"

class OnVScrollUp : public ScrollStrategy {
public:
	OnVScrollUp();
	~OnVScrollUp();
	OnVScrollUp(const OnVScrollUp& source);

	OnVScrollUp& operator=(const OnVScrollUp& socrce);
	virtual void Scroll(PageForm *pageForm, Long nPos);

};
#endif // _ONVSCROLLUP_H
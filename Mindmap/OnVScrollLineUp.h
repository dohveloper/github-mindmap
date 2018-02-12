//OnVScrollLineUp.h

#ifndef _ONVSCROLLLINEUP_H
#define _ONVSCROLLLINEUP_H
#include "ScrollMove.h"

class OnVScrollLineUp : public ScrollMove {
public:
	OnVScrollLineUp();
	~OnVScrollLineUp();
	OnVScrollLineUp(const OnVScrollLineUp& source);

	OnVScrollLineUp& operator=(const OnVScrollLineUp& socrce);
	virtual void Scrolling(PageForm *pageForm);

};
#endif // _ONVSCROLLLINEUP_H
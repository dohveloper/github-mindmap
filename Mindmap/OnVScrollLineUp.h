//OnVScrollLineUp.h

#ifndef _ONVSCROLLLINEUP_H
#define _ONVSCROLLLINEUP_H
#include "ScrollStrategy.h"

class OnVScrollLineUp : public ScrollStrategy {
public:
	OnVScrollLineUp();
	~OnVScrollLineUp();
	OnVScrollLineUp(const OnVScrollLineUp& source);

	OnVScrollLineUp& operator=(const OnVScrollLineUp& socrce);
	virtual void Scroll(PageForm *pageForm, Long nPos);

};
#endif // _ONVSCROLLLINEUP_H
//OnVScrollLineDown.h

#ifndef _ONVSCROLLLINEDOWN_H
#define _ONVSCROLLLINEDOWN_H
#include "ScrollStrategy.h"

class OnVScrollLineDown : public ScrollStrategy {
public:
	OnVScrollLineDown();
	~OnVScrollLineDown();
	OnVScrollLineDown(const OnVScrollLineDown& source);

	OnVScrollLineDown& operator=(const OnVScrollLineDown& socrce);
	virtual void Scroll(PageForm *pageForm, Long nPos);

};
#endif // ONVSCROLLLINEDOWN_H

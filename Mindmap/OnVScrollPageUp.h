//OnVScrollPageUp.h

#ifndef _ONVSCROLLPAGEUP_H
#define _ONVSCROLLPAGEUP_H
#include "ScrollMove.h"

class OnVScrollPageUp : public ScrollMove {
public:
	OnVScrollPageUp();
	~OnVScrollPageUp();
	OnVScrollPageUp(const OnVScrollPageUp& source);

	OnVScrollPageUp& operator=(const OnVScrollPageUp& socrce);
	virtual void Scrolling(PageForm *pageForm);

};
#endif // _ONVSCROLLPAGEUP_H
//OnVScrollPageUp.h

#ifndef _ONVSCROLLPAGEUP_H
#define _ONVSCROLLPAGEUP_H
#include "ScrollStrategy.h"

class OnVScrollPageUp : public ScrollStrategy {
public:
	OnVScrollPageUp();
	~OnVScrollPageUp();
	OnVScrollPageUp(const OnVScrollPageUp& source);

	OnVScrollPageUp& operator=(const OnVScrollPageUp& socrce);
	virtual void Scroll(PageForm *pageForm, Long nPos);

};
#endif // _ONVSCROLLPAGEUP_H
//OnVThumb.h

#ifndef _ONVTHUMB_H
#define _ONVTHUMB_H
#include "ScrollStrategy.h"

class OnVThumb : public ScrollStrategy {
public:
	OnVThumb();
	OnVThumb(const OnVThumb& source);
	~OnVThumb();
	virtual void Scroll(PageForm *pageForm, Long nPos);
	OnVThumb& operator=(const OnVThumb& source);
};
#endif // ONVTHUMB_H

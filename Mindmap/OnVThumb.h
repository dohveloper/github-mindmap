//OnVThumb.h

#ifndef _ONVTHUMB_H
#define _ONVTHUMB_H
#include "ScrollMove.h"

class OnVThumb : public ScrollMove{
public:
	OnVThumb();
	OnVThumb(const OnVThumb& source);
	~OnVThumb();
	virtual void ThumbMove(PageForm *pageForm, Long nPos);
	OnVThumb& operator=(const OnVThumb& source);
};
#endif // ONVTHUMB_H

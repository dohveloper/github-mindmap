//OnHThumb.h

#ifndef _ONHTHUMB_H
#define _ONHTHUMB_H
#include "ScrollMove.h"

class OnHThumb : public ScrollMove{
public:
	OnHThumb();
	OnHThumb(const OnHThumb& source);
	~OnHThumb();
	virtual void ThumbMove(PageForm *pageForm, Long nPos);
	OnHThumb& operator=(const OnHThumb& source);
};
#endif // ONHTHUMB_H

//OnHThumb.h

#ifndef _ONHTHUMB_H
#define _ONHTHUMB_H
#include "ScrollStrategy.h"

class OnHThumb : public ScrollStrategy {
public:
	OnHThumb();
	OnHThumb(const OnHThumb& source);
	~OnHThumb();
	virtual void Scroll(PageForm *pageForm, Long nPos);
	OnHThumb& operator=(const OnHThumb& source);
};
#endif // ONHTHUMB_H

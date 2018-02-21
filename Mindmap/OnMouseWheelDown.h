//OnMouseWheelDown.h

#ifndef _ONMOUSEWHEELDOWN_H
#define _ONMOUSEWHEELDOWN_H
#include "OnMouseWheel.h"

class PageForm;
typedef signed long int Long;

class OnMouseWheelDown :public OnMouseWheel {
public:
	OnMouseWheelDown();
	~OnMouseWheelDown();
	Long Scroll(PageForm *pageForm, short zDelta);
	OnMouseWheelDown& operator=(const OnMouseWheelDown& source);
};
#endif // _ONMOUSEWHEELDOWN_H

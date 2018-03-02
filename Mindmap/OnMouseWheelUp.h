//OnMouseWheelUp.h

#ifndef _ONMOUSEWHEELUP_H
#define _ONMOUSEWHEELUP_H
#include "OnMouseWheel.h"
typedef signed long int Long;
class PageForm;

class OnMouseWheelUp :public OnMouseWheel {
public:
	OnMouseWheelUp();
	~OnMouseWheelUp();
	Long Scroll(PageForm *pageForm, short zDelta);
};
#endif // _ONMOUSEWHEELUP_H

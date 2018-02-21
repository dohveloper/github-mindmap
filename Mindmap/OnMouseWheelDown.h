//OnMouseWheelDown.h

#ifndef _ONMOUSEWHEELDOWN_H
#define _ONMOUSEWHEELDOWN_H

class PageForm;
typedef signed long int Long;

class OnMouseWheelDown {
public:
	OnMouseWheelDown();
	~OnMouseWheelDown();
	Long Scroll(PageForm *pageForm, short zDelta);
	OnMouseWheelDown& operator=(const OnMouseWheelDown& source);

private:
	Long movedPosition;
};
#endif // _ONMOUSEWHEELDOWN_H

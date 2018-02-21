//OnMouseWheel.h

#ifndef _ONMOUSEWHEEL_H
#define _ONMOUSEWHEEL_H
typedef signed long int Long;
class PageForm;

class OnMouseWheel {
public:
	OnMouseWheel();
	~OnMouseWheel();
	Long Scroll(PageForm *pageForm, short zDelta);
	OnMouseWheel& operator=(const OnMouseWheel& source);

private:
	Long movedPosition;
};
#endif // _ONMOUSEWHEEL_H

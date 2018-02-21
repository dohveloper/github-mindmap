#ifndef _ONMOUSEWHEEL_H
#define _ONMOUSEWHEEL_H
typedef signed long int Long;
class PageForm;

class OnMouseWheel
{
public:
	OnMouseWheel();
	~OnMouseWheel();
	virtual Long Scroll(PageForm *pageForm, short zDelta) = 0;
};
#endif

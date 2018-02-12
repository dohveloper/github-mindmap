//Scroll.h

#ifndef _SCROLL_H
#define _SCROLL_H
#include "PageForm.h"

typedef signed long int Long;

class ScrollMove;
class Scroll
{
public:
	Scroll();
	Scroll(const Scroll& source);
	~Scroll();

	void MoveHScroll(PageForm *pageForm, Long nSBCode, Long nPos, CScrollBar* pScrollBar);
	void MoveVScroll(PageForm *pageForm, Long nSBCode, Long nPos, CScrollBar* pScrollBar);
	Scroll& operator=(const Scroll& source);

protected:
	ScrollMove *scrollMove;
};


#endif // _SCROLL_H
//ScrollAction.h

#ifndef _SCROLLACTION_H
#define _SCROLLACTION_H
#include "PageForm.h"

typedef signed long int Long;

class ScrollStrategy;
class ScrollAction
{
public:
	ScrollAction();
	ScrollAction(const ScrollAction& source);
	~ScrollAction();
	Long Scroll(PageForm *pageForm, UINT nPos);
	Long Scroll(PageForm *pageForm, short zDelta);

	void SetHScrollStrategy(Long nSBCode);
	void SetVScrollStrategy(Long nSBCode);
	ScrollAction& operator=(const ScrollAction& source);

private:
	ScrollStrategy * scrollStrategy;
};

#endif // _SCROLLACTION_H

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
	Long SetHScrollStrategy(PageForm *pageForm, Long nSBCode, UINT nPos, CScrollBar* pScrollBar);
	Long SetVScrollStrategy(PageForm *pageForm, Long nSBCode, UINT nPos, CScrollBar* pScrollBar);
	ScrollAction& operator=(const ScrollAction& source);

private:
	ScrollStrategy *scrollStrategy;
	//ScrollStrategy *hScrollStrategy;
	//ScrollStrategy *vScrollStrategy;

};
	

#endif // _SCROLLACTION_H

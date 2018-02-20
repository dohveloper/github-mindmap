//ScrollStrategy.h

#ifndef _SCROLLSTATEGY_H
#define _SCROLLSTATEGY_H
#include "PageForm.h"

class ScrollStrategy
{
public:
	ScrollStrategy();
	ScrollStrategy(const ScrollStrategy& source);
	virtual ~ScrollStrategy() = 0;
	virtual void Scroll(PageForm *pageForm, Long nPos);
	ScrollStrategy& operator=(const ScrollStrategy& source);

	Long GetMovedPosition() const;
protected:
	Long movedPosition;
};

inline Long ScrollStrategy::GetMovedPosition() const {
	return this->movedPosition;
}
#endif // SCROLLSTATEGY_H

//ScrollMove.h

#ifndef _SCROLLMOVE_H
#define _SCROLLMOVE_H
#include "PageForm.h"

class ScrollMove
{
public:
	ScrollMove();
	ScrollMove(const ScrollMove& source);
	virtual ~ScrollMove() = 0;
	virtual void Scrolling(PageForm *pageForm);
	virtual void ThumbMove(PageForm *pageForm, Long nPos);
	ScrollMove& operator=(const ScrollMove& source);

	Long GetDrawingPosition() const;
protected:
	Long drawingPosition;
};

inline Long ScrollMove::GetDrawingPosition() const {
	return this->drawingPosition;
}

#endif // SCROLLMOVE_H

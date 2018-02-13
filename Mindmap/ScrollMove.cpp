//ScrollMove.cpp

#include "ScrollMove.h"

ScrollMove::ScrollMove()
{
	this->drawingPosition = 0;
}
ScrollMove::ScrollMove(const ScrollMove& source)
{
}
ScrollMove::~ScrollMove()
{
}

void ScrollMove::Scrolling(PageForm *pageForm)
{
}

void ScrollMove::ThumbMove(PageForm * pageForm, Long nPos)
{

}

ScrollMove& ScrollMove::operator=(const ScrollMove& source)
{
	return *this;
}

//ScrollStrategy.cpp

#include "ScrollStrategy.h"

ScrollStrategy::ScrollStrategy()
{
	this->movedPosition = 0;
}
ScrollStrategy::ScrollStrategy(const ScrollStrategy& source)
{
	this->movedPosition = source.movedPosition;
}
ScrollStrategy::~ScrollStrategy()
{
}

void ScrollStrategy::Scroll(PageForm *pageForm, Long nPos)
{
}

ScrollStrategy& ScrollStrategy::operator=(const ScrollStrategy& source)
{
	this->movedPosition = source.movedPosition;
	return *this;
}

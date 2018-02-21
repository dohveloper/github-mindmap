//OnHScrollLeft.cpp

#include "OnHScrollLeft.h"

OnHScrollLeft::OnHScrollLeft()
{
}

OnHScrollLeft::OnHScrollLeft(const OnHScrollLeft& source)
{
}

OnHScrollLeft::~OnHScrollLeft()
{
}

void OnHScrollLeft::Scroll(PageForm *pageForm, Long nPos)
{
	Long minmumPosition;
	Long maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_HORZ, (int*)&minmumPosition, (int*)&maximumPosition);
	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);

	this->movedPosition = currentPosition - minmumPosition;

	pageForm->SetScrollPos(SB_HORZ, minmumPosition);
}

OnHScrollLeft& OnHScrollLeft::operator=(const OnHScrollLeft& source)
{
	return *this;
}
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

void OnHScrollLeft::Scrolling(PageForm * pageForm)
{
	Long minmumPosition;
	Long maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_HORZ, (int*)&minmumPosition, (int*)&maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_HORZ);
	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);

	currentPosition = minmumPosition;

	pageForm->SetScrollPos(SB_HORZ, currentPosition);
}

OnHScrollLeft& OnHScrollLeft::operator=(const OnHScrollLeft& source)
{
	return *this;
}

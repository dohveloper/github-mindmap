//OnHScrollRight.cpp

#include "OnHScrollRight.h"

OnHScrollRight::OnHScrollRight()
{
}

OnHScrollRight::OnHScrollRight(const OnHScrollRight& source)
{
}

OnHScrollRight::~OnHScrollRight()
{
}

void OnHScrollRight::Scrolling(PageForm *pageForm)
{
	Long minmumPosition;
	Long maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_HORZ, (int*)&minmumPosition, (int*)&maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_HORZ);
	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);

	currentPosition = maximumPosition;

	pageForm->SetScrollPos(SB_HORZ, currentPosition);
}

OnHScrollRight& OnHScrollRight::operator=(const OnHScrollRight& source)
{
	return *this;
}

//OnHScrollLineLeft.cpp

#include "OnHScrollLineLeft.h"

OnHScrollLineLeft::OnHScrollLineLeft()
{
}

OnHScrollLineLeft::OnHScrollLineLeft(const OnHScrollLineLeft& source)
{
}


OnHScrollLineLeft::~OnHScrollLineLeft()
{
}

void OnHScrollLineLeft::Scrolling(PageForm * pageForm)
{
	Long minmumPosition;
	Long maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_HORZ, (int*)&minmumPosition, (int*)&maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_HORZ);
	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);

	currentPosition -= 10;

	if (currentPosition < minmumPosition)
	{
		currentPosition = minmumPosition;
	}

	pageForm->SetScrollPos(SB_HORZ, currentPosition);

}

OnHScrollLineLeft& OnHScrollLineLeft::operator=(const OnHScrollLineLeft& source)
{
	return *this;
}
//OnHScrollPageLeft.cpp

#include "OnHScrollPageLeft.h"

OnHScrollPageLeft::OnHScrollPageLeft()
{
}

OnHScrollPageLeft::OnHScrollPageLeft(const OnHScrollPageLeft& source)
{
}

OnHScrollPageLeft::~OnHScrollPageLeft()
{
}

void OnHScrollPageLeft::Scrolling(PageForm * pageForm)
{
	Long minmumPosition;
	Long maximumPosition;
	Long currentPosition;
	SCROLLINFO info;

	pageForm->GetScrollRange(SB_HORZ, (int*)&minmumPosition, (int*)&maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_HORZ);
	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);
	pageForm->GetScrollInfo(SB_HORZ, &info, SIF_ALL);


	currentPosition -= 100;

	if (currentPosition > minmumPosition)
	{
		currentPosition = max(minmumPosition, currentPosition - (int)info.nPage);
	}

	pageForm->SetScrollPos(SB_HORZ, currentPosition);

}

OnHScrollPageLeft& OnHScrollPageLeft::operator=(const OnHScrollPageLeft& source)
{
	return *this;
}
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

void OnHScrollPageLeft::Scroll(PageForm *pageForm, Long nPos)
{
	Long minmumPosition;
	Long maximumPosition;
	Long currentPosition;
	SCROLLINFO info;

	pageForm->GetScrollRange(SB_HORZ, (int*)&minmumPosition, (int*)&maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_HORZ);
	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);
	pageForm->GetScrollInfo(SB_HORZ, &info, SIF_ALL);

	if (currentPosition > minmumPosition)
	{
		this->movedPosition = (int)info.nPage;
		currentPosition -= (int)info.nPage;
	}
	else
	{
		currentPosition = minmumPosition;
	}
	pageForm->SetScrollPos(SB_HORZ, currentPosition);
}

OnHScrollPageLeft& OnHScrollPageLeft::operator=(const OnHScrollPageLeft& source)
{
	return *this;
}
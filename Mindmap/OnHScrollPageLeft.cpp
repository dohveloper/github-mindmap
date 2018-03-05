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
	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);
	pageForm->GetScrollInfo(SB_HORZ, &info, SIF_ALL);

	if (currentPosition - (int)info.nPage > minmumPosition)
	{
		this->movedPosition = (int)info.nPage;
		currentPosition -= (int)info.nPage;
	}
	else
	{
		this->movedPosition = currentPosition - minmumPosition;
		currentPosition = minmumPosition;
	}
	pageForm->SetScrollPos(SB_HORZ, currentPosition);
}

OnHScrollPageLeft& OnHScrollPageLeft::operator=(const OnHScrollPageLeft& source)
{
	return *this;
}
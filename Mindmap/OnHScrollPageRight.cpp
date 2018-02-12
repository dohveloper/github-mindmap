//OnHScrollPageRight.cpp

#include "OnHScrollPageRight.h"

OnHScrollPageRight::OnHScrollPageRight()
{
}

OnHScrollPageRight::OnHScrollPageRight(const OnHScrollPageRight& source)
{
}

OnHScrollPageRight::~OnHScrollPageRight()
{
}

void OnHScrollPageRight::Scrolling(PageForm *pageForm)
{
	Long minmumPosition;
	Long maximumPosition;
	Long currentPosition;
	SCROLLINFO info;

	pageForm->GetScrollRange(SB_HORZ, (int*)&minmumPosition, (int*)&maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_HORZ);
	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);
	pageForm->GetScrollInfo(SB_HORZ, &info, SIF_ALL);


	currentPosition += 100;

	if (currentPosition < minmumPosition)
	{
		currentPosition = min(minmumPosition, currentPosition - (int)info.nPage);
	}

	pageForm->SetScrollPos(SB_HORZ, currentPosition);

}


OnHScrollPageRight& OnHScrollPageRight::operator=(const OnHScrollPageRight& source)
{
	return *this;
}

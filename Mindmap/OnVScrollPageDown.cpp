//OnVScrollPageDown.cpp

#include "OnVScrollPageDown.h"

OnVScrollPageDown::OnVScrollPageDown()
{
}

OnVScrollPageDown::~OnVScrollPageDown()
{
}

OnVScrollPageDown::OnVScrollPageDown(const OnVScrollPageDown& source)
{
}

void OnVScrollPageDown::Scroll(PageForm *pageForm, Long nPos)
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;
	SCROLLINFO info;
	Long currentMaximum;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);
	pageForm->GetScrollInfo(SB_VERT, &info, SIF_ALL);
	currentMaximum = maximumPosition - info.nPage;

	if (currentPosition + (int)info.nPage < currentMaximum)
	{
		this->movedPosition = -(int)info.nPage;
		currentPosition += (int)info.nPage;
	}
	else if (currentPosition < currentMaximum || currentPosition + (int)info.nPage >= currentMaximum)
	{
		this->movedPosition = currentPosition - currentMaximum;
		currentPosition = currentMaximum;
	}

	pageForm->SetScrollPos(SB_VERT, currentPosition);
}

OnVScrollPageDown& OnVScrollPageDown::operator=(const OnVScrollPageDown& soucre)
{
	return *this;
}
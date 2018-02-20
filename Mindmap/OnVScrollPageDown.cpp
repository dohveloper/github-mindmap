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

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_VERT);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);
	pageForm->GetScrollInfo(SB_VERT, &info, SIF_ALL);

	if (currentPosition < maximumPosition)
	{
		this->movedPosition = -(int)info.nPage;
		currentPosition += (int)info.nPage;
	}
	else
	{
		currentPosition = maximumPosition;
	}
	pageForm->SetScrollPos(SB_VERT, currentPosition);
}

OnVScrollPageDown& OnVScrollPageDown::operator=(const OnVScrollPageDown& soucre)
{
	return *this;
}
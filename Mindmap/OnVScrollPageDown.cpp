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

void OnVScrollPageDown::Scrolling(PageForm *pageForm)
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_VERT);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);

	currentPosition += 100;


	if (currentPosition < minmumPosition)
	{
		currentPosition = maximumPosition;
	}

	pageForm->SetScrollPos(SB_VERT, currentPosition);
}

OnVScrollPageDown& OnVScrollPageDown::operator=(const OnVScrollPageDown& soucre)
{
	return *this;
}
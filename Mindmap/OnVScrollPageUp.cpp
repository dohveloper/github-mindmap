//OnVScrollPageUp.cpp

#include "OnVScrollPageUp.h"

OnVScrollPageUp::OnVScrollPageUp()
{
}

OnVScrollPageUp::~OnVScrollPageUp()
{
}

OnVScrollPageUp::OnVScrollPageUp(const OnVScrollPageUp& source)
{
}

void OnVScrollPageUp::Scroll(PageForm *pageForm, Long nPos)
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;
	SCROLLINFO info;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);
	pageForm->GetScrollInfo(SB_VERT, &info, SIF_ALL);

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

	pageForm->SetScrollPos(SB_VERT, currentPosition);
}

OnVScrollPageUp& OnVScrollPageUp::operator=(const OnVScrollPageUp& soucre)
{
	return *this;
}
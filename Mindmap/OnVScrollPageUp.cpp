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
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_VERT);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);
	pageForm->GetScrollInfo(SB_VERT, &info, SIF_ALL);

	if (currentPosition > minmumPosition)
	{
		this->movedPosition = (int)info.nPage;
		currentPosition -= (int)info.nPage;
	}
	else
	{
		currentPosition = minmumPosition;
	}
	pageForm->SetScrollPos(SB_VERT, currentPosition);
}

OnVScrollPageUp& OnVScrollPageUp::operator=(const OnVScrollPageUp& soucre)
{
	return *this;
}
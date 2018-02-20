//OnVScrollUp.cpp

#include "OnVScrollUp.h"

OnVScrollUp::OnVScrollUp()
{
}

OnVScrollUp::~OnVScrollUp()
{
}

OnVScrollUp::OnVScrollUp(const OnVScrollUp& source)
{
}

void OnVScrollUp::Scroll(PageForm *pageForm, Long nPos)
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_VERT);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);

	this->movedPosition = currentPosition - minmumPosition;
	currentPosition = minmumPosition;

	pageForm->SetScrollPos(SB_VERT, currentPosition);
}

OnVScrollUp& OnVScrollUp::operator=(const OnVScrollUp& soucre)
{
	return *this;
}
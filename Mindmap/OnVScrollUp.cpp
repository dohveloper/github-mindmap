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
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);

	this->movedPosition = currentPosition - minmumPosition;

	pageForm->SetScrollPos(SB_VERT, minmumPosition);
}

OnVScrollUp& OnVScrollUp::operator=(const OnVScrollUp& soucre)
{
	return *this;
}
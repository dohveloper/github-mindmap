//OnVScrollLineUp.cpp

#include "OnVScrollLineUp.h"

OnVScrollLineUp::OnVScrollLineUp()
{
}

OnVScrollLineUp::~OnVScrollLineUp()
{
}

OnVScrollLineUp::OnVScrollLineUp(const OnVScrollLineUp& source)
{
}

void OnVScrollLineUp::Scroll(PageForm *pageForm, Long nPos)
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_VERT);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);
	
	if (currentPosition > minmumPosition)
	{
		this->movedPosition = 10;
		currentPosition -= 10;
	}
	else
	{
		currentPosition = minmumPosition;
	}
	pageForm->SetScrollPos(SB_VERT, currentPosition);
}

OnVScrollLineUp& OnVScrollLineUp::operator=(const OnVScrollLineUp& soucre)
{
	return *this;
}
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

void OnVScrollLineUp::Scrolling(PageForm *pageForm)
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_VERT);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);

	currentPosition -= 10;


	if (currentPosition < minmumPosition)
	{
		currentPosition = minmumPosition;
	}

	pageForm->SetScrollPos(SB_VERT, currentPosition);
}

OnVScrollLineUp& OnVScrollLineUp::operator=(const OnVScrollLineUp& soucre)
{
	return *this;
}
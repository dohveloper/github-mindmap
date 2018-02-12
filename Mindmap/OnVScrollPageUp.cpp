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

void OnVScrollPageUp::Scrolling(PageForm *pageForm)
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_VERT);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);

	currentPosition -= 100;


	if (currentPosition < minmumPosition)
	{
		currentPosition = minmumPosition;
	}

	pageForm->SetScrollPos(SB_VERT, currentPosition);
}

OnVScrollPageUp& OnVScrollPageUp::operator=(const OnVScrollPageUp& soucre)
{
	return *this;
}
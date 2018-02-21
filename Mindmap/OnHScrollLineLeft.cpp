//OnHScrollLineLeft.cpp

#include "OnHScrollLineLeft.h"

OnHScrollLineLeft::OnHScrollLineLeft()
{
}

OnHScrollLineLeft::OnHScrollLineLeft(const OnHScrollLineLeft& source)
{
}

OnHScrollLineLeft::~OnHScrollLineLeft()
{
}

void OnHScrollLineLeft::Scroll(PageForm *pageForm, Long nPos)
{
	Long minmumPosition;
	Long maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_HORZ, (int*)&minmumPosition, (int*)&maximumPosition);
	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);

	if (currentPosition > minmumPosition)
	{
		this->movedPosition = 10;
		currentPosition -= 10;
	}
	pageForm->SetScrollPos(SB_HORZ, currentPosition);
}

OnHScrollLineLeft& OnHScrollLineLeft::operator=(const OnHScrollLineLeft& source)
{
	return *this;
}
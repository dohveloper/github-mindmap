//OnHScrollLineRight.cpp

#include "OnHScrollLineRight.h"

OnHScrollLineRight::OnHScrollLineRight()
{
}

OnHScrollLineRight::OnHScrollLineRight(const OnHScrollLineRight& source)
{
}

OnHScrollLineRight::~OnHScrollLineRight()
{
}

void OnHScrollLineRight::Scroll(PageForm *pageForm, Long nPos)
{
	Long minmumPosition;
	Long maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_HORZ, (int*)&minmumPosition, (int*)&maximumPosition);
	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);

	if (currentPosition < maximumPosition)
	{
		this->movedPosition = -10;
		currentPosition += 10;
	}
	pageForm->SetScrollPos(SB_HORZ, currentPosition);
}

OnHScrollLineRight& OnHScrollLineRight::operator=(const OnHScrollLineRight& source)
{
	return *this;
}
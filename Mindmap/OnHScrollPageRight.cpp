//OnHScrollPageRight.cpp

#include "OnHScrollPageRight.h"

OnHScrollPageRight::OnHScrollPageRight()
{
}

OnHScrollPageRight::OnHScrollPageRight(const OnHScrollPageRight& source)
{
}

OnHScrollPageRight::~OnHScrollPageRight()
{
}

void OnHScrollPageRight::Scroll(PageForm *pageForm, Long nPos)
{
	Long minmumPosition;
	Long maximumPosition;
	Long currentPosition;
	SCROLLINFO info;

	pageForm->GetScrollRange(SB_HORZ, (int*)&minmumPosition, (int*)&maximumPosition);
	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);
	pageForm->GetScrollInfo(SB_HORZ, &info, SIF_ALL);

	if (currentPosition < maximumPosition)
	{
		this->movedPosition = -(int)info.nPage;
		currentPosition += (int)info.nPage;
	}
	pageForm->SetScrollPos(SB_HORZ, currentPosition);
}

OnHScrollPageRight& OnHScrollPageRight::operator=(const OnHScrollPageRight& source)
{
	return *this;
}
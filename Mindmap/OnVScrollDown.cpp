//OnVScrollDown.cpp

#include "OnVScrollDown.h"

OnVScrollDown::OnVScrollDown()
{
}

OnVScrollDown::~OnVScrollDown()
{
}

OnVScrollDown::OnVScrollDown(const OnVScrollDown& source)
{
}

void OnVScrollDown::Scroll(PageForm *pageForm, Long nPos)
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;
	Long currentMaximum;
	SCROLLINFO info;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);
	pageForm->GetScrollInfo(SB_VERT, &info, SIF_ALL);
	currentMaximum = maximumPosition - info.nPage;

	this->movedPosition = currentPosition - currentMaximum;
	pageForm->SetScrollPos(SB_VERT, currentMaximum);
}

OnVScrollDown& OnVScrollDown::operator=(const OnVScrollDown& soucre)
{
	return *this;
}
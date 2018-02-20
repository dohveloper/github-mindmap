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

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_VERT);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);

	this->movedPosition = currentPosition - maximumPosition;
	currentPosition = maximumPosition;

	pageForm->SetScrollPos(SB_VERT, currentPosition);
}

OnVScrollDown& OnVScrollDown::operator=(const OnVScrollDown& soucre)
{
	return *this;
}
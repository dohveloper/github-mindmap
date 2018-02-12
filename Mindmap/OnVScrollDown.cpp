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

void OnVScrollDown::Scrolling(PageForm *pageForm)
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_VERT);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);

	currentPosition = maximumPosition;

	pageForm->SetScrollPos(SB_VERT, currentPosition);
}

OnVScrollDown& OnVScrollDown::operator=(const OnVScrollDown& soucre)
{
	return *this;
}
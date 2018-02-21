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
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);

	this->movedPosition = currentPosition - maximumPosition;
	pageForm->SetScrollPos(SB_VERT, maximumPosition);
}

OnVScrollDown& OnVScrollDown::operator=(const OnVScrollDown& soucre)
{
	return *this;
}
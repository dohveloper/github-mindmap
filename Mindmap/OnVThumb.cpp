//OnVThumb.cpp

#include "OnVThumb.h"

OnVThumb::OnVThumb()
{
}

OnVThumb::OnVThumb(const OnVThumb& source)
{
}

OnVThumb::~OnVThumb()
{
}

void OnVThumb::Scroll(PageForm *pageForm, Long nPos)
{
	Long currentPosition;

	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);
	this->movedPosition = currentPosition - nPos;

	pageForm->SetScrollPos(SB_VERT, nPos);
}

OnVThumb& OnVThumb::operator=(const OnVThumb& source)
{
	return *this;
}
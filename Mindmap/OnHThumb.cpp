//OnHThumb.cpp

#include "OnHThumb.h"

OnHThumb::OnHThumb()
{
}

OnHThumb::OnHThumb(const OnHThumb& source)
{
}

OnHThumb::~OnHThumb()
{
}

void OnHThumb::Scroll(PageForm *pageForm, Long nPos)
{
	Long currentPosition;

	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);
	this->movedPosition = currentPosition - nPos;
	currentPosition = nPos;

	pageForm->SetScrollPos(SB_HORZ, nPos);
}

OnHThumb& OnHThumb::operator=(const OnHThumb& source)
{
	return *this;
}
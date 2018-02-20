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
	Long minmumPosition;
	Long maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_VERT, (int*)&minmumPosition, (int*)&maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_VERT);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);

	this->movedPosition = currentPosition - nPos;
	currentPosition = nPos;

	pageForm->SetScrollPos(SB_VERT, nPos);

}

OnVThumb& OnVThumb::operator=(const OnVThumb& source)
{
	return *this;
}

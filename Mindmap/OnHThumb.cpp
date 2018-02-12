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

void OnHThumb::ThumbMove(PageForm *pageForm, Long nPos)
{
	Long minmumPosition;
	Long maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_HORZ, (int*)&minmumPosition, (int*)&maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_HORZ);
	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);

	currentPosition = nPos;

	pageForm->SetScrollPos(SB_HORZ, nPos);

}

OnHThumb& OnHThumb::operator=(const OnHThumb& source)
{
	return *this;
}

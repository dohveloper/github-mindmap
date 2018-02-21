#include "OnMouseWheelDown.h"
#include "PageForm.h"

OnMouseWheelDown::OnMouseWheelDown()
{
	this->movedPosition = 0;
}
OnMouseWheelDown::~OnMouseWheelDown()
{
}

Long OnMouseWheelDown::Scroll(PageForm * pageForm, short zDelta)
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);

	if (currentPosition < maximumPosition && currentPosition > minmumPosition)
	{
		this->movedPosition = zDelta;
		currentPosition += zDelta;
	}

	pageForm->SetScrollPos(SB_VERT, currentPosition);

	return this->movedPosition;
}

OnMouseWheelDown & OnMouseWheelDown::operator=(const OnMouseWheelDown & source)
{
	return *this;
}
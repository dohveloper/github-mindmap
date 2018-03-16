#include "OnMouseWheelDown.h"
#include "PageForm.h"

OnMouseWheelDown::OnMouseWheelDown()
	:OnMouseWheel()
{
}
OnMouseWheelDown::~OnMouseWheelDown()
{
}

Long OnMouseWheelDown::Scroll(PageForm * pageForm, short zDelta)
{
	int minimum;
	int maximum;
	Long current;
	Long currentMax;
	SCROLLINFO info;
	Long movedPosition = 0;

	pageForm->GetScrollRange(SB_VERT, &minimum, &maximum);
	current = (Long)pageForm->GetScrollPos(SB_VERT);
	pageForm->GetScrollInfo(SB_VERT, &info, SIF_ALL);

	currentMax = maximum - info.nPage;

	if (current < currentMax && current - zDelta <= currentMax) {
		movedPosition = zDelta;
		current -= zDelta;
	}
	else if (current < currentMax && current - zDelta > currentMax) {
		movedPosition = current - currentMax;
		current = currentMax;
	}
	pageForm->SetScrollPos(SB_VERT, current);

	return movedPosition;
}

OnMouseWheelDown & OnMouseWheelDown::operator=(const OnMouseWheelDown & source)
{
	return *this;
}
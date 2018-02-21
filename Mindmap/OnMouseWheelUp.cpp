#include "OnMouseWheelUp.h"
#include "PageForm.h"

OnMouseWheelUp::OnMouseWheelUp()
	:OnMouseWheel()
{
}

OnMouseWheelUp::~OnMouseWheelUp()
{
}

Long OnMouseWheelUp::Scroll(PageForm * pageForm, short zDelta)
{
	int minimum;
	int maximum;
	Long current;
	SCROLLINFO info;
	Long movedPosition = 0;

	pageForm->GetScrollRange(SB_VERT, &minimum, &maximum);
	current = (Long)pageForm->GetScrollPos(SB_VERT);
	//pageForm->GetScrollInfo(SB_VERT, &info, SIF_ALL);

	if (current > minimum && current + zDelta >= minimum) {
		movedPosition = zDelta;
		current -= zDelta;
	}
	else if (current > minimum && current + zDelta > minimum) {
		movedPosition = minimum - current;
		current = minimum;
	}
	pageForm->SetScrollPos(SB_VERT, current);

	return movedPosition;
}
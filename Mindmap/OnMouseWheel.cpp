#include "OnMouseWheel.h"
#include "PageForm.h"

OnMouseWheel::OnMouseWheel()
{
	this->movedPosition = 0;
}
OnMouseWheel::~OnMouseWheel()
{
}

Long OnMouseWheel::Scroll(PageForm * pageForm, short zDelta)
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;
	SCROLLINFO info;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition);
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT);
	pageForm->GetScrollInfo(SB_VERT, &info, SIF_ALL);

	if (zDelta < 0)
	{
		CString string;
		string.Format(_T("current: %d  max : %d "), currentPosition, maximumPosition);
		AfxMessageBox(string);

		if (currentPosition < maximumPosition)
		{
			this->movedPosition = zDelta;
			currentPosition -= zDelta;
		}
		else {
			currentPosition = maximumPosition;
		}
	}

	if (zDelta > 0)
	{
		if (currentPosition > minmumPosition) {
			this->movedPosition = zDelta;
			currentPosition -= zDelta;
		}
		else {
			currentPosition = minmumPosition;
		}
	}
	pageForm->SetScrollPos(SB_VERT, currentPosition);

	return this->movedPosition;
}

OnMouseWheel & OnMouseWheel::operator=(const OnMouseWheel & source)
{
	return *this;
}
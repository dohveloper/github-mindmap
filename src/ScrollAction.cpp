//ScrollAction.cpp

#include "ScrollAction.h"
#include "PageForm.h"
#include "OnHThumb.h"
#include "OnHScrollLeft.h"
#include "OnHScrollRight.h"
#include "OnHScrollLineRight.h"
#include "OnHScrollLineLeft.h"
#include "OnHScrollPageRight.h"
#include "OnHScrollPageLeft.h"
#include "OnVThumb.h"
#include "OnVScrollUp.h"
#include "OnVScrollDown.h"
#include "OnVScrollLineUp.h"
#include "OnVScrollLineDown.h"
#include "OnVScrollPageUp.h"
#include "OnVScrollPageDown.h"
#include "OnMouseWheel.h"
#include "OnMouseWheelUp.h"
#include "OnMouseWheelDown.h"

ScrollAction::ScrollAction()
{
	this->scrollStrategy = NULL;
}

ScrollAction::ScrollAction(const ScrollAction & source)
{
	this->scrollStrategy = source.scrollStrategy;
}

ScrollAction::~ScrollAction()
{
}

Long ScrollAction::Scroll(PageForm *pageForm, UINT nPos)
{
	Long movedPosition = 0;
	if (this->scrollStrategy != NULL)
	{
		this->scrollStrategy->Scroll(pageForm, nPos);
		movedPosition = this->scrollStrategy->GetMovedPosition();
	}
	return movedPosition;
}

Long ScrollAction::Scroll(PageForm * pageForm, UINT nFlags, short zDelta)
{
	Long movedPosition = 0;
	Long startY;
	OnMouseWheel *onMouseWheel = NULL;
	if (nFlags == MK_CONTROL)
	{
		pageForm->view->Zoom(zDelta);
	}

	else {
		if (zDelta > 0) {
			onMouseWheel = new OnMouseWheelUp();
		}
		else {
			onMouseWheel = new OnMouseWheelDown();
		}

		movedPosition = onMouseWheel->Scroll(pageForm, zDelta);
		startY = pageForm->view->GetStartY();
		startY -= movedPosition;
		pageForm->view->SetStartY(startY);

		if (onMouseWheel != NULL) {
			delete onMouseWheel;
		}
	}

	return movedPosition;
}

void ScrollAction::SetHScrollStrategy(Long nSBCode)
{
	if (this->scrollStrategy != NULL)
	{
		delete this->scrollStrategy;
		this->scrollStrategy = NULL;
	}

	switch (nSBCode)
	{
	case SB_THUMBTRACK:
	{
		this->scrollStrategy = new OnHThumb();
		break;
	}
	case SB_LEFT:
	{
		this->scrollStrategy = new OnHScrollLeft();
		break;
	}
	case SB_RIGHT:
	{
		this->scrollStrategy = new OnHScrollRight();
		break;
	}
	case SB_LINELEFT:
	{
		this->scrollStrategy = new OnHScrollLineLeft();
		break;
	}
	case SB_LINERIGHT:
	{
		this->scrollStrategy = new OnHScrollLineRight();
		break;
	}
	case SB_PAGELEFT:
	{
		this->scrollStrategy = new OnHScrollPageLeft();
		break;
	}
	case SB_PAGERIGHT:
	{
		this->scrollStrategy = new OnHScrollPageRight();
		break;
	}
	default:
		break;
	}
}

void ScrollAction::SetVScrollStrategy(Long nSBCode)
{
	if (this->scrollStrategy != NULL)
	{
		delete this->scrollStrategy;
		this->scrollStrategy = NULL;
	}

	switch (nSBCode)
	{
	case SB_THUMBTRACK:
	{
		this->scrollStrategy = new OnVThumb();
		break;
	}
	case SB_TOP:
	{
		this->scrollStrategy = new OnVScrollUp();
		break;
	}
	case SB_BOTTOM:
	{
		this->scrollStrategy = new OnVScrollDown();

		break;
	}
	case SB_LINEUP:
	{
		this->scrollStrategy = new OnVScrollLineUp();
		break;
	}
	case SB_LINEDOWN:
	{
		this->scrollStrategy = new OnVScrollLineDown();
		break;
	}
	case SB_PAGEUP:
	{
		this->scrollStrategy = new OnVScrollPageUp();
		break;
	}
	case SB_PAGEDOWN:
	{
		this->scrollStrategy = new OnVScrollPageDown();
		break;
	}

	default:
		break;
	}
}

ScrollAction& ScrollAction::operator=(const ScrollAction& source)
{
	this->scrollStrategy = source.scrollStrategy;
	return *this;
}
//Scroll.cpp

#include "Scroll.h"
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


Scroll::Scroll()
{
	this->scrollMove = NULL;
	this->currentPosition = 0;
}

Scroll::Scroll(const Scroll & source)
{
	this->scrollMove = source.scrollMove;
}

Scroll::~Scroll()
{
}

Long Scroll::MoveHScroll(PageForm *pageForm, Long nSBCode, Long nPos, CScrollBar * pScrollBar)
{
	switch (nSBCode)
	{

	case SB_THUMBTRACK:
	{
		OnHThumb onHThumb;
		onHThumb.ThumbMove(pageForm, nPos);
		break;
	}
	case SB_LEFT:
	{
		OnHScrollLeft onHScrollLeft;
		onHScrollLeft.Scrolling(pageForm);
		break;
	}
	case SB_RIGHT:
	{
		OnHScrollRight onHScrollRight;
		onHScrollRight.Scrolling(pageForm);
		break;
	}
	case SB_LINELEFT:
	{
		OnHScrollLineLeft onHScrollLineLeft;
		onHScrollLineLeft.Scrolling(pageForm);
		break;
	}
	case SB_LINERIGHT:
	{
		OnHScrollLineRight onHScrollLineRight;
		onHScrollLineRight.Scrolling(pageForm);
		break;
	}
	case SB_PAGELEFT:
	{
		OnHScrollPageLeft onHScrollPageLeft;
		onHScrollPageLeft.Scrolling(pageForm);
		break;
	}
	case SB_PAGERIGHT:
	{
		OnHScrollPageRight onHScrollPageRight;
		onHScrollPageRight.Scrolling(pageForm);
		break;
	}
	default:
		break;
	}

	return this->currentPosition;
}


void Scroll::MoveVScroll(PageForm *pageForm, Long nSBCode, Long nPos, CScrollBar* pScrollBar)
{
	switch (nSBCode)
	{

	case SB_THUMBTRACK:
	{
		OnVThumb onVThumb;
		onVThumb.Scrolling(pageForm);
		break;
	}
	case SB_TOP:
	{
		OnVScrollUp onVScrollUp;
		onVScrollUp.Scrolling(pageForm);
		break;
	}
	case SB_BOTTOM:
	{
		OnVScrollDown onVScrollDown;
		onVScrollDown.Scrolling(pageForm);
		break;
	}
	case SB_LINEUP:
	{
		OnVScrollLineUp onVScrollLineUp;
		onVScrollLineUp.Scrolling(pageForm);
		break;
	}
	case SB_LINEDOWN:
	{
		OnVScrollLineDown onVScrollLineDown;
		onVScrollLineDown.Scrolling(pageForm);
		break;
	}
	case SB_PAGEUP:
	{
		OnVScrollPageUp onVScrollPageUp;
		onVScrollPageUp.Scrolling(pageForm);
		break;
	}
	case SB_PAGEDOWN:
	{
		OnVScrollPageDown onVScrollPageDown;
		onVScrollPageDown.Scrolling(pageForm);
		break;
	}
	default:
		break;
	}
}

Scroll& Scroll::operator=(const Scroll& source)
{
	return *this;
}

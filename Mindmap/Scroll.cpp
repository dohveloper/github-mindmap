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
}

Scroll::Scroll(const Scroll & source)
{
	this->scrollMove = source.scrollMove;
}

Scroll::~Scroll()
{
}

void Scroll::MoveHScroll(PageForm *pageForm, Long nSBCode, Long nPos, CScrollBar * pScrollBar)
{
	switch (nSBCode)
	{

	case SB_THUMBTRACK:
		this->scrollMove = new OnHThumb;
		this->scrollMove->ThumbMove(pageForm, nPos);
		break;

	case SB_LEFT:      
		this->scrollMove = new OnHScrollLeft;
		this->scrollMove->Scrolling(pageForm);
		break;

	case SB_RIGHT:      
		this->scrollMove = new OnHScrollRight;
		this->scrollMove->Scrolling(pageForm);
		break;

	case SB_LINELEFT:
		this->scrollMove = new OnHScrollLineLeft;
		this->scrollMove->Scrolling(pageForm);
		break;

	case SB_LINERIGHT:
		this->scrollMove = new OnHScrollLineRight;
		this->scrollMove->Scrolling(pageForm);
		break;

	case SB_PAGELEFT:
		this->scrollMove = new OnHScrollPageLeft;
		this->scrollMove->Scrolling(pageForm);
		break;

	case SB_PAGERIGHT:
		this->scrollMove = new OnHScrollPageRight;
		this->scrollMove->Scrolling(pageForm);
		break;
	}

	if (this->scrollMove != NULL)
	{
		delete this->scrollMove;
		this->scrollMove = NULL;
	}

}


void Scroll::MoveVScroll(PageForm *pageForm, Long nSBCode, Long nPos, CScrollBar* pScrollBar)
{


	switch (nSBCode)
	{
	case SB_THUMBTRACK:
		this->scrollMove = new OnVThumb;
		this->scrollMove->ThumbMove(pageForm, nPos);
		break;

	case SB_TOP:
		this->scrollMove = new OnVScrollUp;
		this->scrollMove->Scrolling(pageForm);
		break;

	case SB_BOTTOM:
		this->scrollMove = new OnVScrollDown;
		this->scrollMove->Scrolling(pageForm);
		break;

	case SB_LINEUP:
		this->scrollMove = new OnVScrollLineUp;
		this->scrollMove->Scrolling(pageForm);
		break;

	case SB_LINEDOWN:
		this->scrollMove = new OnVScrollLineDown;
		this->scrollMove->Scrolling(pageForm);
		break;

	case SB_PAGEUP:
		this->scrollMove = new OnVScrollPageUp;
		this->scrollMove->Scrolling(pageForm);
		break;

	case SB_PAGEDOWN:
		this->scrollMove = new OnVScrollPageDown;
		this->scrollMove->Scrolling(pageForm);
		break;
	}

	if (this->scrollMove != NULL)
	{
		delete this->scrollMove;
		this->scrollMove = NULL;
	}
}

Scroll& Scroll::operator=(const Scroll& source)
{
	return *this;
}

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

Long ScrollAction::SetHScrollStrategy(PageForm *pageForm, Long nSBCode, UINT nPos, CScrollBar* pScrollBar)
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
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	case SB_LEFT:
	{
		this->scrollStrategy = new OnHScrollLeft();
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	case SB_RIGHT:
	{
		this->scrollStrategy = new OnHScrollRight();
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	case SB_LINELEFT:
	{
		this->scrollStrategy = new OnHScrollLineLeft();
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	case SB_LINERIGHT:
	{
		this->scrollStrategy = new OnHScrollLineRight();
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	case SB_PAGELEFT:
	{
		this->scrollStrategy = new OnHScrollPageLeft();
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	case SB_PAGERIGHT:
	{
		this->scrollStrategy = new OnHScrollPageRight();
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	default:
		break;
	}
	return this->scrollStrategy->GetMovedPosition();
}

Long ScrollAction::SetVScrollStrategy(PageForm * pageForm, Long nSBCode, UINT nPos, CScrollBar * pScrollBar)
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
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	case SB_TOP:
	{
		this->scrollStrategy = new OnVScrollUp();
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	case SB_BOTTOM:
	{
		this->scrollStrategy = new OnVScrollDown();
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	case SB_LINEUP:
	{
		this->scrollStrategy = new OnVScrollLineUp();
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	case SB_LINEDOWN:
	{
		this->scrollStrategy = new OnVScrollLineDown();
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	case SB_PAGEUP:
	{
		this->scrollStrategy = new OnVScrollPageUp();
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	case SB_PAGEDOWN:
	{
		this->scrollStrategy = new OnVScrollPageDown();
		this->scrollStrategy->Scroll(pageForm, nPos);
		break;
	}
	default:
		break;
	}
	//this->scrollStrategy->Scroll(pageForm, nPos);
	
}




ScrollAction& ScrollAction::operator=(const ScrollAction& source)
{
	this->scrollStrategy = source.scrollStrategy;
	return *this;
}
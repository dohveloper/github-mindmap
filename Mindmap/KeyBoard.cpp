//KeyBoard.cpp

#include "KeyBoard.h"
#include "KeyAction.h"
#include "PageForm.h"
#include "DeleteKey.h"

KeyBoard::KeyBoard()
{
}

KeyBoard::~KeyBoard()
{
}

void KeyBoard::KeyDown(PageForm *pageForm, UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_DELETE:
		DeleteKey deleteKey;
		//this->keyAction = new DeleteKey;
		this->keyAction->KeyPress(pageForm);
		break;
	}
	/*
	if (this->scrollMove != NULL)
	{
	delete this->scrollMove;
	this->scrollMove = NULL;
	}
	*/
}

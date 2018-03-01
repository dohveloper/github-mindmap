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
	{
		DeleteKey deleteKey;
		deleteKey.KeyPress(pageForm);
		break;
	}
	case VK_RETURN://엔터
	{
		break;
	}
	case VK_SPACE://스페이스
	{
		break;
	}
	case VK_ESCAPE://ESC
	{
		break;
	}
	case VK_TAB://탭
	{
		break;
	}
	case VK_BACK://백스페이스
	{
		break;
	}
	case VK_LEFT://왼쪽방향
	{
		break;
	}
	case VK_RIGHT://오른쪽방향
	{
		break;
	}
	case VK_UP://위쪽방향
	{
		break;
	}
	case VK_DOWN://아래쪽방향
	{
		break;
	}
	/*
	case MK_CONTROL + 0x43:
	{
		break;
	}
	case 0x56:
	{
		break;
	}
	*/
	//0x56
	default:
		break;
	}
}
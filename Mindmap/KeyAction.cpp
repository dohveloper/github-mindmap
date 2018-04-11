//KeyAction.cpp

#include "KeyAction.h"
#include "Keyboard.h"
#include "PageForm.h"
#include "DeleteKey.h"
#include "ArrangeKey.h"
#include "SearchKey.h"
#include "ReplaceKey.h"

KeyAction::KeyAction()
{
}

KeyAction::~KeyAction()
{
}

void KeyAction::KeyPress(PageForm *pageForm, UINT nChar)
{
	switch (nChar)
	{
	case VK_DELETE:
	{
		DeleteKey deleteKey;
		deleteKey.KeyDown(pageForm);
		break;
	}
	case 0x41://A키 정렬
	{
		ArrangeKey arrangeKey;
		arrangeKey.KeyDown(pageForm);
		break;
	}
	case 0x53://S키 찾기
	{
		SearchKey searchKey;
		searchKey.KeyDown(pageForm);
		break;
	}

	case 0x52://R키 바꾸기
	{
		ReplaceKey replaceKey;
		replaceKey.KeyDown(pageForm);
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

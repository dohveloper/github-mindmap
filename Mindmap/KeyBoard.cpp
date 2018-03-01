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
	case VK_RETURN://����
	{
		break;
	}
	case VK_SPACE://�����̽�
	{
		break;
	}
	case VK_ESCAPE://ESC
	{
		break;
	}
	case VK_TAB://��
	{
		break;
	}
	case VK_BACK://�齺���̽�
	{
		break;
	}
	case VK_LEFT://���ʹ���
	{
		break;
	}
	case VK_RIGHT://�����ʹ���
	{
		break;
	}
	case VK_UP://���ʹ���
	{
		break;
	}
	case VK_DOWN://�Ʒ��ʹ���
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
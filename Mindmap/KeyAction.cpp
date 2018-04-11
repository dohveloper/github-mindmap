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
	case 0x41://AŰ ����
	{
		ArrangeKey arrangeKey;
		arrangeKey.KeyDown(pageForm);
		break;
	}
	case 0x53://SŰ ã��
	{
		SearchKey searchKey;
		searchKey.KeyDown(pageForm);
		break;
	}

	case 0x52://RŰ �ٲٱ�
	{
		ReplaceKey replaceKey;
		replaceKey.KeyDown(pageForm);
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

//Keyboard.h

#ifndef _KEYBOARD_H
#define _KEYBOARD_H
#include <afxwin.h>

class PageForm;
class KeyAction;
class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	void KeyDown(PageForm *pageForm, UINT nChar, UINT nRepCnt, UINT nFlags);

};


#endif // !KEYBOARD_H

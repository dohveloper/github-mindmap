//Keyboard.h

#ifndef _KEYBOARD_H
#define _KEYBOARD_H
#include <afxwin.h>

class PageForm;
class Keyboard
{
public:
	Keyboard();
	virtual ~Keyboard() = 0;
	void KeyDown(PageForm *pageForm);

};

#endif // KEYBOARD_H

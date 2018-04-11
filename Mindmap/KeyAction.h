//KeyAction.h

#ifndef _KEYACTION_H
#define _KEYACTION_H
#include <afxwin.h>

class PageForm;
class KeyAction
{
public:
	KeyAction();
	~KeyAction();
	void KeyPress(PageForm *pageForm, UINT nChar);

};

#endif // _KEYACTION_H

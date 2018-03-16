//PasteKey.h

#ifndef _PASTEKEY_H
#define _PASTEKEY_H
#include "KeyAction.h"

class PageForm;
class PasteKey :public KeyAction
{
public:
	PasteKey();
	virtual ~PasteKey();
	void KeyPress(PageForm *pageForm);
};

#endif // _PASTEKEY_H

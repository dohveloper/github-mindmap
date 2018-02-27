//DeleteKey.h

#ifndef _DELETEKEY_H
#define _DELETEKEY_H
#include "KeyAction.h"

class PageForm;
class DeleteKey :public KeyAction
{
public:
	DeleteKey();
	virtual ~DeleteKey();
	void KeyPress(PageForm *pageForm);
};

#endif // _DELETEKEY_H

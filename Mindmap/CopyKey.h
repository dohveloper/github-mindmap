//CopyKey.h

#ifndef _COPYKEY_H
#define _COPYKEY_H
#include "KeyAction.h"

class PageForm;
class CopyKey :public KeyAction
{
public:
	CopyKey();
	virtual ~CopyKey();
	void KeyPress(PageForm *pageForm);
};

#endif // _COPYKEY_H

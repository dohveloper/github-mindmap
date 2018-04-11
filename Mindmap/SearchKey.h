//SearchKey.h

#ifndef _SEARCHKEY_H
#define _SEARCHKEY_H
//#include "KeyAction.h"

class PageForm;
class SearchKey //:public KeyAction
{
public:
	SearchKey();
	virtual ~SearchKey();
	void KeyPress(PageForm *pageForm);
};

#endif // _SEARCHKEY_H

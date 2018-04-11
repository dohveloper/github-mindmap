//SearchKey.h

#ifndef _SEARCHKEY_H
#define _SEARCHKEY_H
#include "KeyBoard.h"

class PageForm;
class SearchKey : public Keyboard 
{
public:
	SearchKey();
	virtual ~SearchKey();
	void KeyDown(PageForm *pageForm);
};

#endif // SEARCHKEY_H

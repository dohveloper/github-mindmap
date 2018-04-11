//ReplaceKey.h

#ifndef _REPLACEKEY_H
#define _REPLACEKEY_H
#include "KeyBoard.h"

class PageForm;
class ReplaceKey : public Keyboard
{
public:
	ReplaceKey();
	virtual ~ReplaceKey();
	void KeyDown(PageForm *pageForm);
};

#endif // REPLACEKEY_H

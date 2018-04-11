//ArrangeKey.h

#ifndef _ARRANGEKEY_H
#define _ARRANGEKEY_H
#include "KeyBoard.h"

class PageForm;
class ArrangeKey : public Keyboard {
public:
	ArrangeKey();
	virtual ~ArrangeKey();
	void KeyDown(PageForm *pageForm);

};

#endif // _ARRANGEKEY_H

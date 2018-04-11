//DeleteKey.h

#ifndef _DELETEKEY_H
#define _DELETEKEY_H
#include "KeyBoard.h"

class PageForm;
class DeleteKey : public Keyboard {
public:
	DeleteKey();
	virtual ~DeleteKey();
	void KeyDown(PageForm *pageForm);

};

#endif // _DELETEKEY_H

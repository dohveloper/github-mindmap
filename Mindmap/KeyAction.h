//KeyAction.h

#ifndef _KEYACTION_H
#define _KEYACTION_H

class PageForm;
class KeyAction
{
public:
	KeyAction();
	virtual ~KeyAction() = 0;
	void KeyPress(PageForm *pageForm);

private:

};

#endif // _KEYACTION_H
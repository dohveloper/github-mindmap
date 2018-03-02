//MultiLineDragAction.h

#ifndef _MULTILINEDRAGACTION_H
#define _MULTILINEDRAGACTION_H

#include "afxwin.h"

class TextForm;
class MultiLineDragAction {
public:
	MultiLineDragAction();
	~MultiLineDragAction();

	void DragUp(TextForm *textForm, CDC *cdc);
	void DragDown(TextForm *textForm, CDC *cdc);
};

#endif //_MULTILINEDRAGACTION_H
//DoubleLineDragAction.h

#ifndef _DOUBLELINEDRAGACTION_H
#define _DOUBLELINEDRAGACTION_H

#include "afxwin.h"

class TextForm;
class DoubleLineDragAction {
public:
	DoubleLineDragAction();
	~DoubleLineDragAction();

	void DragUp(TextForm *textForm, CDC *cdc);
	void DragDown(TextForm *textForm, CDC *cdc);
};

#endif //_DOUBLELINEDRAGACTION_H
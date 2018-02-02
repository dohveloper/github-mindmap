//SingleLineDragAction.h

#ifndef _SINGLELINEDRAGACTION_H
#define _SINGLELINEDRAGACTION_H

#include "afxwin.h"

class TextForm;
class SingleLineDragAction {
public:
	SingleLineDragAction();
	~SingleLineDragAction();

	void DragLeft(TextForm *textForm, CDC *cdc);
	void DragRight(TextForm *textForm, CDC *cdc);
};
#endif //_SINGLELINEDRAGACTION_H
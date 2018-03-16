//TextDoubleClickSelectAction.h

#ifndef _TEXTDOUBLECLICKSELECTACTION_H
#define _TEXTDOUBLECLICKSELECTACTION_H

#include "afxwin.h"
#include "TextForm.h"

class TextForm;
class TextDoubleClickSelectAction
{
public:
	TextDoubleClickSelectAction();
	~TextDoubleClickSelectAction();

	void AllSelect(TextForm *textForm, CDC *cdc, Long width);

};

#endif //_TEXTDOUBLECLICKSELECTACTION_H

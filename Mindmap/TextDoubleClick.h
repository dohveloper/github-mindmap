//TextDoubleClick.h

#ifndef _TEXTDOUBLECLICK_H
#define _TEXTDOUBLECLICK_H

#include "afxwin.h"



class TextForm;
class TextDoubleClick
{
public:
	TextDoubleClick();
	~TextDoubleClick();

	void TextDoubleClickSelect(TextForm *textForm, CDC *cdc);

};

#endif //TextDoubleClick_H

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
	Long CheckStartCharacterIndex(TextForm *textForm);
	Long CheckEndCharacterIndex(TextForm *textForm);

};

#endif //TextDoubleClick_H

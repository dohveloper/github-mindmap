//TextFormWidthSizeAction.h

#ifndef _TEXTFORMWIDTHSIZEACTION_H
#define _TEXTFORMWIDTHSIZEACTION_H

#include "afxwin.h"
typedef signed long int Long;


class TextForm;
class TextFormWidthSizeAction
{
public:
	TextFormWidthSizeAction();
	~TextFormWidthSizeAction();

	void TextFormWidthLong(TextForm *textForm, CDC *cdc);
	void TextFormWidthShort(TextForm *textForm, CDC *cdc);


};
#endif //_TEXTFORMWIDTHSIZEACTION_H

//TextFormHeightSizeAction.h

#ifndef _TEXTFORMHEIGHTSIZEACTION_H
#define _TEXTFORMHEIGHTSIZEACTION_H

#include "afxwin.h"
typedef signed long int Long;


class TextForm;
class TextFormHeightSizeAction
{
public:
	TextFormHeightSizeAction();
	~TextFormHeightSizeAction();

	void TextFormHeightLong(TextForm *textForm, CDC *cdc);
	void TextFormHeightShort(TextForm *textForm, CDC *cdc);


};
#endif //_TEXTFORMHEIGHTSIZEACTION_H


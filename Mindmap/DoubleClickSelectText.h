//DoubleClickSelectText.h

#ifndef _DOUBLECLICKSELECTTEXT_H
#define _DOUBLECLICKSELECTTEXT_H

#include "afxwin.h"
#include "TextForm.h"

class TextForm;
class DoubleClickSelectText
{
public:
	DoubleClickSelectText();
	~DoubleClickSelectText();

	void AllSelect(TextForm *textForm, CDC *cdc, Long width);

};

#endif //DOUBLECLICKSELECTTEXT_H

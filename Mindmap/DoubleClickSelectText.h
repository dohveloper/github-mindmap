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
	DoubleClickSelectText(Long width);
	DoubleClickSelectText(const DoubleClickSelectText& source);
	~DoubleClickSelectText();

	Long CheckStartCharacterIndex(TextForm *textForm, CDC *cdc);
	Long CheckEndCharacterIndex(TextForm *textForm);
	void AllSelect(TextForm *textForm, CDC *cdc);

	DoubleClickSelectText& operator=(const DoubleClickSelectText& soucre);

private:
	Long width;
};

#endif //DOUBLECLICKSELECTTEXT_H

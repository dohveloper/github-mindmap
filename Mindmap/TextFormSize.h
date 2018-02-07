//TextFormSize.h

#ifndef _TEXTFORMSIZE_H
#define _TEXTFORMSIZE_H

#include "afxwin.h"
typedef signed long int Long;


class TextForm;
class TextFormSize
{
public:
	TextFormSize();
	~TextFormSize();
	void TextFormWidthSize(TextForm *textForm, CDC *cdc);
	void TextFormHeightSize(TextForm *textForm);

};

#endif //TEXTFORMSIZE_H#pragma once

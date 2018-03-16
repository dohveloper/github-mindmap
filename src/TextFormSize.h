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
	TextFormSize(Long x, Long y, Long width, Long height);
	TextFormSize(const TextFormSize& source);
	~TextFormSize();

	void TextFormWidthSize(TextForm *textForm, CDC *cdc);
	void TextFormHeightSize(TextForm *textForm, CDC *cdc);

	Long SetX(Long index);
	Long SetY(Long index);
	Long SetWidth(Long index);
	Long SetHeight(Long index);

	TextFormSize& operator=(const TextFormSize& source);

private:
	Long x;
	Long y;
	Long width;
	Long height;
};

#endif //TEXTFORMSIZE_H#pragma once

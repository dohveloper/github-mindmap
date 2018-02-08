//TextFormSize.cpp

#include "TextFormSize.h"
#include "TextForm.h"
#include "PageForm.h"
#include "Caret.h"
#include "Text.h"
#include "TextFont.h"
#include <string>
using namespace std;

TextFormSize::TextFormSize()
{
}

TextFormSize::TextFormSize(Long x, Long y, Long width, Long height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

TextFormSize::TextFormSize(const TextFormSize& source)
{
	this->x = source.x;
	this->y = source.y;
	this->width = source.width;
	this->width = source.height;
}

TextFormSize::~TextFormSize()
{
}

void TextFormSize::TextFormWidthSize(TextForm *textForm, CDC *cdc)
{
	Row* row;
	string word;
	Long length;
	Long width;
	Long textFormX;
	Long textFormY;
	Long textFormWidth;
	Long textFormHeight;
	Long caretIndex;
	Long wordWidth;
	CFont fnt;

	fnt.CreateFont(textForm->textFont->GetHeight(), textForm->textFont->GetWidth(), 0, 0, textForm->textFont->GetWeight(), textForm->textFont->GetItalic(), textForm->textFont->GetUnderline(), textForm->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T(textForm->textFont->GetLpszFacename()));

	cdc->SelectObject(&fnt);


	row = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());
	length = row->GetLength();
	width = row->GetRowWidth(cdc, 0,length);

	caretIndex = textForm->caret->GetCharacterIndex();

	word = row->GetAt(caretIndex)->MakeString();
	wordWidth = cdc->GetTextExtent((CString)word.c_str()).cx;

	textFormX = this->x;
	textFormY = this->y;
	textFormWidth = this->width;
	textFormHeight = this->height;


	if (width*1.06 > textFormWidth && wordWidth == 17)
	{
		textForm->MoveWindow(textFormX, textFormY, textFormWidth+18.07 , textFormHeight);
	}

	else if (width*1.01 > textFormWidth && wordWidth == 33)
	{
		textForm->MoveWindow(textFormX, textFormY, textFormWidth + 34.02, textFormHeight);
	}
	fnt.DeleteObject();
}

void TextFormSize::TextFormHeightSize(TextForm *textForm)
{

}

Long TextFormSize::SetX(Long index)
{
	this->x = index;

	return this->x;
}

Long TextFormSize::SetY(Long index)
{
	this->y = index;

	return this->y;
}

Long TextFormSize::SetWidth(Long index)
{
	this->width = index;

	return this->width;
}

Long TextFormSize::SetHeight(Long index)
{
	this->height = index;

	return this->height;
}

TextFormSize& TextFormSize::operator=(const TextFormSize& source)
{
	this->x = source.x;
	this->y = source.y;
	this->width = source.width;
	this->width = source.height;

	return *this;
}





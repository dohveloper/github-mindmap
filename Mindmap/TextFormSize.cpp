//TextFormSize.cpp

#include "TextFormSize.h"
#include "TextForm.h"
#include "PageForm.h"
#include "SelectText.h"
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
	CFont fnt;
	Long maxWidthSize = 600;
	fnt.CreateFont(textForm->textFont->GetHeight(), textForm->textFont->GetWidth(), 0, 0, textForm->textFont->GetWeight(), textForm->textFont->GetItalic(), textForm->textFont->GetUnderline(), textForm->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, textForm->textFont->GetLpszFacename());
	cdc->SelectObject(&fnt);

	row = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());
	length = row->GetLength();
	width = row->GetRowWidth(cdc, 0,length)+3;

	textFormX = this->x;
	textFormY = this->y;
	textFormWidth = this->width;
	textFormHeight = this->height;

	if (width > textFormWidth && width < maxWidthSize)
	{
		textFormWidth = width;
		textForm->MoveWindow(textFormX, textFormY, textFormWidth+6, textFormHeight);

	}
	
	this->width = textFormWidth;
	
	fnt.DeleteObject();
}

void TextFormSize::TextFormHeightSize(TextForm *textForm, CDC *cdc)
{
	Long height;
	Long textFormX;
	Long textFormY;
	Long textFormWidth;
	Long textFormHeight;
	Long rowHeight;
	CFont fnt;
	Long addTextFormHeight;

	Long textWindowRato = 1.1;

	Long maxHeightSize = 600;

	fnt.CreateFont(textForm->textFont->GetHeight(), textForm->textFont->GetWidth(), 0, 0, textForm->textFont->GetWeight(), textForm->textFont->GetItalic(), textForm->textFont->GetUnderline(), textForm->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, textForm->textFont->GetLpszFacename());
	cdc->SelectObject(&fnt);
	

	height = textForm->textFont->GetHeight();
	rowHeight = textForm->text->GetLength()*height;
	
	textFormX = this->x;
	textFormY = this->y;
	textFormWidth = this->width;
	textFormHeight = this->height;
	

	if (rowHeight*textWindowRato > textFormHeight && rowHeight*textWindowRato<maxHeightSize)
	{
		addTextFormHeight = height * textWindowRato;
		textFormHeight += addTextFormHeight;
		textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
	}
	this->height = textFormHeight;

	fnt.DeleteObject();
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





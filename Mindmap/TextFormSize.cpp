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
	Long caretIndex;
	Long wordWidth;
	CFont fnt;
	Long addTextFormWidth;
	Long textWindowRato = 1.07;
	Long maxWidthSize = 600;
	fnt.CreateFont(30, 16, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("����ü"));

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

	if (width*textWindowRato > textFormWidth &&width*textWindowRato < maxWidthSize)
	{
		addTextFormWidth = wordWidth*textWindowRato;
		textFormWidth += addTextFormWidth;
		textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
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
	fnt.CreateFont(30, 16, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("����ü"));
	cdc->SelectObject(&fnt);
	

	height = textForm->fontHeight;
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





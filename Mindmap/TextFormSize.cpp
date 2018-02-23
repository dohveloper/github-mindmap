//TextFormSize.cpp

#include "TextFormSize.h"
#include "TextFormWidthSizeAction.h"
#include "TextFormHeightSizeAction.h"
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

void TextFormSize::TextFormWidthSizeLong(TextForm *textForm, CDC *cdc)
{
	TextFormWidthSizeAction textFormWidthSizeAction;
	textFormWidthSizeAction.TextFormWidthLong(textForm, cdc);
	
}

void TextFormSize::TextFormWidthSizeShort(TextForm *textForm, CDC *cdc)
{
	TextFormWidthSizeAction textFormWidthSizeAction;
	textFormWidthSizeAction.TextFormWidthShort(textForm, cdc);

}

void TextFormSize::TextFormHeightSizeLong(TextForm *textForm, CDC *cdc)
{
	TextFormHeightSizeAction textFormHeightSizeAction;
	textFormHeightSizeAction.TextFormHeightLong(textForm, cdc);
}

void TextFormSize::TextFormHeightSizeShort(TextForm *textForm, CDC *cdc)
{
	TextFormHeightSizeAction textFormHeightSizeAction;
	textFormHeightSizeAction.TextFormHeightShort(textForm, cdc);
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
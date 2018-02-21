//TextFormWidthSizeAction.cpp

#include "TextFormSize.h"
#include "TextFormWidthSizeAction.h"
#include "SelectText.h"
#include "TextForm.h"
#include "PageForm.h"
#include "Caret.h"
#include "Text.h"
#include "TextFont.h"
#include <string>
using namespace std;

TextFormWidthSizeAction::TextFormWidthSizeAction()
{
}

TextFormWidthSizeAction::~TextFormWidthSizeAction()
{
}

void TextFormWidthSizeAction::TextFormWidthLong(TextForm *textForm, CDC *cdc)
{
	Row* row;
	Long length;
	Long width;
	Long textFormX;
	Long textFormY;
	Long textFormWidth;
	Long textFormHeight;
	Long maxWidthSize = 600;
	CFont fnt;
	fnt.CreateFont(textForm->textFont->GetHeight(), textForm->textFont->GetWidth(), 0, 0, textForm->textFont->GetWeight(), textForm->textFont->GetItalic(), textForm->textFont->GetUnderline(), textForm->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, textForm->textFont->GetLpszFacename());
	cdc->SelectObject(&fnt);

	row = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());
	length = row->GetLength();
	width = row->GetRowWidth(cdc, 0, length);

	textFormX = textForm->textFormSize->GetX();
	textFormY = textForm->textFormSize->GetY();
	textFormWidth = textForm->textFormSize->GetWidth();
	textFormHeight = textForm->textFormSize->GetHeight();

	if (width > textFormWidth && width < maxWidthSize)
	{
		textFormWidth = width+6;
		textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
		textForm->textFormSize->SetWidth(textFormWidth);
	}
	fnt.DeleteObject();
}


void TextFormWidthSizeAction::TextFormWidthShort(TextForm *textForm, CDC *cdc)
{
	Row* row;
	Long length;
	Long width;
	Long rightDirectionSelectWidth;
	Long leftDirectionSelectWidth;
	Long textFormX;
	Long textFormY;
	Long textFormWidth;
	Long textFormHeight;
	Long minWidthSize= 200;
	CFont fnt;
	fnt.CreateFont(textForm->textFont->GetHeight(), textForm->textFont->GetWidth(), 0, 0, textForm->textFont->GetWeight(), textForm->textFont->GetItalic(), textForm->textFont->GetUnderline(), textForm->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, textForm->textFont->GetLpszFacename());
	cdc->SelectObject(&fnt);

	row = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());
	length = row->GetLength();
	width = row->GetRowWidth(cdc, 0, length);
	//rightDirectionSelectWidth = row->GetRowWidth(cdc, );
	//leftDirectionSelectWidth

	textFormX = textForm->textFormSize->GetX();
	textFormY = textForm->textFormSize->GetY();
	textFormWidth = textForm->textFormSize->GetWidth();
	textFormHeight = textForm->textFormSize->GetHeight();


	if (width < textFormWidth && width > minWidthSize)
	{
		textFormWidth = width+6;
		textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
		textForm->textFormSize->SetWidth(textFormWidth);
	}
	fnt.DeleteObject();
}

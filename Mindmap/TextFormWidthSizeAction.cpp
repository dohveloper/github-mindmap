//TextFormWidthSizeAction.cpp

#include "TextFormSize.h"
#include "TextFormWidthSizeAction.h"
#include "SelectText.h"
#include "TextForm.h"
#include "PageForm.h"
#include "Caret.h"
#include "Text.h"
#include "TextFont.h"
#include "WordWrap.h"
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
	Row* row1;
	Row* row2;
	Long length1;
	Long length2;
	Long width1;
	Long width2;
	Long textFormX;
	Long textFormY;
	Long textFormWidth;
	Long textFormHeight;
	Long textLength;
	Long i=0;
	Long j=1;
	Long maxWidthSize = 600;
	CFont fnt;
	fnt.CreateFont(textForm->textFont->GetHeight(), textForm->textFont->GetWidth(), 0, 0, textForm->textFont->GetWeight(), textForm->textFont->GetItalic(), textForm->textFont->GetUnderline(), textForm->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, textForm->textFont->GetLpszFacename());
	cdc->SelectObject(&fnt);

	textFormX = textForm->textFormSize->GetX();
	textFormY = textForm->textFormSize->GetY();
	textFormWidth = textForm->textFormSize->GetWidth();
	textFormHeight = textForm->textFormSize->GetHeight();
	textLength = textForm->text->GetLength();


	if (textLength >= 2)
	{
		row1 = (Row*)textForm->text->GetAt(i);
		length1 = row1->GetLength();
		width1 = row1->GetRowWidth(cdc, 0, length1);
		while (j < textLength)
		{
			row2 = (Row*)textForm->text->GetAt(j);
			length2 = row2->GetLength();
			width2 = row2->GetRowWidth(cdc, 0, length2);

			if (width1 < width2)
			{
				width1 = width2;
			}
			j++;
		}

		if (width1 > textFormWidth && width1 <= maxWidthSize)
		{
			textFormWidth = width1 + 6;
			textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
			textForm->textFormSize->SetWidth(textFormWidth);
		}
		else if (width1 > textFormWidth && width1 > maxWidthSize)
		{
			textFormWidth = maxWidthSize+6;
			textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
			textForm->textFormSize->SetWidth(textFormWidth);
		}
		
	}
	else
	{
		row1 = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());
		length1 = row1->GetLength();
		width1 = row1->GetRowWidth(cdc, 0, length1);


		if (width1 > textFormWidth && width1 <= maxWidthSize)
		{
			textFormWidth = width1 + 6;
			textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
			textForm->textFormSize->SetWidth(textFormWidth);
		}
		else if (width1 > textFormWidth && width1 > maxWidthSize)
		{
			textFormWidth = maxWidthSize + 6;
			textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
			textForm->textFormSize->SetWidth(textFormWidth);
		}
	}
	
	if (width1 > maxWidthSize)
	{
		WordWrap wordWrap;

		wordWrap.Writing(textForm,cdc);
	}
	fnt.DeleteObject();
}


void TextFormWidthSizeAction::TextFormWidthShort(TextForm *textForm, CDC *cdc)
{
	Row* row1;
	Row* row2;
	Long length1;
	Long length2;
	Long width1;
	Long width2;
	Long textLength;
	Long rightDirectionSelectWidth;
	Long leftDirectionSelectWidth;
	Long textFormX;
	Long textFormY;
	Long textFormWidth;
	Long textFormHeight;
	Long i = 0;
	Long j = 1;
	Long minWidthSize= 200;
	CFont fnt;
	fnt.CreateFont(textForm->textFont->GetHeight(), textForm->textFont->GetWidth(), 0, 0, textForm->textFont->GetWeight(), textForm->textFont->GetItalic(), textForm->textFont->GetUnderline(), textForm->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, textForm->textFont->GetLpszFacename());
	cdc->SelectObject(&fnt);


	//rightDirectionSelectWidth = row->GetRowWidth(cdc, );
	//leftDirectionSelectWidth

	textFormX = textForm->textFormSize->GetX();
	textFormY = textForm->textFormSize->GetY();
	textFormWidth = textForm->textFormSize->GetWidth();
	textFormHeight = textForm->textFormSize->GetHeight();
	textLength = textForm->text->GetLength();

	if (textLength >= 2)
	{
		row1 = (Row*)textForm->text->GetAt(i);
		length1 = row1->GetLength();
		width1 = row1->GetRowWidth(cdc, 0, length1);
		while (j < textLength)
		{
			row2 = (Row*)textForm->text->GetAt(j);
			length2 = row2->GetLength();
			width2 = row2->GetRowWidth(cdc, 0, length2);

			if (width1 < width2)
			{
				width1 = width2;
			}
			j++;
		}

		if (width1 < textFormWidth && width1 >= minWidthSize)
		{
			textFormWidth = width1 + 6;
			textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
			textForm->textFormSize->SetWidth(textFormWidth);
		}
		else if (width1 > textFormWidth && width1 < minWidthSize)
		{
			textFormWidth = minWidthSize + 6;
			textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
			textForm->textFormSize->SetWidth(textFormWidth);
		}

	}
	else
	{
		row1 = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());
		length1 = row1->GetLength();
		width1 = row1->GetRowWidth(cdc, 0, length1);


		if (width1 < textFormWidth && width1 >= minWidthSize)
		{
			textFormWidth = width1 + 6;
			textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
			textForm->textFormSize->SetWidth(textFormWidth);
		}
		else if (width1 > textFormWidth && width1 < minWidthSize)
		{
			textFormWidth = minWidthSize + 6;
			textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
			textForm->textFormSize->SetWidth(textFormWidth);
		}
	}

	fnt.DeleteObject();
}

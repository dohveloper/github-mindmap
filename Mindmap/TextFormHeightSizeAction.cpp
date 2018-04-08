//TextFormHeightSizeAction.cpp

#include "TextFormSize.h"
#include "TextFormHeightSizeAction.h"
#include "TextForm.h"
#include "PageForm.h"
#include "Caret.h"
#include "Text.h"
#include "TextFont.h"
#include <string>
using namespace std;

TextFormHeightSizeAction::TextFormHeightSizeAction()
{
}

TextFormHeightSizeAction::~TextFormHeightSizeAction()
{
}

void TextFormHeightSizeAction::TextFormHeightLong(TextForm *textForm, CDC *cdc)
{
	Long deleteLength;
	Long rowLength;
	Long rowHeight;
	Long textFormX;
	Long textFormY;
	Long textFormWidth;
	Long textFormHeight;
	Long maxHeightSize = 300;
	CFont fnt;
	fnt.CreateFont(textForm->textFont->GetHeight(), textForm->textFont->GetWidth(), 0, 0, textForm->textFont->GetWeight(), textForm->textFont->GetItalic(), textForm->textFont->GetUnderline(), textForm->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, textForm->textFont->GetLpszFacename());
	cdc->SelectObject(&fnt);

	rowLength = textForm->text->GetLength();
	rowHeight = rowLength * textForm->textFont->GetHeight();

	textFormX = textForm->textFormSize->GetX();
	textFormY = textForm->textFormSize->GetY();
	textFormWidth = textForm->textFormSize->GetWidth();
	textFormHeight = textForm->textFormSize->GetHeight();

	if (rowHeight > textFormHeight && rowHeight< maxHeightSize)
	{
		textFormHeight = rowHeight+6;
		textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
		textForm->textFormSize->SetHeight(textFormHeight);
	}
	else if (rowHeight > textFormHeight && rowHeight>= maxHeightSize)
	{
		if (rowLength > 10)
		{
			deleteLength = rowLength - 1;
			while (rowLength != 10)
			{
				textForm->text->Delete(deleteLength);
				deleteLength--;
				rowLength--;
			}
		}
		textFormHeight = maxHeightSize + 6;
		textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
		textForm->textFormSize->SetHeight(textFormHeight);
	}
	fnt.DeleteObject();
}


void TextFormHeightSizeAction::TextFormHeightShort(TextForm *textForm, CDC *cdc)
{
	Long rowLength;
	Long rowHeight;
	Long textFormX;
	Long textFormY;
	Long textFormWidth;
	Long textFormHeight;
	Long minHeightSize = 200;
	CFont fnt;
	fnt.CreateFont(textForm->textFont->GetHeight(), textForm->textFont->GetWidth(), 0, 0, textForm->textFont->GetWeight(), textForm->textFont->GetItalic(), textForm->textFont->GetUnderline(), textForm->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, textForm->textFont->GetLpszFacename());
	cdc->SelectObject(&fnt);

	rowLength = textForm->text->GetLength();
	rowHeight = rowLength * textForm->textFont->GetHeight();

	textFormX = textForm->textFormSize->GetX();
	textFormY = textForm->textFormSize->GetY();
	textFormWidth = textForm->textFormSize->GetWidth();
	textFormHeight = textForm->textFormSize->GetHeight();

	if ( rowHeight < textFormHeight &&rowHeight > minHeightSize )
	{
		textFormHeight = rowHeight+6;
		textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
		textForm->textFormSize->SetHeight(textFormHeight);
	}
	else if (rowHeight < textFormHeight &&rowHeight <= minHeightSize)
	{
		textFormHeight = minHeightSize + 6;
		textForm->MoveWindow(textFormX, textFormY, textFormWidth, textFormHeight);
		textForm->textFormSize->SetHeight(textFormHeight);
	}
	fnt.DeleteObject();
}
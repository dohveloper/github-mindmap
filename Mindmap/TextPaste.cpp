//TextPaste.cpp

#include "TextPaste.h"
#include "TextForm.h"
#include "Text.h"
#include "textClipboard.h"
#include "caret.h"


TextPaste::TextPaste()
{
}

TextPaste::~TextPaste()
{
}

void TextPaste::Paste(TextForm *textForm)
{
	Long rowLength;
	Long textLength;
	Long caretRowIndex;
	Long caretIndex;
	Long i = 0;
	Long j = 0;
	Long nextCaretRowIndex;
	Long nextCaretIndex;
	Long currentCaretIndex;

	rowLength = textForm->textClipboard->GetLength();
	caretRowIndex = textForm->caret->GetRowIndex();
	caretIndex = textForm->caret->GetCharacterIndex();
	currentCaretIndex = caretIndex;


	if (rowLength == 1)
	{
		textLength = textForm->textClipboard->GetAt(i)->GetLength();
		if (caretIndex == 0)
		{
			while (j < textLength)
			{
				textForm->text->GetAt(caretRowIndex)->Write(textForm->textClipboard->GetAt(i)->GetAt(j)->Clone());
				j++;
			}
		}
		else
		{
			while (j < textLength)
			{
				textForm->text->GetAt(caretRowIndex)->Insert(caretIndex,textForm->textClipboard->GetAt(i)->GetAt(j)->Clone());
				j++;
				caretIndex++;
			}
		}
	}
	else
	{
		textLength = textForm->textClipboard->GetAt(i)->GetLength();
		if(caretIndex == 0)
		{
			while (j < textLength)
			{
				textForm->text->GetAt(caretRowIndex)->Write(textForm->textClipboard->GetAt(i)->GetAt(j)->Clone());
				j++;
			}
		}
		else
		{
			while (j < textLength)
			{
				textForm->text->GetAt(caretRowIndex)->Insert(caretIndex, textForm->textClipboard->GetAt(i)->GetAt(j)->Clone());
				j++;
				caretIndex++;
			}
		}

		i++;

		while (i < rowLength-1)
		{
			textForm->text->Write((Row*)(textForm->textClipboard->GetAt(i))->Clone());
			i++;
		}

		textForm->text->Write((Row*)(textForm->textClipboard->GetAt(i))->Clone());

	}
	//이 밑에부턴 붙여넣기 한 후 캐럿의 위치 이동
	nextCaretRowIndex = textForm->text->GetLength()-1;
	nextCaretIndex = currentCaretIndex + textForm->textClipboard->GetAt(textForm->textClipboard->GetLength()-1)->GetLength();
	
	if (caretRowIndex == nextCaretRowIndex)
	{
		
		if(currentCaretIndex == nextCaretIndex)
		{

			textForm->caret->MoveToRight(0);
		}
		else if (currentCaretIndex < nextCaretIndex)
		{
			textForm->caret->MoveToRight(nextCaretIndex- currentCaretIndex);
		}
		else if (currentCaretIndex > nextCaretIndex)
		{
			textForm->caret->MoveToLeft(currentCaretIndex - nextCaretIndex);
		}
	}
	else if (caretRowIndex < nextCaretRowIndex)
	{
		textForm->caret->MoveToDown(nextCaretRowIndex - caretRowIndex);
		
		if (currentCaretIndex == nextCaretIndex)
		{
			textForm->caret->MoveToRight(0);
		}
		else if (currentCaretIndex < nextCaretIndex)
		{
			textForm->caret->MoveToRight(nextCaretIndex - currentCaretIndex);
		}
		else if (currentCaretIndex > nextCaretIndex)
		{
			textForm->caret->MoveToLeft(currentCaretIndex - nextCaretIndex);
		}
	}
	else if (caretRowIndex > nextCaretRowIndex)
	{
		textForm->caret->MoveToUp(caretRowIndex - nextCaretRowIndex);

		if (currentCaretIndex == nextCaretIndex)
		{
			textForm->caret->MoveToRight(0);
		}
		else if (currentCaretIndex < nextCaretIndex)
		{
			textForm->caret->MoveToRight(nextCaretIndex - currentCaretIndex);
		}
		else if (currentCaretIndex > nextCaretIndex)
		{
			textForm->caret->MoveToLeft(currentCaretIndex - nextCaretIndex);
		}

	}

}
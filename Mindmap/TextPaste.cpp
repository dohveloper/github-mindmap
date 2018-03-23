//TextPaste.cpp

#include "TextPaste.h"
#include "TextForm.h"
#include "Text.h"
#include "textClipboard.h"
#include "caret.h"


TextPaste::TextPaste()
{
	this->startTextRowLength = 0;
	this->caretRowIndexSave = 0;
	this->startCaretIndex = 0;
	this->startPasteTextLength = 0;
	this->isWrite = false;
}

TextPaste::TextPaste(const TextPaste& source)
{
	this->startTextRowLength = source.startTextRowLength;
	this->caretRowIndexSave = source.caretRowIndexSave;
	this->startCaretIndex = source.startCaretIndex;
	this->startPasteTextLength = source.startPasteTextLength;
	this->isWrite = source.isWrite;
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
	Long k = 0;
	Long currentCaretIndex;
	Long pasteIndex;
	Long cloneIndex;
	Long textRowLastIndex;
	Long cloneCaretIndex;
	Long deleteIndex;
	Long deleteTextLength;
	Long LastCaretIndex;

	rowLength = textForm->textClipboard->GetLength();
	caretRowIndex = textForm->caret->GetRowIndex();
	caretIndex = textForm->caret->GetCharacterIndex();
	currentCaretIndex = caretIndex;
	this->startPasteTextLength =textForm->text->GetAt(caretRowIndex)->GetLength();
	LastCaretIndex = textForm->text->GetAt(caretRowIndex)->GetLength() - 1;
	textRowLastIndex = textForm->text->GetLength() - 1;
	this->startTextRowLength = textForm->text->GetLength();
	cloneCaretIndex = caretRowIndex;
	this->caretRowIndexSave = caretRowIndex;
	this->startCaretIndex = caretIndex;

	if (textForm->textClipboard->GetLength() != 0)
	{

		if (rowLength == 1) //한줄붙여넣기
		{
			textLength = textForm->textClipboard->GetAt(i)->GetLength();

			if (caretIndex > textForm->text->GetAt(caretRowIndex)->GetLength()-1)
			{
				this->isWrite = true;
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
	
		}
		else //여러줄(Row)붙여넣기
		{
			textLength = textForm->textClipboard->GetAt(i)->GetLength();

			if (caretIndex > textForm->text->GetAt(caretRowIndex)->GetLength() - 1)//여러줄(Row)붙여넣기인데 라이트일때
			{
				this->isWrite = true;
				while (j < textLength)
				{
					textForm->text->GetAt(caretRowIndex)->Write(textForm->textClipboard->GetAt(i)->GetAt(j)->Clone());
					j++;
				}
				i++;

				if (caretRowIndex == textRowLastIndex)
				{
					while (i < rowLength )
					{
						textForm->text->Write((Row*)(textForm->textClipboard->GetAt(i))->Clone());
						i++;
					}
				}
				else
				{
					
					caretRowIndex++;

					while (i < rowLength)
					{

						textForm->text->Insert(caretRowIndex,(Row*)(textForm->textClipboard->GetAt(i))->Clone());
						i++;
						caretRowIndex++;
					}
				}
			}
			else//여러줄(Row)붙여넣기인데 인설트일때
			{
				while (j < textLength)
				{
					textForm->text->GetAt(caretRowIndex)->Insert(caretIndex, textForm->textClipboard->GetAt(i)->GetAt(j)->Clone());
					j++;
					caretIndex++;
				}
				i++;

				if (caretRowIndex == textRowLastIndex)
				{
					while (i < rowLength)
					{
						textForm->text->Write((Row*)(textForm->textClipboard->GetAt(i))->Clone());
						i++;
					}
				}
				else
				{
					caretRowIndex++;

					while (i < rowLength)
					{

						textForm->text->Insert(caretRowIndex, (Row*)(textForm->textClipboard->GetAt(i))->Clone());
						i++;
						caretRowIndex++;
					}
				}
				
				cloneIndex = currentCaretIndex + textForm->textClipboard->GetAt(0)->GetLength();
				deleteIndex = cloneIndex;
				pasteIndex = cloneCaretIndex + textForm->textClipboard->GetLength() - 1;

				while (cloneIndex < textForm->text->GetAt(cloneCaretIndex)->GetLength())
				{
					textForm->text->GetAt(pasteIndex)->Write(textForm->text->GetAt(cloneCaretIndex)->GetAt(cloneIndex)->Clone());
					cloneIndex++;
				}
				deleteTextLength = textForm->text->GetAt(cloneCaretIndex)->GetLength();
				while (deleteIndex < deleteTextLength)
				{
					textForm->text->GetAt(cloneCaretIndex)->Delete(deleteIndex);
					deleteIndex++;
				}
			}
		}
	}
}

void TextPaste::CaretMove(TextForm *textForm)
{
	Long rowLength;
	Long nextCaretIndex;
	Long downLength;
	Long setCaretIndex;

	rowLength = textForm->textClipboard->GetLength();

	if (rowLength==1)
	{
		nextCaretIndex = textForm->textClipboard->GetAt(textForm->textClipboard->GetLength() - 1)->GetLength();

		if (this->startTextRowLength == textForm->text->GetLength()) //붙여넣기 했는데 전체 줄 개수는 그대로인 경우
		{
			textForm->caret->MoveToRight(nextCaretIndex);
		}

		else
		{
			if (this->isWrite==true) //붙여넣기 했는데 전체 줄 개수가 늘어났고 wirte로 붙여넣어졌을때
			{
				textForm->caret->MoveToDown(1);
				if (textForm->text->GetAt(caretRowIndexSave + 1)->GetLength() < textForm->caret->GetCharacterIndex())
				{
					textForm->caret->MoveToLeft(textForm->caret->GetCharacterIndex() - textForm->text->GetAt(caretRowIndexSave + 1)->GetLength());
				}
			}

			else //붙여넣기 했는데 전체 줄 개수가 늘어났고 insert로 붙여넣어졌을때
			{
				if (textForm->text->GetAt(this->caretRowIndexSave)->GetLength() - this->startCaretIndex == textForm->textClipboard->GetAt(0)->GetLength())
				{
				
					textForm->caret->MoveToRight(textForm->textClipboard->GetAt(0)->GetLength());
				}
					
				else
				{	
					textForm->caret->MoveToDown(1);
					downLength = this->startPasteTextLength - this->startCaretIndex;
					setCaretIndex = textForm->text->GetAt(caretRowIndexSave + 1)->GetLength() - downLength;

					if (setCaretIndex < textForm->caret->GetCharacterIndex())
					{
						textForm->caret->MoveToLeft(textForm->caret->GetCharacterIndex() - setCaretIndex);
					}
				}
			}
		}
	}
	else
	{
		
		if (this->isWrite == true)
		{
			if (this->startCaretIndex==0)
			{
				
				textForm->caret->MoveToDown(rowLength-1);
				textForm->caret->MoveToRight(textForm->textClipboard->GetAt(rowLength-1)->GetLength());
			}
			else
			{
				if (textForm->text->GetLength()==this->startTextRowLength + textForm->textClipboard->GetLength() - 1)
				{
					textForm->caret->MoveToDown(textForm->textClipboard->GetLength() - 1);

					if (textForm->caret->GetCharacterIndex() > textForm->text->GetAt(this->caretRowIndexSave+1)->GetLength())
					{
						textForm->caret->MoveToLeft(textForm->caret->GetCharacterIndex()- textForm->text->GetAt(this->caretRowIndexSave + 1)->GetLength());
					}
					else if (textForm->caret->GetCharacterIndex() < textForm->text->GetAt(this->caretRowIndexSave + 1)->GetLength())
					{
						textForm->caret->MoveToRight(textForm->text->GetAt(this->caretRowIndexSave + 1)->GetLength()- textForm->caret->GetCharacterIndex());
					}
				}
				else if (textForm->text->GetLength() == this->startTextRowLength + textForm->textClipboard->GetLength())
				{
					textForm->caret->MoveToDown(textForm->textClipboard->GetLength());

					if (textForm->caret->GetCharacterIndex() > textForm->text->GetAt(this->caretRowIndexSave + +2)->GetLength())
					{
						textForm->caret->MoveToLeft(textForm->caret->GetCharacterIndex() - textForm->text->GetAt(this->caretRowIndexSave + 2)->GetLength());
					}
					else if (textForm->caret->GetCharacterIndex() < textForm->text->GetAt(this->caretRowIndexSave + 2)->GetLength())
					{
						textForm->caret->MoveToRight(textForm->text->GetAt(this->caretRowIndexSave + 2)->GetLength() - textForm->caret->GetCharacterIndex());
					}

				}
			}
		}
		else
		{

			textForm->caret->MoveToDown(textForm->textClipboard->GetLength());
				
			if (textForm->caret->GetCharacterIndex() > textForm->textClipboard->GetAt(rowLength - 1)->GetLength())
			{
				textForm->caret->MoveToLeft(textForm->caret->GetCharacterIndex()- textForm->textClipboard->GetAt(rowLength - 1)->GetLength());
			}
			else if(textForm->caret->GetCharacterIndex() < textForm->textClipboard->GetAt(rowLength - 1)->GetLength())
			{
				textForm->caret->MoveToRight(textForm->textClipboard->GetAt(rowLength - 1)->GetLength()- textForm->caret->GetCharacterIndex());
			}
		}
	}
}

TextPaste& TextPaste::operator=(const TextPaste& source)
{
	this->startTextRowLength = source.startTextRowLength;
	this->caretRowIndexSave = source.caretRowIndexSave;
	this->startCaretIndex = source.startCaretIndex;
	this->startPasteTextLength = source.startPasteTextLength;
	this->isWrite = source.isWrite;

	return *this;
}
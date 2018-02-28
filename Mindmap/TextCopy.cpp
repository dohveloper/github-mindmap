//TextCopy.cpp

#include "TextCopy.h"
#include "TextForm.h"
#include "Row.h"
#include "Text.h"
#include "SelectText.h"
#include "textClipboard.h"
#include "singleByteCharacter.h"
#include "DoubleByteCharacter.h"

TextCopy::TextCopy()
{
}

TextCopy::~TextCopy()
{
}

void TextCopy::Copy(TextForm *textForm)
{
		Long startRowIndex;
		Long endRowIndex;
		Long startCharacterIndex;
		Long endCharacterIndex;
		Long startRowLength;

		startRowIndex = textForm->selectText->GetStartRowIndex();
		endRowIndex = textForm->selectText->GetEndRowIndex();
		startCharacterIndex = textForm->selectText->GetStartCharacterIndex();
		endCharacterIndex = textForm->selectText->GetEndCharacterIndex();
		startRowLength = textForm->text->GetAt(startRowIndex)->GetLength();
		
		if (startRowIndex == endRowIndex && startCharacterIndex < endCharacterIndex)//한줄 복사이면서 왼쪽에서 오른쪽으로 텍스트가 선택됐을 때
		{
			textForm->textClipboard->Add((Row*)(textForm->text->GetAt(startRowIndex))->Clone());

			while (startCharacterIndex < endCharacterIndex)
			{
				textForm->textClipboard->GetAt(startRowIndex)->Write(textForm->text->GetAt(startRowIndex)->GetAt(startCharacterIndex)->Clone());
				startCharacterIndex++;
			}
		}

		else if (startRowIndex == endRowIndex && endCharacterIndex < startCharacterIndex)//한줄 복사이면서 오른쪽에서 왼쪽으로 텍스트가 선택됐을 때
		{
			textForm->textClipboard->Add((Row*)(textForm->text->GetAt(startRowIndex))->Clone());
			while (endCharacterIndex > startCharacterIndex)
			{
				textForm->textClipboard->GetAt(startRowIndex)->Write(textForm->text->GetAt(startRowIndex)->GetAt(endCharacterIndex)->Clone());

				endCharacterIndex++;
			}
		}

		else if (startRowIndex != endRowIndex && startCharacterIndex < endCharacterIndex)//여러줄 복사이면서 왼쪽에서 오른쪽으로 텍스트가 선택됐을 때
		{

			textForm->textClipboard->Add((Row*)(textForm->text->GetAt(startRowIndex))->Clone());
			while (startCharacterIndex<startRowLength)
			{
				textForm->textClipboard->GetAt(startRowIndex)->Write(textForm->text->GetAt(startRowIndex)->GetAt(startCharacterIndex)->Clone());

				startCharacterIndex++;
			}

			while (startCharacterIndex < startRowLength)
			{
				textForm->textClipboard->GetAt(startRowIndex)->Write(textForm->text->GetAt(startRowIndex)->GetAt(startCharacterIndex)->Clone());

				startCharacterIndex++;
			}
		}
}

		
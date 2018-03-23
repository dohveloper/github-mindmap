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
		Long lowLength;
		Long startRowLength;
		Long endRowLength;
		Long i=0;
		Long textClipboardLength;
		Long textClipboardTextLength;

		startRowIndex = textForm->selectText->GetStartRowIndex();
		endRowIndex = textForm->selectText->GetEndRowIndex();
		startCharacterIndex = textForm->selectText->GetStartCharacterIndex();
		endCharacterIndex = textForm->selectText->GetEndCharacterIndex();
		startRowLength = textForm->text->GetAt(startRowIndex)->GetLength();
		endRowLength = textForm->text->GetAt(endRowIndex)->GetLength();
		
		if (textForm->textClipboard->GetLength() != 0)
		{
			textClipboardLength = textForm->textClipboard->GetLength() - 1;
			
			while (textClipboardLength >= 0)
			{
				textClipboardTextLength = textForm->textClipboard->GetAt(textClipboardLength)->GetLength()-1;
				while (textClipboardTextLength >= 0)
				{

					textForm->textClipboard->GetAt(textClipboardLength)->Delete(textClipboardTextLength);
					textClipboardTextLength--;
				}
				textForm->textClipboard->Delete(textClipboardLength);
				textClipboardLength--;
			}
			
		}


		if (startRowIndex == endRowIndex && startCharacterIndex < endCharacterIndex)//한줄 복사이면서 왼쪽에서 오른쪽으로 텍스트가 선택됐을 때
		{
			textForm->textClipboard->Add((Row*)(textForm->text->GetAt(startRowIndex))->Clone());
			lowLength = textForm->textClipboard->GetAt(i)->GetLength()-1;

			while (lowLength >= i) //Row만 복사되어야 하니 그 밑에 딸려오는 배열들은 삭제
			{
				textForm->textClipboard->GetAt(i)->Delete(lowLength);
				lowLength--;
			}

			while (startCharacterIndex < endCharacterIndex)
			{
				textForm->textClipboard->GetAt(i)->Write(textForm->text->GetAt(startRowIndex)->GetAt(startCharacterIndex)->Clone());
				startCharacterIndex++;
			}
		}
		
		else if (startRowIndex == endRowIndex && endCharacterIndex < startCharacterIndex)//한줄 복사이면서 오른쪽에서 왼쪽으로 텍스트가 선택됐을 때
		{
			
			textForm->textClipboard->Add((Row*)(textForm->text->GetAt(startRowIndex))->Clone());
			lowLength = textForm->textClipboard->GetAt(i)->GetLength()-1;

			while (lowLength  >= i) //Row만 복사되어야 하니 그 밑에 딸려오는 배열들은 삭제
			{
				textForm->textClipboard->GetAt(i)->Delete(lowLength);
				lowLength--;
			}


			while (endCharacterIndex < startCharacterIndex)
			{
				textForm->textClipboard->GetAt(i)->Write(textForm->text->GetAt(startRowIndex)->GetAt(endCharacterIndex)->Clone());

				endCharacterIndex++;
			}
		}

		else if (startRowIndex < endRowIndex)//드래그 다운으로 텍스트가 선택됐을 때
		{
			textForm->textClipboard->Add((Row*)(textForm->text->GetAt(startRowIndex))->Clone());
			lowLength = textForm->textClipboard->GetAt(i)->GetLength()-1;

			while (lowLength  >= i) //Row만 복사되어야 하니 그 밑에 딸려오는 배열들은 삭제
			{
				textForm->textClipboard->GetAt(i)->Delete(lowLength);
				lowLength--;
			}

			while (startCharacterIndex<startRowLength)
			{
				textForm->textClipboard->GetAt(i)->Write(textForm->text->GetAt(startRowIndex)->GetAt(startCharacterIndex)->Clone());

				startCharacterIndex++;
			}

			startRowIndex++;

			while (startRowIndex != endRowIndex)
			{

				textForm->textClipboard->Add((Row*)(textForm->text->GetAt(startRowIndex))->Clone());

				startRowIndex++;
			}

			textForm->textClipboard->Add((Row*)(textForm->text->GetAt(endRowIndex))->Clone());
			lowLength = textForm->textClipboard->GetAt(textForm->textClipboard->GetLength()-1)->GetLength()-1;
		
			while (lowLength  >= i) //Row만 복사되어야 하니 그 밑에 딸려오는 배열들은 삭제
			{
				textForm->textClipboard->GetAt(textForm->textClipboard->GetLength()-1)->Delete(lowLength);
				lowLength--;
			}

			while (i<endCharacterIndex)
			{
				textForm->textClipboard->GetAt(textForm->textClipboard->GetLength() - 1)->Write(textForm->text->GetAt(endRowIndex)->GetAt(i)->Clone());

				i++;
			}
		}

		else if (startRowIndex > endRowIndex)//드래그 업으로 선택됐을 때
		{
			textForm->textClipboard->Add((Row*)(textForm->text->GetAt(endRowIndex))->Clone());
			lowLength = textForm->textClipboard->GetAt(i)->GetLength()-1;

			while (lowLength >= i) //Row만 복사되어야 하니 그 밑에 딸려오는 배열들은 삭제
			{
				textForm->textClipboard->GetAt(i)->Delete(lowLength);
				lowLength--;
			}

			while (endCharacterIndex<endRowLength)
			{
				textForm->textClipboard->GetAt(i)->Write(textForm->text->GetAt(endRowIndex)->GetAt(endCharacterIndex)->Clone());

				endCharacterIndex++;
			}

			endRowIndex++;

			while (endRowIndex != startRowIndex)
			{

				textForm->textClipboard->Add((Row*)(textForm->text->GetAt(endRowIndex))->Clone());

				endRowIndex++;
			}

			textForm->textClipboard->Add((Row*)(textForm->text->GetAt(startRowIndex))->Clone());
			lowLength = textForm->textClipboard->GetAt(textForm->textClipboard->GetLength()-1)->GetLength()-1;
		
			while (lowLength >= i) //Row만 복사되어야 하니 그 밑에 딸려오는 배열들은 삭제
			{
				textForm->textClipboard->GetAt(textForm->textClipboard->GetLength() - 1)->Delete(lowLength);
				lowLength--;
			}

			while (i<startCharacterIndex)
			{
				textForm->textClipboard->GetAt(textForm->textClipboard->GetLength() - 1)->Write(textForm->text->GetAt(startRowIndex)->GetAt(i)->Clone());

				i++;
			}
		}
}

		
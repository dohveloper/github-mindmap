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

		startRowIndex = textForm->selectText->GetStartRowIndex();
		endRowIndex = textForm->selectText->GetEndRowIndex();
		startCharacterIndex = textForm->selectText->GetStartCharacterIndex();
		endCharacterIndex = textForm->selectText->GetEndCharacterIndex();
		startRowLength = textForm->text->GetAt(startRowIndex)->GetLength();
		endRowLength = textForm->text->GetAt(endRowIndex)->GetLength();
		
		if (startRowIndex == endRowIndex && startCharacterIndex < endCharacterIndex)//���� �����̸鼭 ���ʿ��� ���������� �ؽ�Ʈ�� ���õ��� ��
		{
			textForm->textClipboard->Add((Row*)(textForm->text->GetAt(startRowIndex))->Clone());
			lowLength = textForm->textClipboard->GetAt(i)->GetLength()-1;

			while (lowLength >= i) //Row�� ����Ǿ�� �ϴ� �� �ؿ� �������� �迭���� ����
			{
				textForm->textClipboard->GetAt(startRowIndex)->Delete(lowLength);
				lowLength--;
			}

			while (startCharacterIndex < endCharacterIndex)
			{
				textForm->textClipboard->GetAt(i)->Write(textForm->text->GetAt(startRowIndex)->GetAt(startCharacterIndex)->Clone());
				startCharacterIndex++;
			}
		}
		
		else if (startRowIndex == endRowIndex && endCharacterIndex < startCharacterIndex)//���� �����̸鼭 �����ʿ��� �������� �ؽ�Ʈ�� ���õ��� ��
		{
			textForm->textClipboard->Add((Row*)(textForm->text->GetAt(startRowIndex))->Clone());
			lowLength = textForm->textClipboard->GetAt(i)->GetLength()-1;

			while (lowLength  >= i) //Row�� ����Ǿ�� �ϴ� �� �ؿ� �������� �迭���� ����
			{
				textForm->textClipboard->GetAt(i)->Delete(lowLength);
				lowLength--;
			}


			while (endCharacterIndex > startCharacterIndex)
			{
				textForm->textClipboard->GetAt(i)->Write(textForm->text->GetAt(startRowIndex)->GetAt(endCharacterIndex)->Clone());

				endCharacterIndex++;
			}
		}

		else if (startRowIndex < endRowIndex)//������ �����̸鼭 �巡�� �ٿ����� �ؽ�Ʈ�� ���õ��� ��
		{
			textForm->textClipboard->Add((Row*)(textForm->text->GetAt(startRowIndex))->Clone());
			lowLength = textForm->textClipboard->GetAt(i)->GetLength()-1;

			while (lowLength  >= i) //Row�� ����Ǿ�� �ϴ� �� �ؿ� �������� �迭���� ����
			{
				textForm->textClipboard->GetAt(startRowIndex)->Delete(lowLength);
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
			lowLength = textForm->textClipboard->GetAt(endRowIndex)->GetLength()-1;
		
			while (lowLength  >= i) //Row�� ����Ǿ�� �ϴ� �� �ؿ� �������� �迭���� ����
			{
				textForm->textClipboard->GetAt(endRowIndex)->Delete(lowLength);
				lowLength--;
			}

			while (i<endCharacterIndex)
			{
				textForm->textClipboard->GetAt(endRowIndex)->Write(textForm->text->GetAt(endRowIndex)->GetAt(i)->Clone());

				i++;
			}
		}

		else if (startRowIndex > endRowIndex)//������ �����̸鼭 �巡�� ������ ���õ��� ��
		{
			textForm->textClipboard->Add((Row*)(textForm->text->GetAt(endRowIndex))->Clone());
			lowLength = textForm->textClipboard->GetAt(i)->GetLength()-1;

			while (lowLength >= i) //Row�� ����Ǿ�� �ϴ� �� �ؿ� �������� �迭���� ����
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
			lowLength = textForm->textClipboard->GetAt(endRowIndex)->GetLength()-1;
		
			while (lowLength >= i) //Row�� ����Ǿ�� �ϴ� �� �ؿ� �������� �迭���� ����
			{
				textForm->textClipboard->GetAt(startRowIndex)->Delete(lowLength);
				lowLength--;
			}

			while (i<startCharacterIndex)
			{
				textForm->textClipboard->GetAt(startRowIndex)->Write(textForm->text->GetAt(startRowIndex)->GetAt(i)->Clone());

				i++;
			}
		}
}

		
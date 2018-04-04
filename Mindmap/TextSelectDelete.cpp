//TextSelectDelete.h

#include "TextSelectDelete.h"
#include "TextForm.h"
#include "SelectText.h"
#include "Text.h"
#include "Caret.h"

TextSelectDelete::TextSelectDelete()
{
}

TextSelectDelete::~TextSelectDelete()
{
}

void TextSelectDelete::TextSelectDeleteAction(TextForm *textForm)
{

	Long startRowIndex;
	Long endRowIndex;
	Long startCharacterIndex;
	Long endCharacterIndex;
	Long i = 0;
	Long caretIndex;
	Long deleteIndex;

	startRowIndex = textForm->selectText->GetStartRowIndex();
	endRowIndex = textForm->selectText->GetEndRowIndex();
	startCharacterIndex = textForm->selectText->GetStartCharacterIndex();
	endCharacterIndex = textForm->selectText->GetEndCharacterIndex();
	
	//한줄 선택일때
	if (startRowIndex == endRowIndex)
	{	//한줄 선택이면서 좌측에서 우측으로 드래그했을때 헤헤
		if (startCharacterIndex < endCharacterIndex)
		{
			endCharacterIndex--;
			while (endCharacterIndex >= startCharacterIndex)
			{
				textForm->text->GetAt(startRowIndex)->Delete(endCharacterIndex);
				endCharacterIndex--;
			}
			caretIndex = textForm->selectText->GetStartCharacterIndex();
			textForm->caret->SetCharacterIndex(caretIndex);
		}
		else //한줄 선택이면서 우측에서 좌측으로 드래그했을때 히히
		{
			startCharacterIndex--;
			while (startCharacterIndex >= endCharacterIndex)
			{
				textForm->text->GetAt(startRowIndex)->Delete(startCharacterIndex);
				startCharacterIndex--;
			}
			caretIndex = textForm->selectText->GetEndCharacterIndex();
			textForm->caret->SetCharacterIndex(caretIndex);
		}
	}
	else
	{
		if (startRowIndex < endRowIndex)
		{
			
			endCharacterIndex--;
			while (endCharacterIndex >= i)
			{
				textForm->text->GetAt(endRowIndex)->Delete(endCharacterIndex);
				endCharacterIndex--;
			}
			endRowIndex--;
		
			while (endRowIndex != startRowIndex)
			{
				textForm->text->Delete(endRowIndex);
				endRowIndex--;
			}
			deleteIndex = textForm->text->GetAt(startRowIndex)->GetLength() - 1;
			while (deleteIndex >= startCharacterIndex)
			{
				textForm->text->GetAt(startRowIndex)->Delete(deleteIndex);
				deleteIndex--;
			}
			textForm->caret->MoveToUp(endRowIndex - startRowIndex);
			if (startCharacterIndex < endCharacterIndex)
			{
				textForm->caret->MoveToLeft(endCharacterIndex - startCharacterIndex);
			}
			else if (startCharacterIndex > endCharacterIndex)
			{
				textForm->caret->MoveToLeft(startCharacterIndex - endCharacterIndex);
			}
		}
		else
		{
			i = 0;

			startCharacterIndex--;
			while (startCharacterIndex >= i)
			{
				textForm->text->GetAt(startRowIndex)->Delete(startCharacterIndex);
				startCharacterIndex--;
			}
			startCharacterIndex--;

			while (startRowIndex != endRowIndex)
			{
				textForm->text->Delete(startRowIndex);
				startRowIndex--;
			}
			deleteIndex = textForm->text->GetAt(endRowIndex)->GetLength() - 1;
			while (deleteIndex >= endCharacterIndex)
			{
				textForm->text->GetAt(endRowIndex)->Delete(deleteIndex);
				deleteIndex--;
			}
			textForm->caret->MoveToUp(startRowIndex - endRowIndex);

			if (endCharacterIndex < startCharacterIndex)
			{
				textForm->caret->MoveToLeft(startCharacterIndex - endCharacterIndex);
			}
			else if (endCharacterIndex > startCharacterIndex)
			{
				textForm->caret->MoveToLeft(endCharacterIndex - startCharacterIndex);
			}
		}
	}
	textForm->selectText->SetIsNotSelect();
}
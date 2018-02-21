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
	Long rowLength;
	Long i = 0;
	Long caretIndex;

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
		textForm->selectText->SetIsNotSelect();
	}

	else
	{
		while (endCharacterIndex>=i)
		{
			textForm->text->GetAt(endRowIndex)->Delete(endCharacterIndex);
			endCharacterIndex--;
		}
	
		while (startRowIndex < endRowIndex)
		{

			startCharacterIndex = textForm->selectText->GetStartCharacterIndex();
			rowLength = textForm->text->GetAt(startRowIndex)->GetLength();


			while(startCharacterIndex < rowLength)
			{
				textForm->text->GetAt(startRowIndex)->Delete(startCharacterIndex);
				startCharacterIndex++;
			}
			startRowIndex++;
		}
		endCharacterIndex = textForm->selectText->GetEndCharacterIndex();
		
		while (i <= endCharacterIndex)
		{
			textForm->text->GetAt(endRowIndex)->Delete(i);
			i++;
		}
		

	}
}
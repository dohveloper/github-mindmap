//TextCopy.cpp

#include "TextCopy.h"
#include "TextForm.h"
#include "Row.h"
#include "Text.h"
#include "SelectText.h"
#include "textClipboard.h"

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

		startRowIndex = textForm->selectText->GetStartRowIndex();
		endRowIndex = textForm->selectText->GetEndRowIndex();
		startCharacterIndex = textForm->selectText->GetStartCharacterIndex();
		endCharacterIndex = textForm->selectText->GetEndCharacterIndex();

		if (startRowIndex == endRowIndex)
		{
			textForm->textClipboard->Add(new Row);
			while (startCharacterIndex < endCharacterIndex)
			{
				textForm->textClipboard->GetAt(startRowIndex)->Write(textForm->text->GetAt(startRowIndex)->GetAt(startCharacterIndex));
				startCharacterIndex++;
			}
		}
		Long i = 0;
		CString a;
		a.Format("%d", textForm->textClipboard->GetAt(startRowIndex)->GetAt(0)->GetCharacter());
		textForm->MessageBox(a);
}
//WordWrap.cpp

#include "WordWrap.h"
#include "TextForm.h"
#include "TextFormSize.h"
#include "Caret.h"
#include "Text.h"

#define MAXWIDTHSIZE 600

WordWrap::WordWrap() {

}

WordWrap::~WordWrap() {

}

void WordWrap::Writing(TextForm *textForm,CDC *cdc) {
	Long i;
	Row *row;
	Character *character;

	i = textForm->caret->GetRowIndex();

	while (i < textForm->text->GetLength() && textForm->text->GetAt(i)->GetRowWidth(cdc, 0, textForm->text->GetAt(i)->GetLength()) > MAXWIDTHSIZE)
	{
		if (i == textForm->text->GetLength() - 1)
		{
			textForm->text->Write(new Row(true));
			textForm->textFormSize->TextFormHeightSizeLong(textForm, cdc);
		}
		else if (textForm->text->GetAt(i + 1)->GetIsWordWrap() == false)
		{
			textForm->text->Insert(i + 1, new Row(true));
			textForm->textFormSize->TextFormHeightSizeLong(textForm, cdc);
		}
		while (textForm->text->GetAt(i)->GetRowWidth(cdc, 0, textForm->text->GetAt(i)->GetLength()) > MAXWIDTHSIZE)
		{
			row = (Row*)textForm->text->GetAt(i);

			character = row->GetAt(row->GetLength() - 1);

			row->Delete(row->GetLength() - 1);

			textForm->text->GetAt(i + 1)->Insert(0, character);
		}
		i++;	
	}
	row = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());

	if (textForm->caret->GetCharacterIndex() >= row->GetLength())
	{
		textForm->caret->MoveToDown();
		textForm->caret->SetCharacterIndex(0);
	}
}

void WordWrap::Deleting(TextForm *textForm, CDC *cdc) {
	Long i = textForm->caret->GetRowIndex();
	Character *character;

	
	while (i < textForm->text->GetLength() - 1 && textForm->text->GetAt(i)->GetRowWidth(cdc, 0, textForm->text->GetAt(i)->GetLength()) < MAXWIDTHSIZE)
	{
		while (textForm->text->GetAt(i)->GetRowWidth(cdc, 0, textForm->text->GetAt(i)->GetLength()) < MAXWIDTHSIZE && textForm->text->GetAt(i + 1)->GetLength() > 0)
		{
			character = textForm->text->GetAt(i + 1)->GetAt(0);

			textForm->text->GetAt(i + 1)->Delete(0);

			textForm->text->GetAt(i)->Insert(textForm->text->GetAt(i)->GetLength(), character);
		}

		if (textForm->text->GetAt(i)->GetRowWidth(cdc, 0, textForm->text->GetAt(i)->GetLength()) > MAXWIDTHSIZE && textForm->text->GetAt(i + 1)->GetLength() > 0)
		{
			character = textForm->text->GetAt(i)->GetAt(textForm->text->GetAt(i)->GetLength() - 1);

			textForm->text->GetAt(i)->Delete(textForm->text->GetAt(i)->GetLength() - 1);

			textForm->text->GetAt(i + 1)->Insert(0, character);
		}

		if (textForm->text->GetAt(i + 1)->GetLength() == 0)
		{
			textForm->text->Delete(i + 1);
		}
		else if (textForm->text->GetAt(i + 1)->GetIsWordWrap() == false)
		{
			textForm->text->GetAt(i + 1)->SetIsWordWrap(true);
		}

		i++;
	}
}
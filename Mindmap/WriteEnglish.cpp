//WriteEnglish.cpp

#include "WriteEnglish.h"
#include "TextForm.h"
#include "Caret.h"
#include "TextFormSize.h"
#include "Text.h"
#include "SingleByteCharacter.h"

WriteEnglish::WriteEnglish() {

}

WriteEnglish::~WriteEnglish() {

}

void WriteEnglish::Write(TextForm *textForm,CDC *cdc,char word) {

	if (textForm->caret->GetCharacterIndex() > textForm->text->GetAt(textForm->caret->GetRowIndex())->GetLength() - 1)
	{
		textForm->text->GetAt(textForm->caret->GetRowIndex())->Write(new SingleByteCharacter(word));
	}
	else if (textForm->caret->GetCharacterIndex() < textForm->text->GetAt(textForm->caret->GetRowIndex())->GetLength())
	{
		textForm->text->GetAt(textForm->caret->GetRowIndex())->Insert(textForm->caret->GetCharacterIndex(), new SingleByteCharacter(word));
	}
	textForm->textFormSize->TextFormWidthSizeLong(textForm, cdc);
	textForm->caret->MoveToRight();

	textForm->compose = FALSE;
}
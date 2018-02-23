//WriteKorean.cpp

#include "WriteKorean.h"
#include "TextForm.h"
#include "Caret.h"
#include "Text.h"
#include "TextFormSize.h"
#include "DoubleByteCharacter.h"

WriteKorean::WriteKorean() {

}

WriteKorean::~WriteKorean() {

}

void WriteKorean::KoreanMixing(TextForm *textForm, HIMC hIMC,HWND hWnd,CDC *cdc) {
	Long len;
	char str[3] = "";
	DoubleByteCharacter *doubleByte;

	len = ImmGetCompositionString(hIMC, GCS_COMPSTR, NULL, 0);
	ImmGetCompositionString(hIMC, GCS_COMPSTR, str, len);

	doubleByte = new DoubleByteCharacter(str);
	if (textForm->compose == TRUE)
	{
		textForm->text->GetAt(textForm->caret->GetRowIndex())->Correct(textForm->caret->GetCharacterIndex(), doubleByte);
	}
	else
	{
		if (textForm->caret->GetCharacterIndex() > textForm->text->GetAt(textForm->caret->GetRowIndex())->GetLength() - 1)
		{
			textForm->text->GetAt(textForm->caret->GetRowIndex())->Write(doubleByte);
		}
		else
		{
			textForm->text->GetAt(textForm->caret->GetRowIndex())->Insert(textForm->caret->GetCharacterIndex(), doubleByte);
		}
	}
	textForm->textFormSize->TextFormWidthSizeLong(textForm, cdc);

	textForm->compose = TRUE;
}

void WriteKorean::KoreanMixed(TextForm *textForm, HIMC hIMC, HWND hWnd) {
	Long len;
	char str[3] = "";
	DoubleByteCharacter *doubleByte;

	len = ImmGetCompositionString(hIMC, GCS_RESULTSTR, NULL, 0);
	ImmGetCompositionString(hIMC, GCS_RESULTSTR, str, len);

	doubleByte = new DoubleByteCharacter(str);

	if (textForm->compose == TRUE)
	{
		textForm->text->GetAt(textForm->caret->GetRowIndex())->Correct(textForm->caret->GetCharacterIndex(), doubleByte);
		textForm->caret->MoveToRight();
	}
	textForm->compose = FALSE;
}
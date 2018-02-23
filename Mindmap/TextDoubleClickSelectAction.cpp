//TextDoubleClickSelectAction.cpp

#include "TextDoubleClickSelectAction.h"
#include "TextDoubleClick.h"
#include "TextForm.h"
#include "Caret.h"
#include "SelectText.h"
#include "Text.h"
#include "TextFont.h"
#include <string>
using namespace std;


TextDoubleClickSelectAction::TextDoubleClickSelectAction()
{
}


TextDoubleClickSelectAction::~TextDoubleClickSelectAction()
{
}


void TextDoubleClickSelectAction::AllSelect(TextForm *textForm, CDC *cdc, Long width)
{
	Long start = 0;
	Long end = 0;
	string word;
	Long rowIndex = textForm->selectText->GetStartRowIndex();

	start = textForm->selectText->GetStartCharacterIndex();
	end = textForm->selectText->GetEndCharacterIndex();
	textForm->caret->SetCharacterIndex(end);

	while (start < end)
	{
		word += textForm->text->GetAt(rowIndex)->GetAt(start)->MakeString();
		start++;
	}
	cdc->TextOut(textForm->caret->GetX()-width, textForm->textFont->GetHeight()*rowIndex, (CString)word.c_str());
}







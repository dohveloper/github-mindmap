//TextDoubleClick.cpp

#include "TextForm.h"
#include "Text.h"
#include "Caret.h"
#include "TextDoubleClick.h"
#include "TextDoubleClickSelectAction.h"
#include <string>
using namespace std;
typedef signed long int Long;



TextDoubleClick::TextDoubleClick()
{
}

TextDoubleClick::~TextDoubleClick()
{
}

void TextDoubleClick::TextDoubleClickSelect(TextForm *textForm, CDC *cdc)
{
	TextDoubleClickSelectAction textDoubleClickSelectAction;
	Long caretIndex;
	Row* row;
	Long width;
	string word;

	caretIndex = textForm->caret->GetCharacterIndex() - 1;

	row = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());

	while (caretIndex >= 0 && row->GetAt(caretIndex)->MakeString() != " ")
	{
		word += row->GetAt(caretIndex)->MakeString();

		caretIndex--;
	}
	width = cdc->GetTextExtent((CString)word.c_str()).cx;

	textDoubleClickSelectAction.AllSelect(textForm, cdc, width);
}


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

Long TextDoubleClick::CheckStartCharacterIndex(TextForm *textForm)
{
	Long caretIndex;
	Row* row;
	Long index;

	caretIndex = textForm->caret->GetCharacterIndex() - 1;
	row = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());


	while (caretIndex >= 0 && row->GetAt(caretIndex)->MakeString() != " ")
	{
		caretIndex--;
	}

	if (caretIndex == -1)
	{
		caretIndex = 0;
	}

	if (caretIndex != 0 && row->GetAt(caretIndex)->MakeString() == " ")
	{

		caretIndex += 1;
	}


	index = caretIndex;

	return index;
}

Long TextDoubleClick::CheckEndCharacterIndex(TextForm *textForm)
{
	Long caretIndex;
	Row* row;
	Long length;
	Long index;

	caretIndex = textForm->caret->GetCharacterIndex();
	row = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());
	length = row->GetLength();

	while (caretIndex < length && row->GetAt(caretIndex)->MakeString() != " ")
	{

		caretIndex++;
	}

	index = caretIndex;
	return index;
}

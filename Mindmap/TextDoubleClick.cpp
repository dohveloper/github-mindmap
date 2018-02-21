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

	while (caretIndex >= 0 && row->GetAt(caretIndex)->MakeString() != " " && row->GetAt(caretIndex)->MakeString().compare("\t") != 0)
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

	caretIndex = textForm->caret->GetCharacterIndex()-1;
	row = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());


	while (caretIndex >= 0 &&  row->GetAt(caretIndex)->MakeString().compare(" ") != 0 && row->GetAt(caretIndex)->MakeString().compare("\t") != 0)
	{
		caretIndex--;
	}

	if (caretIndex == -1)
	{
		caretIndex = 0;
	}

	else if (row->GetAt(caretIndex)->MakeString().compare(" ") != 0 || row->GetAt(caretIndex)->MakeString().compare("\t") != 0)
	{
		caretIndex += 1;
	}


	return caretIndex;
}

Long TextDoubleClick::CheckEndCharacterIndex(TextForm *textForm)
{
	Long caretIndex;
	Row* row;
	Long length;

	caretIndex = textForm->caret->GetCharacterIndex();
	row = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());
	length = row->GetLength();

	while (caretIndex < length && row->GetAt(caretIndex)->MakeString().compare(" ") != 0 && row->GetAt(caretIndex)->MakeString().compare("\t") != 0)
	{
		caretIndex++;
	}

	return caretIndex;
}

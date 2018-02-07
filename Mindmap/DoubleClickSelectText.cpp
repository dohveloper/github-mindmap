//DoubleClickSelectText.cpp

#include "DoubleClickSelectText.h"
#include "TextForm.h"
#include "Caret.h"
#include "SelectText.h"
#include "Text.h"
#include <string>
using namespace std;
typedef signed long int Long;


DoubleClickSelectText::DoubleClickSelectText()
{
}


DoubleClickSelectText::~DoubleClickSelectText()
{
}


void DoubleClickSelectText::AllSelect(TextForm *textForm, CDC *cdc, Long width)
{

	Long start = 0;
	Long end = 0;
	string word;
	Long rowIndex = textForm->selectText->GetStartRowIndex();


	start = textForm->selectText->GetStartCharacterIndex();
	end = textForm->selectText->GetEndCharacterIndex();


	Long i = start;

	while (i < end)
	{
		word += textForm->text->GetAt(rowIndex)->GetAt(i)->MakeString();
		i++;
	}

	cdc->TextOut(textForm->caret->GetX()-width, textForm->fontHeight*rowIndex, (CString)word.c_str());
}







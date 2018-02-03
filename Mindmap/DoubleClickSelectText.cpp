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
	this->width = 0;
}

DoubleClickSelectText::DoubleClickSelectText(Long width)
{
	this->width = width;
}

DoubleClickSelectText::DoubleClickSelectText(const DoubleClickSelectText& source)
{
	this->width = source.width;
}

DoubleClickSelectText::~DoubleClickSelectText()
{
}

Long DoubleClickSelectText::CheckStartCharacterIndex(TextForm *textForm, CDC *cdc)
{
	Long caretIndex;
	Row* row;
	Long length;
	Long index;
	Long width;
	string word;
	Long rowIndex = textForm->selectText->GetStartRowIndex();
	
	caretIndex = textForm->caret->GetCharacterIndex();
	row = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());
	length= row->GetLength();

	while(caretIndex >= 0 && row->GetAt(caretIndex)->MakeString()!=" ")
	{
		word += row->GetAt(caretIndex)->MakeString();
		caretIndex--;
	}

	if (caretIndex == -1)
	{
		caretIndex = 0;
	}
	index = caretIndex;

	this->width = cdc->GetTextExtent((CString)word.c_str()).cx;

	return index;
}

Long DoubleClickSelectText::CheckEndCharacterIndex(TextForm *textForm)
{
	Long caretIndex;
	Row* row;
	Long length;
	Long i = 0;
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
void DoubleClickSelectText::AllSelect(TextForm *textForm, CDC *cdc)
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

	cdc->TextOut(textForm->caret->GetX()-this->width, textForm->fontHeight*rowIndex, (CString)word.c_str());
}

DoubleClickSelectText& DoubleClickSelectText::operator=(const DoubleClickSelectText& soucre)
{
	this->width = soucre.width;

	return *this;
}






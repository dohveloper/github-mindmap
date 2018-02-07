//TextFormSize.cpp

#include "TextFormSize.h"
#include "TextForm.h"
#include "Caret.h"
#include "Text.h"
#include <string>

using namespace std;

TextFormSize::TextFormSize()
{
}


TextFormSize::~TextFormSize()
{
}



void TextFormSize::TextFormWidthSize(TextForm *textForm, CDC *cdc)
{
	Row* row;
	string word;
	Long length;
	Long width;

	row = (Row*)textForm->text->GetAt(textForm->caret->GetRowIndex());
	length = row->GetLength()-1;

	while (length >= 0)
	{
		word += row->GetAt(length)->MakeString();

		length--;
	}
	width = cdc->GetTextExtent((CString)word.c_str()).cx;

	CRect rect;
	Long a = 20;
	textForm->GetWindowRect(rect);
	textForm->ScreenToClient(rect);
	if (width > rect.right)
	{
		CString b;
		b.Format("%d", rect.left);
		textForm->MessageBox(b);
		textForm->MoveWindow(rect.left,rect.top,rect.right+100,rect.bottom);
	}
}

void TextFormSize::TextFormHeightSize(TextForm *textForm)
{

}




//Caret.cpp
#include "Caret.h"
#include "Text.h"
using namespace std;

Caret::Caret() {
	this->currentX = 0;
	this->currentY = 0;
	this->characterIndex = 0;
	this->rowIndex = 0;
}

Caret::Caret(const Caret& source) {
	this->currentX = source.currentX;
	this->currentY = source.currentY;
	this->characterIndex = source.characterIndex;
	this->rowIndex = source.rowIndex;
}
Caret::~Caret() {

}

Caret* Caret::MoveToPoint(TextForm *textForm, CDC *cdc,CPoint point) {
	Long width = 0;
	Long textLength = 0;
	Long length;
	Long wordWidth;
	string word;
	CFont fnt;

	fnt.CreateFont(30, 16, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("굴림체"));
	cdc->SelectObject(&fnt);

	this ->characterIndex = 0;
	this->rowIndex = 0;

	textLength = textForm->text->GetLength()-1;

	//아마 수정(나중에)
	this->rowIndex = point.y / textForm->fontHeight;

	if (this->rowIndex > textLength)
	{
		this->rowIndex = textLength;
	}
	length = textForm->text->GetAt(this->rowIndex)->GetLength();

	while (width <= point.x && this->characterIndex < length)
	{
		if (textForm->text->GetAt(this->rowIndex)->GetAt(this->characterIndex)->MakeString().compare("\t") == 0)
		{
			word = "        ";
		}
		else
		{
			word = textForm->text->GetAt(this->rowIndex)->GetAt(this->characterIndex)->MakeString();
		}
		width += cdc->GetTextExtent((CString)word.c_str()).cx;

		this->characterIndex++;
	}
	wordWidth = cdc->GetTextExtent((CString)word.c_str()).cx;

	if (point.x < width - wordWidth /2)
	{
		this->characterIndex--;
	}
	
	fnt.DeleteObject();

	return this;
}

Caret* Caret::MoveToIndex(TextForm *textForm,CDC *cdc) {
	this->currentX = textForm->text->GetAt(this->rowIndex)->GetRowWidth(cdc, 0,this->characterIndex);
	
	this->currentY = this->rowIndex * textForm->fontHeight;

	if (textForm->compose == FALSE)
	{
		textForm->CreateSolidCaret(3, textForm->fontHeight);
	}
	else
	{
		string word = textForm->text->GetAt(this->rowIndex)->GetAt(this->characterIndex)->MakeString();
		CSize size = cdc->GetTextExtent((CString)word.c_str());
		textForm->CreateSolidCaret(size.cx, textForm->fontHeight);
	}
	textForm->SetCaretPos(CPoint(this->currentX,this->currentY));

	textForm->ShowCaret();

	return this;
}

void Caret::MoveToRight(Long index) {
	this->characterIndex += index;
}
void Caret::MoveToLeft(Long index) {
	this->characterIndex -= index;
}
void Caret::MoveToDown(Long index) {
	this->rowIndex += index;
}
void Caret::MoveToUp(Long index) {
	this->rowIndex -= index;
}

Long Caret::SetCharacterIndex(Long index) {
	this->characterIndex = index;

	return this->characterIndex;
}

Long Caret::CheckStartCharacterIndex(TextForm *textForm)
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

Long Caret::CheckEndCharacterIndex(TextForm *textForm)
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

Long Caret::SetRowIndex(Long index) {
	this->rowIndex = index;

	return this->rowIndex;
}

Caret& Caret::operator=(const Caret& source) {
	this->currentX = source.currentX;
	this->currentY = source.currentY;

	return *this;
}
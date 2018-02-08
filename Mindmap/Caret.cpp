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
	string word;
	CFont fnt;

	fnt.CreateFont(30, 16, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("±¼¸²Ã¼"));

	cdc->SelectObject(&fnt);

	this ->characterIndex = 0;
	this->rowIndex = 0;

	textLength = textForm->text->GetLength()-1;

	this->rowIndex = point.y / textForm->fontHeight;

	if (this->rowIndex > textLength)
	{
		this->rowIndex = textLength;
	}
	Long length = textForm->text->GetAt(this->rowIndex)->GetLength();

	while (width <= point.x && this->characterIndex < length)
	{
		word = textForm->text->GetAt(this->rowIndex)->GetAt(this->characterIndex)->MakeString();

		width += cdc->GetTextExtent((CString)word.c_str()).cx;

		this->characterIndex++;
	}
	Long wordWIdth = cdc->GetTextExtent((CString)word.c_str()).cx;

	if (point.x < width - wordWIdth/2)
	{
		this->characterIndex--;
	}
	
	fnt.DeleteObject();

	return this;
}

Caret* Caret::MoveToIndex(TextForm *textForm,CDC *cdc) {
	this->currentX = textForm->text->GetAt(this->rowIndex)->GetRowWidth(cdc, this->characterIndex);
	
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


Long Caret::SetRowIndex(Long index) {
	this->rowIndex = index;

	return this->rowIndex;
}

Caret& Caret::operator=(const Caret& source) {
	this->currentX = source.currentX;
	this->currentY = source.currentY;

	return *this;
}
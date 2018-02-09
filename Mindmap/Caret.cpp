//Caret.cpp
#include "Caret.h"
#include "Text.h"
#include "TextFont.h"
#include "TextFormSize.h"

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

	fnt.CreateFont(textForm->textFont->GetHeight(), textForm->textFont->GetWidth(), 0, 0, textForm->textFont->GetWeight(), textForm->textFont->GetItalic(), textForm->textFont->GetUnderline(), textForm->textFont->GetStrikeOut(), DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T(textForm->textFont->GetLpszFacename()));
	cdc->SelectObject(&fnt);

	this ->characterIndex = 0;
	this->rowIndex = 0;

	textLength = textForm->text->GetLength()-1;

	//아마 수정(나중에)
	this->rowIndex = point.y / textForm->textFont->GetHeight();

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
	if (textForm->text->GetAt(this->rowIndex)->GetRowWidth(cdc, 0, this->characterIndex)<textForm->textFormSize->GetWidth())
	{
		this->currentX = textForm->text->GetAt(this->rowIndex)->GetRowWidth(cdc, 0, this->characterIndex);
	}
	else
	{
		this->currentX = textForm->text->GetAt(this->rowIndex)->GetRowWidth(cdc, 0, this->characterIndex) - (textForm->textFormSize->GetWidth() * textForm->lineWrapCount);
	}

	this->currentY = this->rowIndex * textForm->textFont->GetHeight();

	if (textForm->compose == FALSE)
	{
		textForm->CreateSolidCaret(3, textForm->textFont->GetHeight());
	}
	else
	{
		textForm->CreateSolidCaret(textForm->textFont->GetWidth()*2, textForm->textFont->GetHeight());
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
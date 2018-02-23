//SelectText.cpp

#include "TextForm.h"
#include "SelectText.h"
#include "Caret.h"
#include "Text.h"
#include "TextDrag.h"
#include "TextDoubleClick.h"

SelectText::SelectText() {
	this->startCharacterIndex = 0;
	this->startRowIndex = 0;
	this->endCharacterIndex = 0;
	this->endRowIndex = 0;
}

SelectText::SelectText(const SelectText& source) {
	this->startCharacterIndex = source.startCharacterIndex;
	this->startRowIndex = source.startRowIndex;
	this->endCharacterIndex = source.endCharacterIndex;
	this->endRowIndex = source.endRowIndex;
}

SelectText::~SelectText() {
}

void SelectText::TextDragAction(TextForm *textForm, CDC *cdc, CPoint point) {
	Long start;
	Long end;
	TextDrag textDrag;
	if (point.x < 0 && point.y>=0)
	{
		textForm->caret->MoveToPoint(textForm, cdc, CPoint(0, point.y));
		textForm->selectText->SetEndCharacterIndex(0);
		textForm->selectText->SetEndRowIndex(textForm->caret->GetRowIndex());
	}
	else if (point.x>=0 && point.y < 0 )
	{
		textForm->caret->MoveToPoint(textForm, cdc, CPoint(point.x, 0));
		textForm->selectText->SetEndCharacterIndex(textForm->caret->GetCharacterIndex());
		textForm->selectText->SetEndRowIndex(0);
	}
	else if(point.x<0 && point.y<0)
	{
		textForm->caret->MoveToPoint(textForm, cdc, CPoint(0, 0));
		textForm->selectText->SetEndCharacterIndex(0);
		textForm->selectText->SetEndRowIndex(0);
	}
	else
	{
		textForm->caret->MoveToPoint(textForm, cdc, point);
		textForm->selectText->SetEndCharacterIndex(textForm->caret->GetCharacterIndex());
		textForm->selectText->SetEndRowIndex(textForm->caret->GetRowIndex());
	}
	textForm->caret->MoveToIndex(textForm, cdc);

	start = textForm->selectText->GetStartRowIndex();
	end = textForm->selectText->GetEndRowIndex();

	if (start - end == 0 && textForm->selectText->GetStartCharacterIndex()>=0)
	{
		textDrag.SingleLineDrag(textForm, cdc);
	}
	else if ((start - end == 1 || end - start == 1) && textForm->selectText->GetStartCharacterIndex()>=0)
	{
		textDrag.DoubleLineDrag(textForm, cdc);
	}
	else if((start - end >= 2 ||	end - start >=2) && textForm->selectText->GetStartCharacterIndex()>=0)
	{
		textDrag.MultiLineDrag(textForm, cdc);
	}
}

void SelectText::TextDoubleClickAction(TextForm *textForm, CDC *cdc, CPoint point) {
	TextDoubleClick textDoubleClick;
	
	textForm->selectText->SetStartCharacterIndex(textDoubleClick.CheckStartCharacterIndex(textForm));
	textForm->selectText->SetStartRowIndex(textForm->caret->GetRowIndex());
	textForm->selectText->SetEndCharacterIndex(textDoubleClick.CheckEndCharacterIndex(textForm));
	textForm->selectText->SetEndRowIndex(textForm->caret->GetRowIndex());
	
	textForm->caret->SetCharacterIndex(textForm->selectText->GetEndCharacterIndex());
	textForm->RedrawWindow();

	textDoubleClick.TextDoubleClickSelect(textForm, cdc);

}


SelectText& SelectText::operator=(const SelectText& source) {
	this->startCharacterIndex = source.startCharacterIndex;
	this->startRowIndex = source.startRowIndex;
	this->endCharacterIndex = source.endCharacterIndex;
	this->endRowIndex = source.endRowIndex;

	return *this;
}


Long SelectText::SetStartCharacterIndex(Long index) {
	this->startCharacterIndex = index;
	return this->startCharacterIndex;
}
Long SelectText::SetStartRowIndex(Long index) {
	this->startRowIndex = index;
	return this->startRowIndex;
}
Long SelectText::SetEndCharacterIndex(Long index) {
	this->endCharacterIndex = index;
	return this->endCharacterIndex;
}
Long SelectText::SetEndRowIndex(Long index) {
	this->endRowIndex = index;
	return this->endRowIndex;
}

void SelectText::SetIsSelect()
{
	this->IsSelect = true;
}

void SelectText::SetIsNotSelect()
{
	this->IsSelect = false;
}

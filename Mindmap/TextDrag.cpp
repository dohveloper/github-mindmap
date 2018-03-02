//TextDrag.cpp

#include "TextDrag.h"
#include "TextForm.h"
#include "SelectText.h"
#include "Text.h"
#include "Caret.h"
#include "SingleLineDragAction.h"
#include "DoubleLineDragAction.h"
#include "MultiLineDragAction.h"
#include <string>
using namespace std;

TextDrag::TextDrag() {
}

TextDrag::~TextDrag() {

}

//한줄 드래그
void TextDrag::SingleLineDrag(TextForm *textForm,CDC *cdc) {
	SingleLineDragAction singleLineDragAction;

	//오른쪽으로 드래그
	if (textForm->selectText->GetStartCharacterIndex() < textForm->selectText->GetEndCharacterIndex())
	{
		singleLineDragAction.DragRight(textForm,cdc);
	}
	//왼쪽으로 드래그
	else if (textForm->selectText->GetStartCharacterIndex() > textForm->selectText->GetEndCharacterIndex())
	{
		singleLineDragAction.DragLeft(textForm, cdc);
	}
}

void TextDrag::DoubleLineDrag(TextForm *textForm, CDC *cdc) {
	DoubleLineDragAction doubleLineDragAction;

	//위에서 아래로 드래그
	if (textForm->selectText->GetStartRowIndex() < textForm->selectText->GetEndRowIndex())
	{
		doubleLineDragAction.DragDown(textForm,cdc);
	} 

	//아래에서 위로 드래그
	else if(textForm->selectText->GetStartRowIndex() > textForm->selectText->GetEndRowIndex())
	{	
		doubleLineDragAction.DragUp(textForm,cdc);
	}

}

void TextDrag::MultiLineDrag(TextForm *textForm, CDC *cdc) {
	MultiLineDragAction multiLineDragAction;

	//위에서 아래로 드래그
	if (textForm->selectText->GetStartRowIndex() < textForm->selectText->GetEndRowIndex())
	{
		multiLineDragAction.DragDown(textForm, cdc);
	}

	//아래에서 위로 드래그
	else if (textForm->selectText->GetStartRowIndex() > textForm->selectText->GetEndRowIndex())
	{
		multiLineDragAction.DragUp(textForm, cdc);
	}
}

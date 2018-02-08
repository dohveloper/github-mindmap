//SingleLineDragAction.cpp

#include "SingleLineDragAction.h"
#include "TextDrag.h"
#include "TextForm.h"
#include "SelectText.h"
#include "Text.h"
#include "Caret.h"
#include "TextFont.h"
#include <string>
using namespace std;

SingleLineDragAction::SingleLineDragAction() {

}

SingleLineDragAction::~SingleLineDragAction() {

}

void SingleLineDragAction::DragLeft(TextForm *textForm,CDC *cdc) {
	Long start = 0;//드래그 시작
	Long end = 0;//드래그 마지막
	string word;
	Long rowIndex = textForm->selectText->GetStartRowIndex();

	start = textForm->selectText->GetStartCharacterIndex();
	end = textForm->selectText->GetEndCharacterIndex();

	//왼쪽으로 드래그
	word = textForm->text->GetAt(rowIndex)->MakeString(end,start);
	
	cdc->TextOut(textForm->caret->GetX(), textForm->textFont->GetHeight()*rowIndex, (CString)word.c_str());
}


void SingleLineDragAction::DragRight(TextForm *textForm, CDC *cdc) {
	Long start = 0;//드래그 시작
	Long end = 0;//드래그 마지막
	string word;
	Long rowIndex = textForm->selectText->GetStartRowIndex();

	start = textForm->selectText->GetStartCharacterIndex();
	end = textForm->selectText->GetEndCharacterIndex();

	//오른쪽으로 드래그
	word = textForm->text->GetAt(rowIndex)->MakeString(start, end);

	Long width = cdc->GetTextExtent((CString)word.c_str()).cx;
	cdc->TextOut(textForm->caret->GetX() - width, textForm->textFont->GetHeight()*rowIndex, (CString)word.c_str());
}
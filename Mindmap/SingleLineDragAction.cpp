//SingleLineDragAction.cpp

#include "SingleLineDragAction.h"
#include "TextDrag.h"
#include "TextForm.h"
#include "SelectText.h"
#include "Text.h"
#include "Caret.h"
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

	Long i = end;

	while (i < start)
	{
		if (textForm->text->GetAt(rowIndex)->GetAt(i)->MakeString().compare("\t") == 0)
		{
			word += "        ";
		}
		else
		{
			word += textForm->text->GetAt(rowIndex)->GetAt(i)->MakeString();
		}
		i++;
	}
	cdc->TextOut(textForm->caret->GetX(), textForm->fontHeight*rowIndex, (CString)word.c_str());
}


void SingleLineDragAction::DragRight(TextForm *textForm, CDC *cdc) {
	Long start = 0;//드래그 시작
	Long end = 0;//드래그 마지막
	string word;
	Long rowIndex = textForm->selectText->GetStartRowIndex();

	start = textForm->selectText->GetStartCharacterIndex();
	end = textForm->selectText->GetEndCharacterIndex();

	//오른쪽으로 드래그
	Long i = start;

	while (i < end)
	{
		if (textForm->text->GetAt(rowIndex)->GetAt(i)->MakeString().compare("\t") == 0)
		{
			word += "        ";
		}
		else
		{
			word += textForm->text->GetAt(rowIndex)->GetAt(i)->MakeString();
		}
		i++;
	}
	Long width = cdc->GetTextExtent((CString)word.c_str()).cx;
	cdc->TextOut(textForm->caret->GetX() - width, textForm->fontHeight*rowIndex, (CString)word.c_str());
}
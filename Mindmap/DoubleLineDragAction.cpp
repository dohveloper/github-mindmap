//DoubleLineDragAction.cpp

#include "DoubleLineDragAction.h"
#include "TextDrag.h"
#include "TextForm.h"
#include "SelectText.h"
#include "Text.h"
#include "Caret.h"
#include <string>
using namespace std;

DoubleLineDragAction::DoubleLineDragAction() {

}

DoubleLineDragAction::~DoubleLineDragAction() {

}

void DoubleLineDragAction::DragUp(TextForm *textForm, CDC *cdc) {
	Long startRowIndex;
	Long endRowIndex;
	string startWord;
	string endWord;
	Long start;
	Long end;
	Long width;
	CSize size;
	Long i = 0;

	startRowIndex = textForm->selectText->GetStartRowIndex();
	endRowIndex = textForm->selectText->GetEndRowIndex();
	start = textForm->selectText->GetStartCharacterIndex();
	end = textForm->selectText->GetEndCharacterIndex();
	
	startWord = textForm->text->GetAt(startRowIndex)->MakeString(0, start);
	
	cdc->TextOut(0, startRowIndex*textForm->fontHeight, (CString)startWord.c_str());

	endWord = textForm->text->GetAt(endRowIndex)->MakeString(end, textForm->text->GetAt(endRowIndex)->GetLength());

	width = cdc->GetTextExtent((CString)textForm->text->GetAt(endRowIndex)->MakeString().c_str()).cx;
	size = cdc->GetTextExtent((CString)endWord.c_str());

	cdc->TextOut(width - size.cx, endRowIndex*textForm->fontHeight, (CString)endWord.c_str());
}

void DoubleLineDragAction::DragDown(TextForm *textForm, CDC *cdc) {
	Long startRowIndex;
	Long endRowIndex;
	string startWord;
	string endWord;
	Long start;
	Long end;
	Long width;
	CSize size;
	Long i = 0;

	startRowIndex = textForm->selectText->GetStartRowIndex();
	endRowIndex = textForm->selectText->GetEndRowIndex();
	start = textForm->selectText->GetStartCharacterIndex();
	end = textForm->selectText->GetEndCharacterIndex();

	startWord = textForm->text->GetAt(startRowIndex)->MakeString(start, textForm->text->GetAt(startRowIndex)->GetLength());

	width = cdc->GetTextExtent((CString)textForm->text->GetAt(startRowIndex)->MakeString().c_str()).cx;
	size = cdc->GetTextExtent((CString)startWord.c_str());
	cdc->TextOut(width - size.cx, startRowIndex*textForm->fontHeight, (CString)startWord.c_str());

	endWord = textForm->text->GetAt(endRowIndex)->MakeString(0, end);

	cdc->TextOut(0, endRowIndex*textForm->fontHeight, (CString)endWord.c_str());
}
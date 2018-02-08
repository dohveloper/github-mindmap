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
	while (i < start)
	{
		if (textForm->text->GetAt(startRowIndex)->GetAt(i)->MakeString().compare("\t") == 0)
		{
			startWord += "        ";
		}
		else
		{
			startWord += textForm->text->GetAt(startRowIndex)->GetAt(i)->MakeString();
		}
		i++;
	}
	cdc->TextOut(0, startRowIndex*textForm->fontHeight, (CString)startWord.c_str());

	i = end;
	while (i < textForm->text->GetAt(endRowIndex)->GetLength())
	{
		if (textForm->text->GetAt(endRowIndex)->GetAt(i)->MakeString().compare("\t") == 0)
		{
			endWord += "        ";
		}
		else
		{
			endWord += textForm->text->GetAt(endRowIndex)->GetAt(i)->MakeString();
		}
		i++;
	}
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

	i = start;
	while (i < textForm->text->GetAt(startRowIndex)->GetLength())
	{
		if (textForm->text->GetAt(startRowIndex)->GetAt(i)->MakeString().compare("\t") == 0)
		{
			startWord += "        ";
		}
		else
		{
			startWord += textForm->text->GetAt(startRowIndex)->GetAt(i)->MakeString();
		}
		i++;
	}
	width = cdc->GetTextExtent((CString)textForm->text->GetAt(startRowIndex)->MakeString().c_str()).cx;
	size = cdc->GetTextExtent((CString)startWord.c_str());
	cdc->TextOut(width - size.cx, startRowIndex*textForm->fontHeight, (CString)startWord.c_str());

	i = 0;
	while (i < end)
	{
		if (textForm->text->GetAt(endRowIndex)->GetAt(i)->MakeString().compare("\t") == 0)
		{
			endWord += "        ";
		}
		else
		{
			endWord += textForm->text->GetAt(endRowIndex)->GetAt(i)->MakeString();
		}
		i++;
	}
	cdc->TextOut(0, endRowIndex*textForm->fontHeight, (CString)endWord.c_str());
}
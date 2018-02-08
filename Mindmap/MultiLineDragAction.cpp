//MultiLineDragAction.cpp

#include "MultiLineDragAction.h"
#include "TextDrag.h"
#include "TextForm.h"
#include "SelectText.h"
#include "Text.h"
#include "Caret.h"
#include <string>
using namespace std;

MultiLineDragAction::MultiLineDragAction() {

}

MultiLineDragAction::~MultiLineDragAction() {

}

void MultiLineDragAction::DragDown(TextForm *textForm, CDC *cdc) {
	Long startRowIndex;
	Long endRowIndex;
	string startWord;
	string middleWord;
	string endWord;
	Long start;
	Long end;
	Long width;
	CSize size;
	Long x = 0;
	Long y = 0;

	startRowIndex = textForm->selectText->GetStartRowIndex();
	endRowIndex = textForm->selectText->GetEndRowIndex();
	start = textForm->selectText->GetStartCharacterIndex();
	end = textForm->selectText->GetEndCharacterIndex();
	y = startRowIndex;
	//start line
	x = start;
	while (x < textForm->text->GetAt(startRowIndex)->GetLength())
	{
		if (textForm->text->GetAt(startRowIndex)->GetAt(x)->MakeString().compare("\t") == 0)
		{
			startWord += "        ";
		}
		else
		{
			startWord += textForm->text->GetAt(startRowIndex)->GetAt(x)->MakeString();
		}
		x++;
	}
	width = cdc->GetTextExtent((CString)textForm->text->GetAt(startRowIndex)->MakeString().c_str()).cx;
	size = cdc->GetTextExtent((CString)startWord.c_str());
	cdc->TextOut(width - size.cx, startRowIndex*textForm->fontHeight, (CString)startWord.c_str());

	//middle line
	y++;
	while (y < endRowIndex)
	{
		middleWord = textForm->text->GetAt(y)->MakeString();
		cdc->TextOut(0, y*textForm->fontHeight, (CString)middleWord.c_str());
		y++;
	}

	//end line
	x = 0;
	while (x < end)
	{
		if (textForm->text->GetAt(endRowIndex)->GetAt(x)->MakeString().compare("\t") == 0)
		{
			endWord += "        ";
		}
		else
		{
			endWord += textForm->text->GetAt(endRowIndex)->GetAt(x)->MakeString();
		}
		x++;
	}
	cdc->TextOut(0, endRowIndex*textForm->fontHeight, (CString)endWord.c_str());
}

void MultiLineDragAction::DragUp(TextForm *textForm, CDC *cdc) {
	Long startRowIndex;
	Long endRowIndex;
	string startWord;
	string middleWord;
	string endWord;
	Long start;
	Long end;
	Long width;
	CSize size;
	Long x = 0;
	Long y = 0;

	startRowIndex = textForm->selectText->GetStartRowIndex();
	endRowIndex = textForm->selectText->GetEndRowIndex();
	start = textForm->selectText->GetStartCharacterIndex();
	end = textForm->selectText->GetEndCharacterIndex();

	// start line
	while (x < start)
	{
		if (textForm->text->GetAt(startRowIndex)->GetAt(x)->MakeString().compare("\t") == 0)
		{
			startWord += "        ";
		}
		else
		{
			startWord += textForm->text->GetAt(startRowIndex)->GetAt(x)->MakeString();
		}
		x++;
	}
	size = cdc->GetTextExtent((CString)startWord.c_str());
	cdc->TextOut(0, startRowIndex*textForm->fontHeight, (CString)startWord.c_str());

	//middle line
	y = startRowIndex - 1;
	while (y > endRowIndex && y > 0)
	{
		middleWord = textForm->text->GetAt(y)->MakeString();
		cdc->TextOut(0, y*textForm->fontHeight, (CString)middleWord.c_str());
		y--;
	}

	//end line
	x = end;
	while (x < textForm->text->GetAt(endRowIndex)->GetLength())
	{
		if (textForm->text->GetAt(endRowIndex)->GetAt(x)->MakeString().compare("\t") == 0)
		{
			endWord += "        ";
		}
		else
		{
			endWord += textForm->text->GetAt(endRowIndex)->GetAt(x)->MakeString();
		}
		x++;
	}
	width = cdc->GetTextExtent((CString)textForm->text->GetAt(endRowIndex)->MakeString().c_str()).cx;
	size = cdc->GetTextExtent((CString)endWord.c_str());
	cdc->TextOut(width - size.cx, endRowIndex*textForm->fontHeight, (CString)endWord.c_str());
}
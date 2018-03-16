//WriteVisitor.cpp

#include "WriteVisitor.h"
#include "Row.h"
#include "Text.h"
#include "Caret.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
#include <afxdb.h>  
#include "TextFont.h"
#include "string"
using namespace std;

WriteVisitor::WriteVisitor() {
	this->dc = NULL;
	this->textForm = NULL;
	this->rowIndex = 0;
}

WriteVisitor::WriteVisitor(CPaintDC *dc, TextForm *textForm) {
	this->dc = dc;
	this->textForm = textForm;
}

WriteVisitor::~WriteVisitor() {

}

void WriteVisitor::VisitText(Text *text) {
	string word;
	Long i = 0;
	Long length;
	
	length = text->GetLength();

	while (i < length) {
		word = text->GetAt(i)->MakeString();

		this->dc->TextOut(0, this->textForm->textFont->GetHeight() * i, (CString)word.c_str());
		i++;
	}
}

void WriteVisitor::VisitRow(Row *row) {
	/*
	Long i = 0;
	Long length;
	string word;
	string temp;
	Long tabIndex;
	CString x;

	length = row->GetLength();

	while (i < length) {
		if (row->GetAt(i)->MakeString().compare("\t")==0)
		{
			word += "        ";
		}
		else
		{
			temp = row->GetAt(i)->MakeString();

			word += temp;
		}
		i++;
	}
	dc->TextOut(0, this->rowIndex*this->textForm->fontHeight, (CString)word.c_str());
	*/
}

void WriteVisitor::VisitSingleByteCharacter(SingleByteCharacter *singleByteCharacter) {
	//CSize size = dc->GetTextExtent((CString)singleByteCharacter->MakeString().c_str());
}
void WriteVisitor::VisitDoubleByteCharacter(DoubleByteCharacter *doubleByteCharacter) {
	//CSize size = dc->GetTextExtent((CString)doubleByteCharacter->MakeString().c_str());
}
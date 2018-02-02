//WriteVisitor.cpp

#include "WriteVisitor.h"
#include "TextForm.h"
#include "Row.h"
#include "Text.h"
#include "Caret.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
#include <afxdb.h>  
#include "string"
using namespace std;

WriteVisitor::WriteVisitor() {
	this->dc = NULL;
	this->caret = NULL;
	this->textForm = NULL;
}

WriteVisitor::WriteVisitor(CPaintDC *dc,Caret *caret,TextForm *textForm) {
	this->dc = dc;
	this->caret = caret;
	this->textForm = textForm;
}

WriteVisitor::~WriteVisitor() {

}

void WriteVisitor::VisitText(Text *text) {
	Long i = 0;
	Long length;

	length = text->GetLength();

	while (i < length) {
		text->GetAt(i)->Accept(*this);
		i++;
	}
}

void WriteVisitor::VisitRow(Row *row) {
	string word;
	Long i = 0;
	Long length;

	length = row->GetLength();
	
	while (i < length) {
		word += row->GetAt(i)->MakeString();
		i++;
	}
	this->dc->TextOut(0, this->textForm->fontHeight * this->textForm->text->GetLength()-1, (CString)word.c_str());
}
void WriteVisitor::VisitSingleByteCharacter(SingleByteCharacter *singleByteCharacter) {
	CSize size = dc->GetTextExtent((CString)singleByteCharacter->MakeString().c_str());

	dc->TextOut(this->caret->GetCharacterIndex()*size.cx,this->caret->GetRowIndex()*size.cy,(CString)singleByteCharacter->MakeString().c_str());
}
void WriteVisitor::VisitDoubleByteCharacter(DoubleByteCharacter *doubleByteCharacter) {
	CSize size = dc->GetTextExtent((CString)doubleByteCharacter->MakeString().c_str());

	dc->TextOut(this->caret->GetCharacterIndex()*size.cx, this->caret->GetRowIndex()*size.cy, (CString)doubleByteCharacter->MakeString().c_str());
}
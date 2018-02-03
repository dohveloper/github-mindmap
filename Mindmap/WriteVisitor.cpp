//WriteVisitor.cpp

#include "WriteVisitor.h"
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
	this->textForm = NULL;
	this->rowIndex = 0;
}

WriteVisitor::WriteVisitor(CPaintDC *dc,TextForm *textForm) {
	this->dc = dc;
	this->textForm = textForm;
}

WriteVisitor::~WriteVisitor() {

}

void WriteVisitor::VisitText(Text *text) {
	Long i = 0;
	Long length;

	length = text->GetLength();

	while (i < length) {
		this->rowIndex = i;
		text->GetAt(i)->Accept(*this);
		i++;
	}
}

void WriteVisitor::VisitRow(Row *row) {
	Long i = 0;
	Long length;
	string word;
	string temp;
	
	length = row->GetLength();

	while (i < length) {
		temp=row->GetAt(i)->MakeString();
		if (temp == "\t")
		{
			word += "        ";
		}
		else
		{
			word += temp;
		}
		i++;
	}
	dc->TextOut(0, this->rowIndex*this->textForm->fontHeight, (CString)word.c_str());
}

void WriteVisitor::VisitSingleByteCharacter(SingleByteCharacter *singleByteCharacter) {
	CSize size = dc->GetTextExtent((CString)singleByteCharacter->MakeString().c_str());


}
void WriteVisitor::VisitDoubleByteCharacter(DoubleByteCharacter *doubleByteCharacter) {
	CSize size = dc->GetTextExtent((CString)doubleByteCharacter->MakeString().c_str());


}
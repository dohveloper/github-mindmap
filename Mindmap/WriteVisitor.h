//WriteVisitor.h

#ifndef _WRITEVISITOR_H
#define _WRITEVISITOR_H

#include "TextVisitor.h"
#include <afxwin.h>

class TextForm;
class Caret;
class WriteVisitor :public TextVisitor {
public:
	WriteVisitor();
	WriteVisitor(CPaintDC *dc, Caret *caret,TextForm *textForm);
	virtual ~WriteVisitor();
	virtual void VisitText(Text *text);
	virtual void VisitRow(Row *row);
	virtual void VisitSingleByteCharacter(SingleByteCharacter *singleByteCharacter);
	virtual void VisitDoubleByteCharacter(DoubleByteCharacter *doubleByteCharacter);
private:
	CPaintDC *dc;
	Caret *caret;
	TextForm *textForm;
};

#endif //WRITEVISITOR_H
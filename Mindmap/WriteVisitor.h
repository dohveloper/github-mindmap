//WriteVisitor.h

#ifndef _WRITEVISITOR_H
#define _WRITEVISITOR_H

#include "TextVisitor.h"
#include <afxwin.h>

typedef signed long int Long;

class TextForm;
class WriteVisitor :public TextVisitor {
public:
	WriteVisitor();
	WriteVisitor(CPaintDC *dc,TextForm *textForm);
	virtual ~WriteVisitor();
	virtual void VisitText(Text *text);
	virtual void VisitRow(Row *row);
	virtual void VisitSingleByteCharacter(SingleByteCharacter *singleByteCharacter);
	virtual void VisitDoubleByteCharacter(DoubleByteCharacter *doubleByteCharacter);
private:
	CPaintDC *dc;
	TextForm *textForm;
	Long rowIndex;
};

#endif //WRITEVISITOR_H
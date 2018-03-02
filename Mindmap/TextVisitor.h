//TextVisitor.h

#ifndef _TEXTVISITOR_H
#define _TEXTVISITOR_H

class Text;
class Row;
class SingleByteCharacter;
class DoubleByteCharacter;
class TextVisitor {
public:
	virtual ~TextVisitor();
	virtual void VisitText(Text *text);
	virtual void VisitRow(Row *row);
	virtual void VisitSingleByteCharacter(SingleByteCharacter *singleByteCharacter);
	virtual void VisitDoubleByteCharacter(DoubleByteCharacter *doubleByteCharacter);
protected:
	TextVisitor();

};
#endif //_TEXTVISITOR_H
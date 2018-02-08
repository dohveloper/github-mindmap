//Caret.h

#ifndef _CARET_H
#define _CARET_H
#include "afxwin.h"
#include "TextForm.h"

class TextForm;
class Caret {
public:
	Caret();
	Caret(const Caret& source);
	~Caret();

	Caret* MoveToIndex(TextForm *textForm, CDC *cdc);
	Caret* MoveToPoint(TextForm *textForm, CDC *cdc, CPoint point);


	void MoveToRight(Long index=1);
	void MoveToLeft(Long index=1);
	void MoveToUp(Long index=1);
	void MoveToDown(Long index=1);

	Long SetCharacterIndex(Long index);
	Long CheckStartCharacterIndex(TextForm *textForm);
	Long CheckEndCharacterIndex(TextForm *textForm);
	Long SetRowIndex(Long index);
	Caret& operator=(const Caret& source);

	Long GetX() const;
	Long GetY() const;
	Long GetCharacterIndex() const;
	Long GetRowIndex() const;
private:
	Long characterIndex;
	Long rowIndex;
	Long currentX;
	Long currentY;
};

inline Long Caret::GetX() const {
	return this->currentX;
}
inline Long Caret::GetY() const {
	return this->currentY;
}
inline Long Caret::GetCharacterIndex() const {
	return this->characterIndex;
}
inline Long Caret::GetRowIndex() const {
	return this->rowIndex;
}

#endif //_CARET_H
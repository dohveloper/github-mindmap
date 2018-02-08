//SelectText.h

#ifndef _SELECTTEXT_H
#define _SELECTTEXT_H

#include "afxwin.h"

class TextForm;
class SelectText {
public:
	SelectText();
	SelectText(const SelectText& source);
	~SelectText();

	void TextDragAction(TextForm *textForm, CDC *cdc, CPoint point);
	void TextDoubleClickAction(TextForm *textForm, CDC *cdc);

	SelectText& operator=(const SelectText& source);

	Long SetStartCharacterIndex(Long index);
	Long SetStartRowIndex(Long index);
	Long SetEndCharacterIndex(Long index);
	Long SetEndRowIndex(Long index);

	Long GetStartCharacterIndex() const;
	Long GetStartRowIndex() const;
	Long GetEndCharacterIndex() const;
	Long GetEndRowIndex() const;
private:
	//시작
	Long startCharacterIndex;
	Long startRowIndex;
	//마지막
	Long endCharacterIndex;
	Long endRowIndex;
};

inline Long SelectText::GetStartCharacterIndex() const {
	return this->startCharacterIndex;
}

inline Long SelectText::GetStartRowIndex() const {
	return this->startRowIndex;
}
inline Long SelectText::GetEndCharacterIndex() const {
	return this->endCharacterIndex;
}

inline Long SelectText::GetEndRowIndex() const {
	return this->endRowIndex;
}

#endif //_SELECTTEXT_H
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
	void TextDoubleClickAction(TextForm *textForm, CDC *cdc, CPoint point);

	SelectText& operator=(const SelectText& source);

	Long SetStartCharacterIndex(Long index);
	Long SetStartRowIndex(Long index);
	Long SetEndCharacterIndex(Long index);
	Long SetEndRowIndex(Long index);
	void SetIsSelect();
	void SetIsNotSelect();

	Long GetStartCharacterIndex() const;
	Long GetStartRowIndex() const;
	Long GetEndCharacterIndex() const;
	Long GetEndRowIndex() const;
	bool GetIsSelect() const;
private:
	//����
	Long startCharacterIndex;
	Long startRowIndex;
	//������
	Long endCharacterIndex;
	Long endRowIndex;

	bool IsSelect;
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

inline bool SelectText::GetIsSelect() const {
	return this->IsSelect;
}

#endif //_SELECTTEXT_H
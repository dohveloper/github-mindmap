//TextForm.h

#ifndef _TEXTFORM_H
#define _TEXTFORM_H

typedef signed long int Long;

#include <afxwin.h>

class SelectText;
class Caret;
class Row;
class Text;
class TextFormSize;
class WriteKorean;
class WriteEnglish;
class TextFont;
class TextForm :public CWnd {
public:
	TextForm();
	BOOL PreTranslateMessage(MSG* pMsg);
	bool OnComposition(LPARAM lParam);
	bool OnChar(WPARAM wParam);
	bool OnNotify();
	void OnKeyDown(WPARAM wParam);
public:
	Text *text;
	Caret *caret;
	SelectText *selectText;
	TextFormSize *textFormSize;
	WriteKorean *writeKorean;
	WriteEnglish *writeEnglish;
	TextFont *textFont;
	bool hangul;
	bool compose;
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()	
};
#endif //_TEXTFORM_H
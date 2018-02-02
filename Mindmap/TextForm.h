//TextForm.h

#ifndef _TEXTFORM_H
#define _TEXTFORM_H

typedef signed long int Long;

#include <afxwin.h>

class SelectText;
class Caret;
class Row;
class Text;
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
	bool hangul;
	bool compose;
	Long fontWidth;
	Long fontHeight;
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()
};
#endif //_TEXTFORM_H
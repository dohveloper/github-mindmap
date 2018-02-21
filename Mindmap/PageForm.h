//PageForm.h

#ifndef _PAGEFORM_H
#define _PAGEFORM_H

#include <afxwin.h>
#include <string>
#include "Array.h"
#include "Selection.h"

using namespace std;

typedef signed long int Long;
class Page;
class Branch;
class MouseAction;
class ScrollAction;
class PageForm :public CFrameWnd {
public:
	PageForm();
	void SetScrolls();
	CPoint GetRealPoint(CPoint point);
public:
	Branch * branch;
	Selection selection;
	MouseAction *mouseAction;
	ScrollAction *scrollAction;
	Long movedX;
	Long movedY;
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

#endif //_PAGEFORM_H

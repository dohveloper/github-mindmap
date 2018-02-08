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

class PageForm :public CFrameWnd {
public:
	PageForm();
public:
	Branch * branch;
	Selection selection;
	MouseAction *mouseAction;

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()
};

#endif //_PAGEFORM_H

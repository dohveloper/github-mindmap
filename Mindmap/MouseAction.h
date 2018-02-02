#ifndef _MOUSEACTION_H
#define _MOUSEACTION_H
#include "Branch.h"
#include <afxwin.h>

class Selection;
class MouseStrategy;

class MouseAction {
public:
	MouseAction(MouseStrategy *mouseStrategy);
	void OnLButtonDown(CPoint point, UINT flags,Selection *selection, Branch *branch);
	void OnMouseMove(CPoint point);
	void OnLButtonUp(Selection *selection,bool isOverlapped);
	
	void SetStrategy(Branch* clickedBranch);

	
private:
	MouseStrategy *mouseStrategy;

};

#endif _MOUSEACTION_H

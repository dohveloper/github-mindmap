#ifndef _MOUSEACTION_H
#define _MOUSEACTION_H
#include "Branch.h"
#include "Selection.h"
#include <afxwin.h>

template<typename T> class Array;
class MouseStrategy;

class MouseAction {
public:
	MouseAction(MouseStrategy *mouseStrategy) {
		this->mouseStrategy = NULL;
	}
	void OnLButtonDown(CPoint point, UINT flags,Selection *selection, Branch *branch);
	void OnMouseMove(CPoint point);
	void OnLButtonUp(Selection *selection,bool isOverlapped);
	
	void SetStrategy(Branch* clickedBranch);

	
private:
	MouseStrategy * mouseStrategy;

};

#endif

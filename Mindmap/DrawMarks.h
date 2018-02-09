#ifndef _DRAWMARKS_H
#define _DRAWMARKS_H
#include "BranchTraverser.h"
#include <afxwin.h>

class DrawMarks :public BranchTraverser {
public:
	DrawMarks(Branch *branch, CPaintDC *dc);

protected:
	virtual bool ProcessItem(Shape*);

private:
	CPaintDC * dc;
};

#endif // _DRAWMARKS_H
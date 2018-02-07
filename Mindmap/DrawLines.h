#ifndef _DRAWLINES_H
#define _DRAWLINES_H
#include "BranchTraverser.h"
#include <afxwin.h>

class DrawLines :public BranchTraverser{
public:
	DrawLines(Branch *branch, CPaintDC *dc);

protected:
	virtual bool ProcessItem(Shape*);
	

private:
	CPaintDC *dc;
};

#endif _DRAWLINES_H
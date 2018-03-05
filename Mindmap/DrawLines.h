#ifndef _DRAWLINES_H
#define _DRAWLINES_H
#include "BranchTraverser.h"
#include <afxwin.h>
typedef signed long int Long;

class DrawLines :public BranchTraverser {
public:
	DrawLines(Branch *branch, CPaintDC *dc, Long movedX, Long movedY);

protected:
	virtual bool ProcessItem(Shape* shape);

private:
	CPaintDC * dc;
	Long movedX;
	Long movedY;
};

#endif _DRAWLINES_H
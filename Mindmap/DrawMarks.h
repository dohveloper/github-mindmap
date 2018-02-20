#ifndef _DRAWMARKS_H
#define _DRAWMARKS_H
#include "BranchTraverser.h"
#include <afxwin.h>
typedef signed long int Long;

class DrawMarks :public BranchTraverser {
public:
	DrawMarks(Branch *branch, CPaintDC *dc, Long movedX, Long movedY);

protected:
	virtual bool ProcessItem(Shape*);

private:
	CPaintDC * dc;
	Long movedX;
	Long movedY;
};

#endif // _DRAWMARKS_H
#ifndef _DRAWMARKS_H
#define _DRAWMARKS_H
#include "BranchTraverser.h"
#include <afxwin.h>
typedef signed long int Long;

class View;

class DrawMarks :public BranchTraverser {
public:
	DrawMarks(Branch *branch, CDC *dc, View *view);

protected:
	virtual bool ProcessItem(Shape*);

private:
	CDC * dc;
	View *view;
};

#endif // _DRAWMARKS_H
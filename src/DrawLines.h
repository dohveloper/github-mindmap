#ifndef _DRAWLINES_H
#define _DRAWLINES_H
#include "BranchTraverser.h"
#include <afxwin.h>
typedef signed long int Long;

class View;

class DrawLines :public BranchTraverser {
public:
	DrawLines(Branch *branch, CDC *dc, View *view);

protected:
	virtual bool ProcessItem(Shape* shape);

private:
	CDC * dc;
	View *view;
};

#endif _DRAWLINES_H
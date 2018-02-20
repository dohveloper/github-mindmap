#ifndef _DRAWTOPICS_H
#define _DRAWTOPICS_H
#include "BranchTraverser.h"
#include <afxwin.h>

class DrawTopics :public BranchTraverser {
public:
	DrawTopics(Branch *branch, CPaintDC *dc);

protected:
	virtual bool ProcessItem(Shape*);


private:
	CPaintDC * dc;
};

#endif // _DRAWTOPICS_H
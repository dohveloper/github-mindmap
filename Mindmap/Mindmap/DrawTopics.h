#ifndef _DRAWTOPICS_H
#define _DRAWTOPICS_H
#include "BranchTraverser.h"
#include <afxwin.h>
typedef signed long int Long;

class DrawTopics :public BranchTraverser {
public:
	DrawTopics(Branch *branch, CPaintDC *dc, Long movedX, Long movedY);

protected:
	virtual bool ProcessItem(Shape*);


private:
	CPaintDC * dc;
	Long movedX;
	Long movedY;
};

#endif // _DRAWTOPICS_H
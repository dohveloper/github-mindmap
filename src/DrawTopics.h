#ifndef _DRAWTOPICS_H
#define _DRAWTOPICS_H
#include "BranchTraverser.h"
#include <afxwin.h>
typedef signed long int Long;

class View;
class DrawTopics :public BranchTraverser {
public:
	DrawTopics(Branch *branch, CDC *dc, View *view);

protected:
	virtual bool ProcessItem(Shape*);

private:
	CDC * dc;
	View *view;
};

#endif // _DRAWTOPICS_H
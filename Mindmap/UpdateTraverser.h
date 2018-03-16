#ifndef _UPDATETRAVERSER_H
#define _UPDATETRAVERSER_H
#include "BranchTraverser.h"
typedef signed long int Long;

class Branch;
class UpdateTraverser :public BranchTraverser {
public:
	UpdateTraverser(Branch *before, Branch *after);

protected:
	virtual bool ProcessItem(Shape* shape);

private:
	Branch * after;
};

#endif _UPDATETRAVERSER_H

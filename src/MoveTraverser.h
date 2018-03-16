#ifndef _MOVETRAVERSER_H
#define _MOVETRAVERSER_H
#include "BranchTraverser.h"
typedef signed long int Long;

class Branch;
class MoveTraverser :public BranchTraverser {
public:
	MoveTraverser(Branch *branch, Long x, Long y);

protected:
	virtual bool ProcessItem(Shape* shape);
private:
	Long x;
	Long y;
};

#endif _MOVETRAVERSER_H

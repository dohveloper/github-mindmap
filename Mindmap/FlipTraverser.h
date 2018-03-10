#ifndef _FLIPTRAVERSER_H
#define _FLIPTRAVERSER_H
#include "BranchTraverser.h"
typedef signed long int Long;

class Branch;
class FlipTraverser :public BranchTraverser {
public:
	FlipTraverser(Branch *branch, Long centerX);

protected:
	virtual bool ProcessItem(Shape* shape);
private:
	Long centerX;
};

#endif _FLIPTRAVERSER_H
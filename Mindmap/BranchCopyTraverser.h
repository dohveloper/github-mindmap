#ifndef _BRANCHCOPYTRAVERSER_H
#define _BRANCHCOPYTRAVERSER_H
#include "BranchTraverser.h"
typedef signed long int Long;

class Branch;
class BranchCopyTraverser :public BranchTraverser {
public:
	BranchCopyTraverser(Branch *branch);

	Branch* GetClone() const;

protected:
	virtual bool ProcessItem(Shape* shape);

private:
	Branch * clone;
};
inline Branch* BranchCopyTraverser::GetClone() const {
	return const_cast<Branch*>(this->clone);
}

#endif _BRANCHCOPYTRAVERSER_H
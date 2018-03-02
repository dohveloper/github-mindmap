#ifndef _BRANCHCOPYTRAVERSER_H
#define _BRANCHCOPYTRAVERSER_H
#include "BranchTraverser.h"
typedef signed long int Long;

class Branch;
class BranchCopyTraverser :public BranchTraverser {
public:
	BranchCopyTraverser(Branch *branch);

	Branch* GetCopiedBranch() const;

protected:
	virtual bool ProcessItem(Shape* shape);

private:
	Branch * copiedBranch;
};
inline Branch* BranchCopyTraverser::GetCopiedBranch() const {
	return const_cast<Branch*>(this->copiedBranch);
}

#endif _BRANCHCOPYTRAVERSER_H
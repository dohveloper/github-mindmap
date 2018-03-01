//BranchArray.h

#ifndef _BRANCHARRAY_H
#define _BRANCHARRAY_H
#include "Branch.h"

class BranchArray {
public:
	BranchArray(Long capacity = 256);
	BranchArray(const BranchArray& source);
	~BranchArray();

	Long Add(Branch *branch);
	Long Remove(Branch *branch);
	Branch* GetLastBranchArray();
	Branch* GetAt(Long index);

	BranchArray& operator=(const BranchArray& source);

	Array<Branch*> GetBranches() const;
	Long GetCapacity() const;
	Long GetLength() const;
public:
	Array<Branch*> branches;
private:

	Long capacity;
	Long length;
};

inline Array<Branch*> BranchArray::GetBranches() const
{
	return this->branches;
}

inline Long BranchArray::GetCapacity() const {
	return this->capacity;
}

inline Long BranchArray::GetLength() const {
	return this->length;
}
int CompareBranchLinkes(void *one, void *other);

#endif //_BRANCHARRAY_H

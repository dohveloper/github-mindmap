#ifndef _SELECTION_H
#define _SELECTION_H
#include "Branch.h"

class Selection {
public:
	Selection(Long capacity = 256);
	Selection(const Selection& source);
	~Selection();

	Long Add(Branch *branch);
	Long Remove(Branch *branch);
	Long RemoveSubBranch(Branch *branch);
	void Clear();
	Branch* GetLastSelection();
	Branch* GetAt(Long index);
	bool IsSelected(Branch *branch);

	Selection& operator=(const Selection& source);

	Long GetCapacity() const;
	Long GetLength() const;

private:
	Array<Branch*> selections;
	Long capacity;
	Long length;
};

inline Long Selection::GetCapacity() const {
	return this->capacity;
}

inline Long Selection::GetLength() const {
	return this->length;
}
int CompareBranches(void *one, void *other);

#endif //_SELECTION_H

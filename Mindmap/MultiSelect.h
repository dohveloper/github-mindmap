//MultiSelect.h

#ifndef _MULTISELECT_H
#define _MULTISELECT_H
#include "Select.h"

class MultiSelect : public Select
{
public:
	MultiSelect();
	MultiSelect(const MultiSelect& source);
	virtual ~MultiSelect();
	virtual void SelectBranch(Selection *selection, Branch *branch);
	MultiSelect& operator=(const MultiSelect& source);

};

#endif // !_MULTISELECT_H

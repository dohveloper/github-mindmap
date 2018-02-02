//SingleSelect.h

#ifndef _SINGLESELECT_H
#define _SINGLESELECT_H
#include "Select.h"

class SingleSelect : public Select
{
public:
	SingleSelect();
	SingleSelect(const SingleSelect& source);
	virtual ~SingleSelect();
	virtual void SelectBranch(Selection *selection, Branch *branch);
	SingleSelect& operator=(const SingleSelect& source);

};

#endif // !_SINGLESELECT_H

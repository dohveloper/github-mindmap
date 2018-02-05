//Select.h

#ifndef _SELECT_H
#define _SELECT_H

class Branch;
class Selection;
class Select
{
public:
	Select();
	Select(const Select& source);
	virtual ~Select() = 0;
	virtual void SelectBranch(Selection *selectChoiceion, Branch *branch);
	Select& operator=(const Select& source);


};

#endif // !SELECT_H

//SearchVisitor.h

#ifndef	_SEARCHVISITOR_H
#define _SEARCHVISITOR_H
#include "ShapeVisitor.h"
#include <afxwin.h>
typedef signed long int Long;


class Branch;
class BranchArray;
class SearchVisitor : public ShapeVisitor
{
public:
	SearchVisitor();
	SearchVisitor(BranchArray *branchArray);
	virtual ~SearchVisitor();
	virtual void VisitBranch(Branch *branch);


private:
	BranchArray *branchArray;
};


#endif // _SEARCHVISITOR_H

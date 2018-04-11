//SearchVisitor.h

#ifndef	_SEARCHVISITOR_H
#define _SEARCHVISITOR_H
#include "ShapeVisitor.h"
#include <afxwin.h>
typedef signed long int Long;


class Branch;
//class BranchArray;
class PageForm;
class SearchVisitor : public ShapeVisitor
{
public:
	SearchVisitor();
	SearchVisitor(PageForm *pageForm);
	virtual ~SearchVisitor();
	virtual void VisitBranch(Branch *branch);


private:
	PageForm *pageForm;
};


#endif // _SEARCHVISITOR_H

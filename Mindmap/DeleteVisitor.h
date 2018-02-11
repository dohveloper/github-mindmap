//DeleteVisitor.h

#ifndef	DELETEVISITOR_H
#define DELETEVISITOR_H
#include "ShapeVisitor.h"
#include <afxwin.h>
typedef signed long int Long;


class Branch;
class DeleteVisitor : public ShapeVisitor
{
public:
	DeleteVisitor();
	DeleteVisitor(Branch *select);
	void TakeBranch(Branch *select);
	virtual ~DeleteVisitor();
	virtual void VisitBranch(Branch *branch);


private:
	Branch * select;
};


#endif // DELETEVISITOR_H

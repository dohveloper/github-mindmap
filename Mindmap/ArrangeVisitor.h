//ArrangeVisitor.h

#ifndef ARRANGEVISITOR_H
#define ARRANGEVISITOR_H
#include "ShapeVisitor.h"
#include <afxwin.h>
typedef signed long int Long;

class Branch;
class ArrangeVisitor : public ShapeVisitor
{
public:
	ArrangeVisitor();
	ArrangeVisitor(Long x);
	~ArrangeVisitor();
	virtual void VisitBranch(Branch *branch);
	Long GetX() const;
private:
	Long x;
};
inline Long ArrangeVisitor::GetX() const {
	return this->x;
}
#endif // !ARRANGEVISITOR_H



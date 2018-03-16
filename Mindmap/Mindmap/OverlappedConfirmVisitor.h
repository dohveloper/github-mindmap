//OverlappedConfirmVisitor.h

#ifndef OVERLAPPEDCONFIRMVISITOR_H
#define OVERLAPPEDCONFIRMVISITOR_H
#include "ShapeVisitor.h"
#include <afxwin.h>

class Branch;
class OverlappedConfirmVisitor: public ShapeVisitor
{
public:
	OverlappedConfirmVisitor();
	OverlappedConfirmVisitor(CRect rectA, CRect rectB = NULL);
	virtual ~OverlappedConfirmVisitor();
	virtual void VisitBranch(Branch *branch);

	bool GetIsOverlapped() const;
private:
	CRect rectA;
	CRect rectB;
	bool isOverlapped;
};

inline bool OverlappedConfirmVisitor::GetIsOverlapped() const
{
	return this->isOverlapped;
}

#endif // !OVERLAPPEDCONFIRMVISITOR_H

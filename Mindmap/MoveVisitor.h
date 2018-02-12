#ifndef _MOVEVISITOR_H
#define _MOVEVISITOR_H
#include "ShapeVisitor.h"
#include <afxwin.h>

typedef signed long int Long;
class Topic;
class Line;
class Branch;
class Mark;

class MoveVisitor : public ShapeVisitor {
public:
	MoveVisitor(Long x, Long y);
	virtual ~MoveVisitor();
	virtual void VisitLine(Line *line);
	virtual void VisitTopic(Topic *topic);
	virtual void VisitMark(Mark *mark);
	virtual void VisitBranch(Branch *branch);

private:
	Long x;
	Long y;
};

#endif _MOVEVISITOR_H

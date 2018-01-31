#ifndef _SHAPEVISITOR_H
#define _SHAPEVISITOR_H
class Topic;
class Line;
class Branch;
class ShapeVisitor {
public:
	virtual ~ShapeVisitor() = 0;
	virtual void VisitTopic(Topic *topic);
	virtual void VisitLine(Line *line);
	virtual void VisitBranch(Branch *branch);


protected:
	ShapeVisitor();

};

#endif _SHAPEVISITOR_H
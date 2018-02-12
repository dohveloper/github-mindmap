#include "MoveVisitor.h"
#include "Topic.h"
#include "Line.h"
#include "Branch.h"
#include "Mark.h"
#include "MouseAction.h"
#include "SelectionStrategy.h"
#include "Shape.h"

MoveVisitor::MoveVisitor(Long x, Long y) {
	this->x = x;
	this->y = y;
}

MoveVisitor::~MoveVisitor() {
}

void MoveVisitor::VisitLine(Line *line)
{
	Long X;
	Long y;
	x = line->GetX();
	y = line->GetY();

	line->SetX(x + this->x);
	line->SetY(y + this->y);
}

void MoveVisitor::VisitTopic(Topic *topic) {
	Long X;
	Long y;
	x = topic->GetX();
	y = topic->GetY();

	topic->SetX(x + this->x);
	topic->SetY(y + this->y);
}

void MoveVisitor::VisitMark(Mark * mark)
{
	Long X;
	Long y;
	x = mark->GetX();
	y = mark->GetY();

	mark->SetX(x + this->x);
	mark->SetY(y + this->y);
}

void MoveVisitor::VisitBranch(Branch *branch)
{
	Long length;
	Long i = 0;
	Shape *current;

	length = branch->GetLength();

	while (i < length)
	{
		current = branch->GetAt(i);
		current->Accept(*this);
		i++;
	}
}
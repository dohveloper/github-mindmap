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

#include <iostream>
#include "Mark.h"
#include "Topic.h"
#include "Line.h"
int main(int argc, char *argv[]) {
	Topic topic(1000, 1000, 1000, 1000, "토픽");
	Line line(10, 10, 10, 10, "라인");
	Mark mark(1, 1, 1, 1, "마크");
	Branch branch;

	branch.Add(&topic);
	branch.Add(&line);
	branch.Add(&mark);

	//이동전 값 확인
	cout << " Topic :  " << topic.GetX() << " " << topic.GetY() << " " << topic.GetWidth() << " " << topic.GetHeight() << " " << topic.GetContent() << " " << endl;
	cout << " Line :  " << line.GetX() << " " << line.GetY() << " " << line.GetWidth() << " " << line.GetHeight() << " " << line.GetContent() << " " << endl;
	cout << " Mark :  " << mark.GetX() << " " << mark.GetY() << " " << mark.GetWidth() << " " << mark.GetHeight() << " " << mark.GetContent() << " " << endl;

	//이동
	MoveVisitor visitor(9, 9);
	branch.Accept(visitor);

	//이동후 값 확인
	cout << " Topic :  " << topic.GetX() << " " << topic.GetY() << " " << topic.GetWidth() << " " << topic.GetHeight() << " " << topic.GetContent() << " " << endl;
	cout << " Line :  " << line.GetX() << " " << line.GetY() << " " << line.GetWidth() << " " << line.GetHeight() << " " << line.GetContent() << " " << endl;
	cout << " Mark :  " << mark.GetX() << " " << mark.GetY() << " " << mark.GetWidth() << " " << mark.GetHeight() << " " << mark.GetContent() << " " << endl;

	return 0;
}
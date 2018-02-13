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
	Long newX;
	Long newY;
	newX = line->GetX() - this->x;
	newY = line->GetY() - this->y;

	line->SetX(newX);
	line->SetY(newY);
}

void MoveVisitor::VisitTopic(Topic *topic) {
	Long newX;
	Long newY;
	newX = topic->GetX() - this->x;
	newY = topic->GetY() - this->y;

	topic->SetX(newX);
	topic->SetY(newY);
}

void MoveVisitor::VisitMark(Mark * mark)
{
	Long newX;
	Long newY;
	newX = mark->GetX() - this->x;
	newY = mark->GetY() - this->y;

	mark->SetX(newX);
	mark->SetY(newY);
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
	Topic topic(30, 30, 30, 30, "토픽");
	Line line(10, 10, 10, 10, "라인");
	Mark mark(20, 20, 20, 20, "마크");
	Branch branch;

	branch.Add(&line);
	branch.Add(&mark);
	branch.Add(&topic);

	//Find 기능 확인
	Long index;
	index = branch.Find(&line);
	cout << "index : " << index << endl;

	index = branch.Find(&topic);
	cout << "index : " << index << endl;

	index = branch.Find(&mark);
	cout << "index : " << index << endl;

	//이동전 값 확인
	cout << " Line :  " << line.GetX() << " " << line.GetY() << " " << line.GetWidth() << " " << line.GetHeight() << " " << line.GetContent() << " " << endl;
	cout << " Mark :  " << mark.GetX() << " " << mark.GetY() << " " << mark.GetWidth() << " " << mark.GetHeight() << " " << mark.GetContent() << " " << endl;
	cout << " Topic :  " << topic.GetX() << " " << topic.GetY() << " " << topic.GetWidth() << " " << topic.GetHeight() << " " << topic.GetContent() << " " << endl;
	cout << endl;

	//이동
	MoveVisitor visitor(5, 5);
	branch.Accept(visitor);

	//이동후 값 확인
	cout << " Line :  " << line.GetX() << " " << line.GetY() << " " << line.GetWidth() << " " << line.GetHeight() << " " << line.GetContent() << " " << endl;
	cout << " Mark :  " << mark.GetX() << " " << mark.GetY() << " " << mark.GetWidth() << " " << mark.GetHeight() << " " << mark.GetContent() << " " << endl;
	cout << " Topic :  " << topic.GetX() << " " << topic.GetY() << " " << topic.GetWidth() << " " << topic.GetHeight() << " " << topic.GetContent() << " " << endl;

	return 0;
}
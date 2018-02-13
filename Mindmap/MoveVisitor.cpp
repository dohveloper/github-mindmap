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
	Long x;
	Long y;
	x = line->GetX();
	y = line->GetY();

	line->SetX(x + this->x);
	line->SetY(y + this->y);
}

void MoveVisitor::VisitTopic(Topic *topic) {
	Long x;
	Long y;
	x = topic->GetX();
	y = topic->GetY();

	topic->SetX(x + this->x);
	topic->SetY(y + this->y);
}

void MoveVisitor::VisitMark(Mark * mark)
{
	Long x;
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
	Topic topic(30, 30, 30, 30, "����");
	Line line(10, 10, 10, 10, "����");
	Mark mark(20, 20, 20, 20, "��ũ");
	Branch branch;

	branch.Add(&line);
	branch.Add(&mark);
	branch.Add(&topic);

	//Find ��� Ȯ��
	Long index;
	index = branch.Find(&line);
	cout << "index : " << index << endl;

	index = branch.Find(&topic);
	cout << "index : " << index << endl;

	index = branch.Find(&mark);
	cout << "index : " << index << endl;

	//�̵��� �� Ȯ��
	cout << " Line :  " << line.GetX() << " " << line.GetY() << " " << line.GetWidth() << " " << line.GetHeight() << " " << line.GetContent() << " " << endl;
	cout << " Mark :  " << mark.GetX() << " " << mark.GetY() << " " << mark.GetWidth() << " " << mark.GetHeight() << " " << mark.GetContent() << " " << endl;
	cout << " Topic :  " << topic.GetX() << " " << topic.GetY() << " " << topic.GetWidth() << " " << topic.GetHeight() << " " << topic.GetContent() << " " << endl;
	cout << endl;

	//�̵�
	MoveVisitor visitor(5, 5);
	branch.Accept(visitor);

	//�̵��� �� Ȯ��
	cout << " Line :  " << line.GetX() << " " << line.GetY() << " " << line.GetWidth() << " " << line.GetHeight() << " " << line.GetContent() << " " << endl;
	cout << " Mark :  " << mark.GetX() << " " << mark.GetY() << " " << mark.GetWidth() << " " << mark.GetHeight() << " " << mark.GetContent() << " " << endl;
	cout << " Topic :  " << topic.GetX() << " " << topic.GetY() << " " << topic.GetWidth() << " " << topic.GetHeight() << " " << topic.GetContent() << " " << endl;

	return 0;
}
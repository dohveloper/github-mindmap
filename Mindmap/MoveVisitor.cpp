#include "MoveVisitor.h"
#include "Topic.h"
#include "Line.h"
#include "Branch.h"
#include "Mark.h"
#include "MouseAction.h"
#include "SelectionStrategy.h"
#include "Shape.h"
#include "MoveTraverser.h"

MoveVisitor::MoveVisitor(Long centerX, Long x, Long y) {
	this->centerX = centerX;
	this->x = x;
	this->y = y;
}

MoveVisitor::~MoveVisitor() {
}

void MoveVisitor::VisitBranch(Branch *branch)
{
	Long startX;
	Long startY;
	Long endX;
	Long endY;
	Long lineWidth;
	Long lineHeight;
	Line *line;

	// 이동시킨다.
	MoveTraverser traverser(branch, this->x, this->y);
	traverser.Traverse();

	// 가장 앞 라인을 이동한다.
	branch->GetOwnerBranch()->GetTopic()->GetCenter(&startX, &startY);
	branch->GetTopic()->GetCenter(&endX, &endY);
	lineWidth = endX - startX;
	lineHeight = endY - startY;

	line = branch->GetLine();
	line->SetX(startX);
	line->SetY(startY);
	line->SetWidth(lineWidth);
	line->SetHeight(lineHeight);
}

/*
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

	//================================================================================================================================================
	//   브랜치 기능확인
	//================================================================================================================================================

	//Find 기능 확인

	Long index;
	index = branch.Find(&line);
	cout << "index : " << index << endl;

	index = branch.Find(&topic);
	cout << "index : " << index << endl;

	index = branch.Find(&mark);
	cout << "index : " << index << endl;

	//복사생성자 확인
	(branch.GetAt(0))->SetIsShown(false);
	Branch copied(branch);
	Shape *shape;
	Long i = 0;
	while (i < copied.GetLength()) {
		shape = copied.GetAt(i);
		cout << i << " : " << shape->GetX() << " " << shape->GetY() << " " << shape->GetWidth() << " " << shape->GetHeight() << " " << shape->GetContent() << " " << shape->GetIsShown() << " " << shape->GetOwnerBranch() << endl;
		i++;
	}

	while (i < copied.GetLength()) {
		shape = copied.GetAt(i);
		cout << i << " : " << shape->GetX() << " " << shape->GetY() << " " << shape->GetWidth() << " " << shape->GetHeight() << " " << shape->GetContent() << " " << shape->GetIsShown() << " " << shape->GetOwnerBranch() << endl;
		i++;
	}
	cout << endl;
	//================================================================================================================================================
	//   MoveVisiotr 기능확인
	//================================================================================================================================================

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
*/
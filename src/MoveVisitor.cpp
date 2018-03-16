#include "MoveVisitor.h"
#include "Topic.h"
#include "Line.h"
#include "Branch.h"
#include "Mark.h"
#include "MouseAction.h"
#include "Shape.h"
#include "MoveTraverser.h"
#include "FlipVisitor.h"

MoveVisitor::MoveVisitor(Long centerLine, Long x, Long y) {
	this->centerLine = centerLine;
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
	Long previousCenterX;
	Long newCenterX;

	//�̵���Ű���� X�� ����Ѵ�.
	previousCenterX = branch->GetTopic()->GetCenterX();

	// �̵���Ų��.
	MoveTraverser traverser(branch, this->x, this->y);
	traverser.Traverse();

	//�߾Ӽ��� �Ѿ�� �¿������Ų��.
	FlipVisitor visitor;
	newCenterX = previousCenterX - this->x;
	if (previousCenterX < this->centerLine && newCenterX > this->centerLine) {
		branch->Accept(visitor);
	}
	if (previousCenterX > this->centerLine && newCenterX < this->centerLine) {
		branch->Accept(visitor);
	}

	// ���� �� ������ �̵��Ѵ�.
	startX = branch->GetOwnerBranch()->GetTopic()->GetCenterX();
	startY = branch->GetOwnerBranch()->GetTopic()->GetCenterY();
	endX = branch->GetTopic()->GetCenterX();
	endY = branch->GetTopic()->GetCenterY();
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
	Topic topic(30, 30, 30, 30, "����");
	Line line(10, 10, 10, 10, "����");
	Mark mark(20, 20, 20, 20, "��ũ");
	Branch branch;

	branch.Add(&line);
	branch.Add(&mark);
	branch.Add(&topic);

	//================================================================================================================================================
	//   �귣ġ ���Ȯ��
	//================================================================================================================================================

	//Find ��� Ȯ��

	Long index;
	index = branch.Find(&line);
	cout << "index : " << index << endl;

	index = branch.Find(&topic);
	cout << "index : " << index << endl;

	index = branch.Find(&mark);
	cout << "index : " << index << endl;

	//��������� Ȯ��
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
	//   MoveVisiotr ���Ȯ��
	//================================================================================================================================================

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
*/
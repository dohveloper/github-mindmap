#include "MoveTraverser.h"
#include "Branch.h"
#include "Topic.h"
#include "Line.h"
#include "Mark.h"

MoveTraverser::MoveTraverser(Branch *branch, Long x, Long y)
	:BranchTraverser(branch)
{
	this->x = x;
	this->y = y;
}

inline bool MoveTraverser::ProcessItem(Shape * shape)
{
	bool ret = true;
	Long movedX;
	Long movedY;

	if (typeid(*shape) == typeid(Branch)) {
		MoveTraverser traverser((Branch*)shape, this->x, this->y);
		traverser.Traverse();
	}
	else {
		movedX = shape->GetX() - this->x;
		movedY = shape->GetY() - this->y;

		shape->SetX(movedX);
		shape->SetY(movedY);
	}
	return ret;
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
	MoveTraverser traverser(&branch, 5, 5);
	traverser.Traverse();

	//이동후 값 확인
	cout << " Line :  " << line.GetX() << " " << line.GetY() << " " << line.GetWidth() << " " << line.GetHeight() << " " << line.GetContent() << " " << endl;
	cout << " Mark :  " << mark.GetX() << " " << mark.GetY() << " " << mark.GetWidth() << " " << mark.GetHeight() << " " << mark.GetContent() << " " << endl;
	cout << " Topic :  " << topic.GetX() << " " << topic.GetY() << " " << topic.GetWidth() << " " << topic.GetHeight() << " " << topic.GetContent() << " " << endl;

	return 0;
}
*/
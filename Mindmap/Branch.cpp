//Branch.cpp

#include "Branch.h"
#include "Composite.h"
#include "Topic.h"
#include "Line.h"
Branch::Branch(Long capacity, Branch* branch)
	:Composite(capacity, branch)
{
}
Branch::Branch(const Branch& source)
	: Composite(source) {
	this->x = source.x;
	this->y = source.y;
	this->width = source.width;
	this->height = source.height;
	this->ownerBranch = source.ownerBranch;
	this->isShown = source.isShown;
}
Branch::~Branch()
{
}

Long Branch::Add(Shape * shape)
{
	Long index;
	index = Composite::Add(shape);
	shape->SetOwnerBranch(this);
	return index;
}

Topic* Branch::GetTopic()
{
	Shape *topic;

	topic = this->shapes.GetAt(0);
	if (typeid(*topic) != typeid(Topic)) {
		topic = this->shapes.GetAt(1);
	}

	return (Topic*)topic;
}

Mark* Branch::GetMark()
{
	Shape *mark;
	Long length;
	Long i = 0;

	length = this->shapes.GetLength();

	while (i < length)
	{
		mark = this->shapes.GetAt(i);

		if (typeid(*mark) == typeid(Mark))
		{
			i = length;
		}
		i++;
	}
	/*
	mark = this->shapes.GetAt(1);
	if (typeid(*mark) == typeid(Mark))
	{
		mark = this->shapes.GetAt(2);
	}
	*/
	return (Mark*)mark;
}

void Branch::Accept(ShapeVisitor& visitor) {
	visitor.VisitBranch(this);
}

Branch * Branch::Clone()
{
	return new Branch(*this);
}

Branch& Branch::operator=(const Branch& source)
{
	this->shapes = source.shapes;
	this->capacity = source.capacity;
	this->length = source.length;
	return *this;
}
/*
#include <iostream>
#include "Topic.h"
#include "Line.h"
int main(int argc, char *argv[]) {
Branch branch;
Long index;
Long i = 0;

//ownerBranch 생성 테스트
Topic *topic1 = new Topic(0, 0, 0, 0,"");
if (topic1->GetOwnerBranch() == NULL) {
	cout << "토픽 널 제대로 됨" << endl;
}
Line *line1 = new Line(0, 0, 0, 0, "");
if (line1->GetOwnerBranch() == NULL) {
	cout << "라인 널 제대로 됨" << endl;
}

Branch *branch1 = new Branch();
if (branch1->GetOwnerBranch() == NULL) {
	cout << "브랜치 널 제대로 됨" << endl;
}
//OwnerBranch Add 테스트
Topic *topic2;
topic2 = topic1->GetOwnerBranch()->GetTopic();
cout << " 토픽1 " << topic1->GetContent() << " 토픽1 " << topic2->GetContent() << endl;
Line *line2;
line2 = (Line*)line1->GetOwnerBranch()->GetAt(1);
cout << " 라인1 " << line1->GetContent() << " 라인2 " << line2->GetContent() << endl;
Branch *branch2;
branch2 = (Branch*)branch1->GetOwnerBranch()->GetAt(1);
cout << " 라인1 " << branch1->GetContent() << " 라인2 " << branch1->GetContent() << endl;

index = branch.Add(new Topic(10, 10, 10, 10, "같은지"));
cout<<branch.GetAt(index)->GetX()<< branch.GetAt(index)->GetY()<< branch.GetAt(index)->GetWidth()<< branch.GetAt(index)->GetHeight() << branch.GetAt(index)->GetContent() <<endl;

index = branch.Add(new Line(10, 10, 10, 10, "라인"));
cout << branch.GetAt(index)->GetX() << branch.GetAt(index)->GetY() << branch.GetAt(index)->GetWidth() << branch.GetAt(index)->GetHeight() << branch.GetAt(index)->GetContent() << endl;

Branch branch1(branch);

branch1.Correct(index,new Line(20,20,20,20,"aaaaaa", &branch1));

while (i < branch1.GetLength())
{
cout << branch1.GetAt(i)->GetX() << branch1.GetAt(i)->GetY() << branch1.GetAt(i)->GetWidth() << branch1.GetAt(i)->GetHeight() << branch1.GetAt(i)->GetContent() << endl;
i++;
}

Branch branch2;
branch2 = branch1;
i = 0;
while (i < branch2.GetLength())
{
cout << branch2.GetAt(i)->GetX() << branch2.GetAt(i)->GetY() << branch2.GetAt(i)->GetWidth() << branch2.GetAt(i)->GetHeight() << branch2.GetAt(i)->GetContent() << endl;
i++;
}

branch.Add(&branch2);

return 0;
}

*/
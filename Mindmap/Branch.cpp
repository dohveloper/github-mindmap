//Branch.cpp

#include "Branch.h"
#include "Composite.h"
#include "Topic.h"
#include "Line.h"
#include "BranchCopyTraverser.h"

Branch::Branch(Long capacity, Branch* branch)
	:Composite(capacity, branch)
{
}
Branch::Branch(const Branch& source)
	: Composite(source.capacity)
{
	Long i = 0;
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
	Branch *clone;
	BranchCopyTraverser traverser(this);
	traverser.Traverse();
	clone = traverser.GetClone();
	return clone;
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

//ownerBranch ���� �׽�Ʈ
Topic *topic1 = new Topic(0, 0, 0, 0,"");
if (topic1->GetOwnerBranch() == NULL) {
	cout << "���� �� ������ ��" << endl;
}
Line *line1 = new Line(0, 0, 0, 0, "");
if (line1->GetOwnerBranch() == NULL) {
	cout << "���� �� ������ ��" << endl;
}

Branch *branch1 = new Branch();
if (branch1->GetOwnerBranch() == NULL) {
	cout << "�귣ġ �� ������ ��" << endl;
}
//OwnerBranch Add �׽�Ʈ
Topic *topic2;
topic2 = topic1->GetOwnerBranch()->GetTopic();
cout << " ����1 " << topic1->GetContent() << " ����1 " << topic2->GetContent() << endl;
Line *line2;
line2 = (Line*)line1->GetOwnerBranch()->GetAt(1);
cout << " ����1 " << line1->GetContent() << " ����2 " << line2->GetContent() << endl;
Branch *branch2;
branch2 = (Branch*)branch1->GetOwnerBranch()->GetAt(1);
cout << " ����1 " << branch1->GetContent() << " ����2 " << branch1->GetContent() << endl;

index = branch.Add(new Topic(10, 10, 10, 10, "������"));
cout<<branch.GetAt(index)->GetX()<< branch.GetAt(index)->GetY()<< branch.GetAt(index)->GetWidth()<< branch.GetAt(index)->GetHeight() << branch.GetAt(index)->GetContent() <<endl;

index = branch.Add(new Line(10, 10, 10, 10, "����"));
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
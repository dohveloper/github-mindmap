//Branch.cpp

#include "Branch.h"
#include "Composite.h"
#include "Topic.h"
#include "Line.h"
Branch::Branch(Long capacity)
	:Composite(capacity)
{
	this->isHidden = false;

}
Branch::Branch(const Branch& source)
	:Composite(source) {

}
Branch::~Branch()
{
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

bool Branch::GetIsHidden()
{
	return isHidden;
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

index=branch.Add(new Topic(10, 10, 10, 10, "ASD"));
cout<<branch.GetAt(index)->GetX()<< branch.GetAt(index)->GetY()<< branch.GetAt(index)->GetWidth()<< branch.GetAt(index)->GetHeight() << branch.GetAt(index)->GetContent() <<endl;

index = branch.Add(new Line(10, 10, 10, 10, "ddd"));
cout << branch.GetAt(index)->GetX() << branch.GetAt(index)->GetY() << branch.GetAt(index)->GetWidth() << branch.GetAt(index)->GetHeight() << branch.GetAt(index)->GetContent() << endl;

Branch branch1(branch);

branch1.Correct(index,new Line(20,20,20,20,"aaaaaa"));

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
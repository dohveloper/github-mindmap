//Topic.cpp

#include "Topic.h"

Topic::Topic() 
:Shape()
{

}

Topic::Topic(Long x, Long y, Long width, Long height, string content) 
:Shape(x,y,width,height,content)
{

}

Topic::Topic(const Topic& source)
: Shape(source.x, source.y, source.width, source.height, source.content)
{
	
}

Topic::~Topic() {

}

void Topic::Accept(ShapeVisitor& visitor) {
	visitor.VisitTopic(this);
}

bool Topic::IsEqual(const Topic& other) {
	bool ret = false;

	if (this->x == other.x&&this->y == other.y&&this->width == other.width&&this->height == other.height && (this->content.compare(other.content)) == 0)
	{
		ret = true;
	}
	return ret;
}

bool Topic::IsNotEqual(const Topic& other) {
	bool ret = false;

	if (this->x != other.x || this->y != other.y || this->width != other.width || this->height != other.height || (this->content.compare(other.content)) != 0)
	{
		ret = true;
	}
	return ret;
}

bool Topic::operator==(const Topic& other) {
	bool ret = false;

	if (this->x == other.x&&this->y == other.y&&this->width == other.width&&this->height == other.height && (this->content.compare(other.content)) == 0)
	{
		ret = true;
	}
	return ret;
}

bool Topic::operator!=(const Topic& other) {
	bool ret = false;

	if (this->x != other.x || this->y != other.y || this->width != other.width || this->height != other.height || (this->content.compare(other.content)) != 0)
	{
		ret = true;
	}
	return ret;
}

Topic& Topic::operator=(const Topic& source) {
	this->x = source.x;
	this->y = source.y;
	this->width = source.width;
	this->height = source.height;
	this->content = source.content;

	return *this;
}
/*
#include <iostream>

int main(int argc, char *argv[]) {
	Topic topic(10, 10, 10, 10, "ddd");
	Topic topic1(10, 10, 10, 10, "ddd");
	Topic topic2(topic);
	Topic topic3(2, 2, 3, 3, "aaa");
	topic3 = topic2;

	bool ret = false;

	ret = topic.IsEqual(topic1);
	if (ret == true) {
		cout << "일치" << endl;
	}
	ret = topic2.IsNotEqual(topic3);
	if (ret == true) {
		cout << "불일치" << endl;
	}
	cout << topic1.GetX() << topic1.GetY() << topic1.GetWidth() << topic1.GetHeight() << topic1.GetContent() << endl;

	cout<< topic2.GetX() << topic2.GetY() << topic2.GetWidth() << topic2.GetHeight() << topic2.GetContent() <<endl;

	cout << topic3.GetX() << topic3.GetY() << topic3.GetWidth() << topic3.GetHeight() << topic3.GetContent() << endl;

	return 0;
}

*/
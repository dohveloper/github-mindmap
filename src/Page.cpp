//Page.cpp

#include "Page.h"
#include "Composite.h"


Page::Page(Long capacity)
{
}

Page::Page(const Page& source)
	:Composite(source) {

}

Page::~Page() 
{
}

Page& Page::operator=(const Page& source)
{
	this->shapes = source.shapes;
	this->capacity = source.capacity;
	this->length = source.length;

	return *this;
}


/*
#include <iostream>
#include "topic.h"
int main(int argc, char *argv[]) {

	Page page;
	Long index;
	Topic *topicLink;

	Topic topic(10, 10, 50, 50, "메인토픽");

	index = page.Add(&topic);
	topicLink = (Topic*)page.GetAt(index);
	cout << topicLink->GetX() << topicLink->GetY() << topicLink->GetWidth() << topicLink->GetHeight() << topicLink->GetContent() << endl;

	

	return 0;
}*/
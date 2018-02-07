//Line.cpp

#include "Line.h"
#include <string>


Line::Line()
:Shape()
{

}

Line::Line(Long x, Long y, Long width, Long height, string content, Branch *branch)
:Shape(x, y, width, height, content,branch)
{

}

Line::Line(const Line&source)
:Shape(source.x, source.y, source.width, source.height, source.content,source.ownerBranch)
{

}

Line::~Line() {

}

void Line::Accept(ShapeVisitor& visitor) {
	visitor.VisitLine(this);
}

bool Line::IsEqual(const Line& other) {
	bool ret = false;

	if (this->x == other.x && this->y == other.y && this->width == other.width && this->height == other.height && this->content.compare(other.content) == 0)
	{
		ret = true;
	}
	return ret;
}

bool Line::IsNotEqual(const Line& other) {
	bool ret = false;

	if (this->x != other.x || this->y != other.y || this->width != other.width || this->height != other.height || this->content.compare(other.content) != 0)
	{
		ret = true;
	}
	return ret;
}

bool Line::operator==(const Line& other) {
	bool ret = false;

	if (this->x == other.x && this->y == other.y && this->width == other.width && this->height == other.height && this->content.compare(other.content) == 0)
	{
		ret = true;
	}

	return ret;
}

bool Line::operator!=(const Line& other) {
	bool ret = false;

	if (this->x != other.x || this->y != other.y || this->width != other.width || this->height != other.height || this->content.compare(other.content) != 0)
	{
		ret = true;
	}

	return ret;
}

Line& Line::operator=(const Line& source) {
	this->x = source.x;
	this->y = source.y;
	this->width = source.width;
	this->height = source.height;
	this->content = source.content;

	return *this;
}
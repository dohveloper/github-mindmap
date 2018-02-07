#include "Shape.h"
//#include "Composite.h"
//#include "Line.h"

Shape::Shape()
:content(""){
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
	this->ownerBranch = NULL;
}

Shape::Shape(Long x, Long y, Long width, Long height, string content,Branch *branch)
	: content(content){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->ownerBranch = branch;
}

Shape::Shape(const Shape& source)
	: content(source.content) {
	this->x = source.x;
	this->y = source.y;
	this->width = source.width;
	this->height = source.height;
	this->ownerBranch = source.ownerBranch;
}

Shape::~Shape() {}

Long Shape::Add(Shape *shape) {
	return -1;
}

Long Shape::Correct(Long index, Shape *shape) {
	return -1;
}
Shape* Shape::GetAt(Long index) {
	return 0;
}

void Shape::Accept(ShapeVisitor& visitor) {

}


bool Shape::IsEqual(const Shape& other) {
	return 0;
}

bool Shape::IsNotEqual(const Shape& other) {
	return 0;
}

Shape& Shape::operator=(const Shape& source) {
	this->x = source.x;
	this->y = source.y;
	this->width = source.width;
	this->height = source.height;
	this->content = source.content;

	return *this;

}
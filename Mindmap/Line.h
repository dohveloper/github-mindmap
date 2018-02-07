//Line.h

#ifndef _LINE_H
#define _LINE_H

#include "Shape.h"
#include "ShapeVisitor.h"
#include <string>
using namespace std;

typedef signed long int Long;

class Line : public Shape {
public:
	Line();
	Line(Long x, Long y, Long width, Long height, string content, Branch *branch = NULL);
	Line(const Line& source);
	virtual ~Line();

	virtual void Accept(ShapeVisitor& visitor);

	bool IsEqual(const Line& other);
	bool IsNotEqual(const Line& other);

	Line& operator=(const Line& source);
	bool operator==(const Line& other);
	bool operator!=(const Line& other);

};

#endif //_LINE_H
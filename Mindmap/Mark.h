//Mark.h

#ifndef MARK_H
#define MARK_H

#include "Shape.h"
#include "ShapeVisitor.h"
#include <string>
#define markWidth 20
#define markHeight 20

using namespace std;
typedef signed long int Long;

class Mark : public Shape {
public:
	Mark();
	Mark(Long x, Long y, Long width = markWidth, Long height = markHeight, string content = "+", Branch *branch = NULL);
	Mark(const Mark& source);

	void UpdatePosition();
	virtual ~Mark();

	void Accept(ShapeVisitor& visitor);
	Mark& operator=(const Mark& source);
};

#endif // MARK_H

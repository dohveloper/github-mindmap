//Mark.h

#ifndef MARK_H
#define MARK_H

#include "Shape.h"
#include "ShapeVisitor.h"
#include <string>
#define intervalH 20
#define intervalV -20

using namespace std;
typedef signed long int Long;

class Mark : public Shape {
public:
	Mark();
	Mark(Long x, Long y, Long width = intervalH, Long height = intervalV, string content = "+", Branch *branch = NULL);
	Mark(const Mark& source);
	virtual ~Mark();

	void SetContent(string content);
	void Accept(ShapeVisitor& visitor);
	Mark& operator=(const Mark& source);

};

#endif // MARK_H

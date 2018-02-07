//Topic.h

#ifndef _TOPIC_H
#define _TOPIC_H

#include "Shape.h"
#include "ShapeVisitor.h"
#include <string>
using namespace std;

typedef signed long int Long;

class Topic : public Shape {
public:
	Topic();
	Topic(Long x,Long y,Long width,Long height,string content, Branch *branch = NULL);
	Topic(const Topic& source);
	virtual ~Topic();

	virtual void Accept(ShapeVisitor& visitor);

	bool IsEqual(const Topic& other);
	bool IsNotEqual(const Topic& other);

	bool operator==(const Topic& other);
	bool operator!=(const Topic& other);
	Topic& operator=(const Topic& other);

};

#endif //TOPIC_H
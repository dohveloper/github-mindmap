//Branch.h

#ifndef _BRANCH_H
#define _BRANCH_H

#include "Composite.h"
#include "Mark.h"
using namespace std;
typedef signed long int Long;

class Branch : public Composite {
public:
	Branch(Long capacity = 256, Branch* branch = NULL);
	Branch(const Branch& source);
	virtual ~Branch();

	Long Add(Shape *shape);
	Long Correct(Long index, Shape *shape);
	void Replace(Shape *before, Shape *after);
	Topic* GetTopic();
	Mark* GetMark();

	virtual void Accept(ShapeVisitor& visitor);

	Branch* Clone();
	Branch& operator=(const Branch& source);
};

#endif //TOPIC_H
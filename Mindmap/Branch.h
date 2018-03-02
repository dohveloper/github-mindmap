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
	void Sort();
	Topic* GetTopic();
	Line* GetLine();
	Mark* GetMark();

	virtual void Accept(ShapeVisitor& visitor);

	Branch* Clone();
	Branch& operator=(const Branch& source);
};

int CompareYs(void *one, void *other);

#endif //TOPIC_H
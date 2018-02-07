//Branch.h

#ifndef _BRANCH_H
#define _BRANCH_H

#include "Composite.h"
using namespace std;
typedef signed long int Long;


class Branch : public Composite {
public:
	Branch(Long capacity = 256, Branch* branch = NULL);
	Branch(const Branch& source);
	virtual ~Branch();

	Long Add(Shape *shape);
	Topic* GetTopic();
	bool GetIsHidden();

	virtual void Accept(ShapeVisitor& visitor);
	
	Branch* Clone();
	Branch& operator=(const Branch& source);

private:
	bool isHidden;

};
#endif //TOPIC_H
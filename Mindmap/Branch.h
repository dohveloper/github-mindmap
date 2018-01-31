//Branch.h

#ifndef _BRANCH_H
#define _BRANCH_H

#include "Composite.h"
using namespace std;
typedef signed long int Long;


class Branch : public Composite {
public:
	Branch(Long capacity = 256);
	Branch(const Branch& source);
	virtual ~Branch();
	
	Topic* GetTopic();

	virtual void Accept(ShapeVisitor& visitor);
	
	Branch* Clone();
	Branch& operator=(const Branch& source);

};
#endif //TOPIC_H
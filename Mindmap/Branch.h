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
	Topic* GetTopic();

	virtual void Accept(ShapeVisitor& visitor);

	Branch* Clone();
	Branch& operator=(const Branch& source);

	Mark& GetMark() const;
private:
	Mark mark;
	

};

inline Mark& Branch::GetMark() const {

	return const_cast<Mark&>(this->mark);
}

#endif //TOPIC_H
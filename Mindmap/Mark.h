//Mark.h

#ifndef MARK_H
#define MARK_H

#include "Shape.h"
#include "ShapeVisitor.h"
#include <string>
using namespace std;
typedef signed long int Long;

class Mark : public Shape {
public:
	Mark();
	Mark(Long x, Long y, Long width, Long height, string content);
	Mark(const Mark& source);
	virtual ~Mark();

	void setContent(string content);
	void ShowMark();
	void HideMark();
	void Accept(ShapeVisitor& visitor);
	Mark& operator=(const Mark& source);

	bool GetIsShowned() const;

private:
	bool isShowned;
};

inline bool Mark::GetIsShowned() const
{
	return this->isShowned;
}

#endif // MARK_H

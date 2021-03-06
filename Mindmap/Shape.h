//Shape.h

#ifndef _SHAPE_H
#define _SHAPE_H

#include <string>
#include "ShapeVisitor.h"
using namespace std;
typedef signed long int Long;
class Branch;
class Selection;
class Shape {
public:
	Shape();
	Shape(Long x, Long y, Long width, Long height, string content, Branch *branch = NULL, bool isShown = true);
	Shape(const Shape& source);
	virtual ~Shape() = 0;

	virtual Long Add(Shape *shape);
	virtual Long Remove(Long index);
	virtual Long Correct(Long index, Shape *shape);
	virtual Shape* GetAt(Long index);

	virtual void Accept(ShapeVisitor& visitor);
	virtual void Show();
	virtual void Hide();

	virtual bool IsEqual(const Shape& other);
	virtual bool IsNotEqual(const Shape& other);

	Shape& operator=(const Shape& source);

	Long GetX() const;
	Long GetY() const;
	Long GetWidth() const;
	Long GetHeight() const;
	string& GetContent() const;
	Branch* GetOwnerBranch() const;
	bool GetIsShown() const;
	void SetOwnerBranch(Branch *branch);
	void SetContent(string content);

protected:
	Long x;
	Long y;
	Long height;
	Long width;
	string content;
	Branch *ownerBranch;
	bool isShown;
};

inline Long Shape::GetX() const {
	return this->x;
}
inline Long Shape::GetY() const {
	return this->y;
}
inline Long Shape::GetWidth() const {
	return this->width;
}
inline Long Shape::GetHeight() const {
	return this->height;
}
inline string& Shape::GetContent() const {
	return const_cast<string&>(this->content);
}

inline Branch* Shape::GetOwnerBranch() const
{
	return const_cast<Branch*>(this->ownerBranch);
}
inline bool Shape::GetIsShown() const
{
	return this->isShown;
}
inline void Shape::SetOwnerBranch(Branch *branch)
{
	this->ownerBranch = branch;
}
inline void Shape::SetContent(string content)
{
	this->content = content;
}

#endif //_SHAPE_H
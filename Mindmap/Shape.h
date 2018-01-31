//Shape.h

#ifndef _SHAPE_H
#define _SHAPE_H

#include <string>
#include "ShapeVisitor.h"
using namespace std;
typedef signed long int Long;

class Shape {
    public:
    	Shape();
    	Shape(Long x, Long y, Long width, Long height, string content);
    	Shape(const Shape& source);
    	virtual ~Shape() = 0;
    
    	virtual Long Add(Shape *shape);
    	virtual Long Correct(Long index,Shape *shape);
    	virtual Shape* GetAt(Long index);

		virtual void Accept(ShapeVisitor& visitor);
		
    
    	virtual bool IsEqual(const Shape& other);
    	virtual bool IsNotEqual(const Shape& other);
    
		Shape& operator=(const Shape& source);

    	Long GetX() const;
    	Long GetY() const;
    	Long GetWidth() const;
    	Long GetHeight() const;
    	string& GetContent() const;
    	
    protected:
    	Long x;
    	Long y;
    	Long height;
    	Long width;
    	string content;
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


#endif //_SHAPE_H
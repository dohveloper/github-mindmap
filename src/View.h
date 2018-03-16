#ifndef _VIEW_H
#define _VIEW_H
#include <afxwin.h>
typedef signed long int Long;

class View
{
public:
	View();
	~View();

	void Zoom(short zDelta);
	void GetRealPoint(CPoint *point);

	void SetStartX(Long x);
	void SetStartY(Long y);
	void SetScale(Long scale);
	void SetWidth(Long width);
	void SetHeight(Long height);
	void SetCenterX(Long centerX);
	void SetCenterY(Long centerY);

	Long GetStartX() const;
	Long GetStartY() const;
	Long GetScale() const;
	Long GetWidth() const;
	Long GetHeight() const;
	Long GetCenterX() const;
	Long GetCenterY() const;

private:
	Long startX; // 시작점
	Long startY;
	Long scale;
	Long width; //스크린
	Long height;
	Long centerX;
	Long centerY;
};
inline Long View::GetStartX() const {
	return this->startX;
}
inline Long View::GetStartY() const {
	return this->startY;
}
inline Long View::GetScale() const {
	return this->scale;
}
inline Long View::GetWidth() const {
	return this->width;
}
inline Long View::GetHeight() const {
	return this->height;
}
inline Long View::GetCenterX() const {
	return this->centerX;
}
inline Long View::GetCenterY() const {
	return this->centerY;
}
#endif //_VIEW_H
#include "View.h"

View::View()
{
	this->startX = 0;
	this->startY = 0;
	this->scale = 1;
	this->width = 1280;
	this->height = 720;
	this->centerX = this->width * 1 / 2;
	this->centerY = this->height * 1 / 2;
}

View::~View()
{
}

void View::Zoom(short zDelta)
{
	Long newX;
	Long newY;

	//스케일을 바꾼다.
	this->scale += zDelta;

	//시작점을 조정한다.
	newX = this->startX + this->width / 2 - this->width / 2 / scale;
	newY = this->startY + this->height / 2 - this->height / 2 / scale;
	this->startX = newX;
	this->startY = newY;

	//스크롤바 크기를 조정한다.
}

void View::GetRealPoint(CPoint *point)
{
	point->Offset(this->startX, this->startY);
}

void View::SetStartX(Long x)
{
	this->startX = x;
}

void View::SetStartY(Long y)
{
	this->startY = y;
}

void View::SetScale(Long scale)
{
	this->scale = scale;
}

void View::SetWidth(Long width)
{
	this->width = width;
}

void View::SetHeight(Long height)
{
	this->height = height;
}

void View::SetCenterX(Long centerX)
{
	this->centerX = centerX;
}

void View::SetCenterY(Long centerY)
{
	this->centerY = centerY;
}
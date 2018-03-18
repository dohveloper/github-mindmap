#include "View.h"

View::View(HWND hWnd)
{
	Long nPos;

	this->hWnd = hWnd;

	///스크롤
	//세로
	this->vertical.cbSize = sizeof(this->vertical);
	this->vertical.fMask = SIF_PAGE | SIF_RANGE;
	this->vertical.nPage = 600;
	this->vertical.nMin = 0;
	this->vertical.nMax = 8000;
	nPos = (this->vertical.nMax - this->vertical.nPage) / 2;
	SetScrollInfo(this->hWnd, SB_VERT, &this->vertical, TRUE);
	SetScrollPos(this->hWnd, SB_VERT, nPos, false);

	//가로
	this->horizontal.cbSize = sizeof(this->horizontal);
	this->horizontal.fMask = SIF_PAGE | SIF_RANGE;
	this->horizontal.nPage = 1200;
	this->horizontal.nMin = 0;
	this->horizontal.nMax = 10000;
	nPos = (this->horizontal.nMax - this->horizontal.nPage) / 2;
	SetScrollInfo(this->hWnd, SB_HORZ, &this->horizontal, TRUE);
	SetScrollPos(this->hWnd, SB_HORZ, nPos, false);

	this->startX = 0;
	this->startY = 0;

	this->startX = (10000 - 1280) / 2;
	this->startY = (8000 - 720) / 2;
	this->scale = 10;
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
	//스케일을 바꾼다.
	if (zDelta > 0) {
		this->scale += zDelta / 120;
	}
	else {
		if (this->scale >= 2) {
			this->scale += zDelta / 120;
		}
	}

	//스크롤을 설정한다.
	this->vertical.nPage = 600 / this->scale;
	this->horizontal.nPage = 1200 / this->scale;
	SetScrollInfo(this->hWnd, SB_VERT, &this->vertical, TRUE);
	SetScrollInfo(this->hWnd, SB_HORZ, &this->horizontal, TRUE);
}

void View::ConvertToDocumentPoint(CPoint *point)
{
	//뷰 좌표를 입력받아 문서 좌표를 구하는 연산
	Long documentX;
	Long documentY;

	//scale을 1로 되돌리기
	documentX = (point->x - this->centerX) / this->scale + this->centerX;
	documentY = (point->y - this->centerY) / this->scale + this->centerY;

	//스크롤
	documentX += this->startX;
	documentY += this->startY;

	//값설정
	point->x = documentX;
	point->y = documentY;
}

void View::ConvertToViewPoint(Long *x, Long *y)
{
	//문서 좌표를 입력받아 뷰 좌표를 구하는 연산
	Long distance;
	Long viewX;
	Long viewY;

	//스크롤되기 전 위치를 구함
	*x -= this->startX;
	*y -= this->startY;

	//확대/축소
	distance = this->centerX - *x;
	viewX = this->centerX - distance * scale;
	distance = this->centerY - *y;
	viewY = this->centerY - distance * scale;

	//값설정
	*x = viewX;
	*y = viewY;
}

void View::SetScrolls()
{
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
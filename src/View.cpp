#include "View.h"

View::View(HWND hWnd)
{
	Long nPos;

	this->hWnd = hWnd;

	///��ũ��
	//����
	this->vertical.cbSize = sizeof(this->vertical);
	this->vertical.fMask = SIF_PAGE | SIF_RANGE;
	this->vertical.nPage = 600;
	this->vertical.nMin = 0;
	this->vertical.nMax = 8000;
	nPos = (this->vertical.nMax - this->vertical.nPage) / 2;
	SetScrollInfo(this->hWnd, SB_VERT, &this->vertical, TRUE);
	SetScrollPos(this->hWnd, SB_VERT, nPos, false);

	//����
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
	//�������� �ٲ۴�.
	if (zDelta > 0) {
		this->scale += zDelta / 120;
	}
	else {
		if (this->scale >= 2) {
			this->scale += zDelta / 120;
		}
	}

	//��ũ���� �����Ѵ�.
	this->vertical.nPage = 600 / this->scale;
	this->horizontal.nPage = 1200 / this->scale;
	SetScrollInfo(this->hWnd, SB_VERT, &this->vertical, TRUE);
	SetScrollInfo(this->hWnd, SB_HORZ, &this->horizontal, TRUE);
}

void View::ConvertToDocumentPoint(CPoint *point)
{
	//�� ��ǥ�� �Է¹޾� ���� ��ǥ�� ���ϴ� ����
	Long documentX;
	Long documentY;

	//scale�� 1�� �ǵ�����
	documentX = (point->x - this->centerX) / this->scale + this->centerX;
	documentY = (point->y - this->centerY) / this->scale + this->centerY;

	//��ũ��
	documentX += this->startX;
	documentY += this->startY;

	//������
	point->x = documentX;
	point->y = documentY;
}

void View::ConvertToViewPoint(Long *x, Long *y)
{
	//���� ��ǥ�� �Է¹޾� �� ��ǥ�� ���ϴ� ����
	Long distance;
	Long viewX;
	Long viewY;

	//��ũ�ѵǱ� �� ��ġ�� ����
	*x -= this->startX;
	*y -= this->startY;

	//Ȯ��/���
	distance = this->centerX - *x;
	viewX = this->centerX - distance * scale;
	distance = this->centerY - *y;
	viewY = this->centerY - distance * scale;

	//������
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
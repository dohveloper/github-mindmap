//OnVScrollLineDown.cpp

#include "OnVScrollLineDown.h"

OnVScrollLineDown::OnVScrollLineDown()
{
}

OnVScrollLineDown::~OnVScrollLineDown()
{
}

OnVScrollLineDown::OnVScrollLineDown(const OnVScrollLineDown& source)
{
}

void OnVScrollLineDown::Scroll(PageForm *pageForm, Long nPos) //���� ��ũ�ѿ��� �Ʒ� �̵� ȭ��ǥ ��ư ������ �� ��(��ũ�Ѹ���)�̵� ����
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition); //���� ��ũ�ѹ��� �ּ�,�ִ� �̵��� ��������
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT); //���� ���� ��ũ�ѹٿ��� ���� ��ġ ��������

	if (currentPosition < maximumPosition)
	{
		this->movedPosition = -10;
		currentPosition += 10;
	}

	pageForm->SetScrollPos(SB_VERT, currentPosition); //������ ������ ���� ��ġ�� �����Ѵ�.
}

OnVScrollLineDown& OnVScrollLineDown::operator=(const OnVScrollLineDown& soucre)
{
	return *this;
}
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

void OnVScrollLineDown::Scrolling(PageForm *pageForm) //���� ��ũ�ѿ��� �Ʒ� �̵� ȭ��ǥ ��ư ������ �� ��(��ũ�Ѹ���)�̵� ����
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition); //���� ��ũ�ѹ��� �ּ�,�ִ� �̵��� ��������
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_VERT); //���� ��ũ�ѹ��� �̵� �Ѱ� �� �������� (���⼱ �ִ밪�� �޾�����)
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT); //���� ���� ��ũ�ѹٿ��� ���� ��ġ �������� 

	currentPosition += 10; //���� ���ν�ũ�ѹ��� �� ��ġ�� +10�ؼ� �Ű������� �����Ѵ�.

	if (currentPosition > maximumPosition) //���� �̵��Ҽ� �ִ� �Ѱ谪�� �ʰ��ϸ� �Ѱ谪�� �����ϰ� �����ش�.
	{
		currentPosition = maximumPosition;
	}

	pageForm->SetScrollPos(SB_VERT, currentPosition); //������ ������ ���� ��ġ�� �����Ѵ�.
}

OnVScrollLineDown& OnVScrollLineDown::operator=(const OnVScrollLineDown& soucre)
{
	return *this;
}

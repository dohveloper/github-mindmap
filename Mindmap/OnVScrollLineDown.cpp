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

void OnVScrollLineDown::Scroll(PageForm *pageForm, Long nPos) //세로 스크롤에서 아래 이동 화살표 버튼 눌렀을 시 썸(스크롤막대)이동 구현
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition); //세로 스크롤바의 최소,최대 이동값 가져오기
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT); //현재 세로 스크롤바에서 썸의 위치 가져오기

	if (currentPosition < maximumPosition)
	{
		this->movedPosition = -10;
		currentPosition += 10;
	}

	pageForm->SetScrollPos(SB_VERT, currentPosition); //지정된 값으로 썸의 위치를 변경한다.
}

OnVScrollLineDown& OnVScrollLineDown::operator=(const OnVScrollLineDown& soucre)
{
	return *this;
}
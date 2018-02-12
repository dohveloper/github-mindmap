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

void OnVScrollLineDown::Scrolling(PageForm *pageForm) //세로 스크롤에서 아래 이동 화살표 버튼 눌렀을 시 썸(스크롤막대)이동 구현
{
	int minmumPosition;
	int maximumPosition;
	Long currentPosition;

	pageForm->GetScrollRange(SB_VERT, &minmumPosition, &maximumPosition); //세로 스크롤바의 최소,최대 이동값 가져오기
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_VERT); //세로 스크롤바의 이동 한계 값 가져오기 (여기선 최대값이 받아질듯)
	currentPosition = (Long)pageForm->GetScrollPos(SB_VERT); //현재 세로 스크롤바에서 썸의 위치 가져오기 

	currentPosition += 10; //현재 세로스크롤바의 썸 위치를 +10해서 옮겨지도록 세팅한다.

	if (currentPosition > maximumPosition) //만약 이동할수 있는 한계값을 초과하면 한계값과 동일하게 맞춰준다.
	{
		currentPosition = maximumPosition;
	}

	pageForm->SetScrollPos(SB_VERT, currentPosition); //지정된 값으로 썸의 위치를 변경한다.
}

OnVScrollLineDown& OnVScrollLineDown::operator=(const OnVScrollLineDown& soucre)
{
	return *this;
}

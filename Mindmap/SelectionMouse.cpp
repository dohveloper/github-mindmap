#include "SelectionMouse.h"
#include "Array.h"
#include "Topic.h"
#include "DrawingMouse.h"

MouseState* SelectionMouse::Instance() {
	return new SelectionMouse();
}

SelectionMouse::SelectionMouse() {

}
SelectionMouse::~SelectionMouse() {

}
void SelectionMouse::OnLButtonDown(MouseAction *mouseAction, CPoint point, Selection *selection, Branch *branch) {
	

	if(branch!=NULL){

	//1.이전 선택된 브랜치들을 모두 선택해제하다.
	selection->Clear();
	
	//2.클릭된 브랜치를 추가하다.
	selection->Add(branch);

	//3.드래그모드로 바꾸다.
	}
	
}

void SelectionMouse::OnLButtonUp(MouseAction * mouseAction, Selection * selection)
{
	Long length;
	
	//그리기모드로 다시 바꾸기
	if (selection->GetLength() > 0) {
		mouseAction->ChangeState(DrawingMouse::Instance());
	}
}


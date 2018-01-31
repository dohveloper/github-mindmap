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

	//1.���� ���õ� �귣ġ���� ��� ���������ϴ�.
	selection->Clear();
	
	//2.Ŭ���� �귣ġ�� �߰��ϴ�.
	selection->Add(branch);

	//3.�巡�׸��� �ٲٴ�.
	}
	
}

void SelectionMouse::OnLButtonUp(MouseAction * mouseAction, Selection * selection)
{
	Long length;
	
	//�׸������ �ٽ� �ٲٱ�
	if (selection->GetLength() > 0) {
		mouseAction->ChangeState(DrawingMouse::Instance());
	}
}


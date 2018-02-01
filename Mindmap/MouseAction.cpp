
#include "MouseAction.h"
#include "MouseState.h"
#include "SelectionMouse.h"
#include "Array.h"

MouseAction::MouseAction() {
	//할당해제? 
	state = SelectionMouse::Instance();
}
void MouseAction::OnLButtonDown(CPoint point, Selection *selection, Branch *branch) {
	state->OnLButtonDown(this,point,selection,branch);
}
void MouseAction::OnMouseMove(CPoint point) {
	state->OnMouseMove(this, point);
}
void MouseAction::OnLButtonUp(Selection *selection) {
	state->OnLButtonUp(this,selection);
}
void MouseAction::ChangeState(MouseState* mouseState) {
	state = mouseState;
}




#include "MouseAction.h"
#include "MouseState.h"
#include "DrawingMouse.h"
#include "Array.h"

MouseAction::MouseAction() {
	state = DrawingMouse::Instance();
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



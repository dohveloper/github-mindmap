#include "MouseState.h"
#include "MouseAction.h"
#include "Array.h"


MouseState::MouseState() {

}
MouseState::~MouseState() {

}
void MouseState::OnLButtonDown(MouseAction *mouseAction, CPoint point, Selection *selection, Branch *branch) {

}
void MouseState::OnMouseMove(MouseAction *mouseAction, CPoint point) {

}
void MouseState::OnLButtonUp(MouseAction *mouseAction, Selection *selection) {

}
void MouseState::ChangeState(MouseAction *mouseAction, MouseState* mouseState) {
	mouseAction->ChangeState(mouseState);
}
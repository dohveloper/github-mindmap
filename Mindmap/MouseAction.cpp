#include "MouseAction.h"
#include "Selection.h"
#include "MouseStrategy.h"
#include "DrawingStrategy.h"
#include "SelectionStrategy.h"


MouseAction::MouseAction(MouseStrategy * mouseStrategy)
{
	this->mouseStrategy = NULL;
}

void MouseAction::OnLButtonDown(CPoint point, UINT flags, Selection *selection, Branch *branch){
	//mouseStrategy->OnLButtonDown(point,flags,selection,branch);
}
void MouseAction::OnMouseMove(CPoint point) {
	//mouseStrategy->OnMouseMove(point);
}
void MouseAction::OnLButtonUp(Selection *selection, bool isOverlapped) {
	//mouseStrategy->OnLButtonUp(selection,true);
}

void MouseAction::SetStrategy(Branch * clickedBranch)
{
	delete this->mouseStrategy;

	if (clickedBranch == NULL) {
		this->mouseStrategy = new DrawingStrategy();
	}
	else if (clickedBranch != NULL) {
		this->mouseStrategy = new SelectionStrategy();
	}
}



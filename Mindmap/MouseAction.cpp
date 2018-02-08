#include "MouseAction.h"
#include "Selection.h"
#include "MouseStrategy.h"
#include "DrawingStrategy.h"
#include "SelectionStrategy.h"
#include "MarkStrategy.h"
#include "Topic.h"
#include "Mark.h"


MouseAction::MouseAction()
{
	this->mouseStrategy = NULL;
}

void MouseAction::OnLButtonDown(CPoint point, UINT flags, Selection *selection, Shape *shape){
	mouseStrategy->OnLButtonDown(point, flags, selection, shape);
}
void MouseAction::OnMouseMove(CPoint point) {
	mouseStrategy->OnMouseMove(point);
}
void MouseAction::OnLButtonUp(Selection *selection, bool isOverlapped) {
	mouseStrategy->OnLButtonUp(selection,true);
}

void MouseAction::SetStrategy(Shape *shape)
{
	//할당해제
	if (this->mouseStrategy != NULL) {
		delete this->mouseStrategy;
		this->mouseStrategy = NULL;
	}
	
	if (shape == NULL) {
		this->mouseStrategy = new DrawingStrategy();
	}
	else if (typeid(*shape) == typeid(Topic)) {
		this->mouseStrategy = new SelectionStrategy();
	}
	else if (typeid(*shape) == typeid(Mark)) {
		this->mouseStrategy = new MarkStrategy();
	}
}



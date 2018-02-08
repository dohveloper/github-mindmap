#include "MouseAction.h"
#include "Selection.h"
#include "MouseStrategy.h"
#include "DrawingStrategy.h"
#include "SelectionStrategy.h"
#include "MarkStrategy.h"
#include "Topic.h"
#include "Mark.h"
#include "HitTester.h"

MouseAction::MouseAction()
{
	this->mouseStrategy = NULL;
}

void MouseAction::OnLButtonDown(CPoint point, UINT flags, Selection *selection, Shape *shape) {
	mouseStrategy->OnLButtonDown(point, flags, selection, shape);
}
void MouseAction::OnMouseMove(CPoint point) {
	mouseStrategy->OnMouseMove(point);
}
void MouseAction::OnLButtonUp(Selection *selection, UINT nflags) {
	mouseStrategy->OnLButtonUp(selection, nflags);
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

Shape * MouseAction::GetClickedObject(Branch *branch, CPoint point)
{
	Shape *ret = NULL;

	HitTester hitTester(branch);

	if (hitTester.TestTopic(point)) {
		ret = hitTester.GetHitObject();
	}

	if (hitTester.TestMark(point)) {
		ret = hitTester.GetHitObject();
	}

	return ret;
}
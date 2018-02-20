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

void MouseAction::OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape) {
	mouseStrategy->OnLButtonDown(point, nFlags, selection, shape);
}
void MouseAction::OnMouseMove(CPoint point) {
	mouseStrategy->OnMouseMove(point);
}
void MouseAction::OnLButtonUp(Selection *selection, UINT nFlags, Branch *branch) {
	mouseStrategy->OnLButtonUp(selection, nFlags, branch);
}

void MouseAction::SetStrategy(Shape *shape)
{
	//�Ҵ�����
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
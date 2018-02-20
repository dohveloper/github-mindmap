#include "MouseAction.h"
#include "Selection.h"
#include "MouseStrategy.h"
#include "DrawingStrategy.h"
#include "SelectionStrategy.h"
#include "MarkStrategy.h"
#include "Topic.h"
#include "Mark.h"
#include "HitTester.h"
#include "PageForm.h"

MouseAction::MouseAction()
{
	this->mouseStrategy = NULL;
}

void MouseAction::OnLButtonDown(PageForm *pageForm, CPoint point, UINT nFlags, Shape *shape) {
	mouseStrategy->OnLButtonDown(pageForm, point, nFlags, shape);
}
void MouseAction::OnMouseMove(PageForm *pageForm, CPoint point) {
	mouseStrategy->OnMouseMove(pageForm, point);
}
void MouseAction::OnLButtonUp(PageForm *pageForm, UINT nFlags, Branch *branch) {
	mouseStrategy->OnLButtonUp(pageForm, nFlags, branch);
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
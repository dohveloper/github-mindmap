#include "DrawingMouse.h"
#include "Array.h"
#include "Branch.h"
#include "Topic.h"
#include "Line.h"
#include "SelectionMouse.h"
#define minimumTopicWidth 30
#define minimumTopicHeight 30

MouseState* DrawingMouse::Instance() {
	return new DrawingMouse();
}

DrawingMouse::DrawingMouse() {
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}
DrawingMouse::~DrawingMouse() {

}
void DrawingMouse::OnLButtonDown(MouseAction *mouseAction, CPoint point, Selection *selection, Branch *branch) {
	this->x = point.x;
	this->y = point.y;
	this->width = 0;
	this->height = 0;
	
}

void DrawingMouse::OnMouseMove(MouseAction *mouseAction, CPoint point) {
	this->width = point.x - this->x;
	this->height = point.y - this->y;
}
void DrawingMouse::OnLButtonUp(MouseAction *mouseAction, Selection *selection) {
	
	Long startX;
	Long startY;
	Long lineWidth;
	Long lineHeight;
	Branch *branch;
	Topic *selectedTopic;

	if (this->width > minimumTopicWidth && this->height > minimumTopicHeight &&selection->GetLength()>0) {

		// 1.������ ������,�ʺ�,���̸� ���Ѵ�.
		selectedTopic = selection->GetLastSelection()->GetTopic();
		startX = selectedTopic->GetX() + selectedTopic->GetWidth() / 2;
		startY = selectedTopic->GetY() + selectedTopic->GetHeight() / 2;
		lineWidth = this->x + this->width / 2 - startX;
		lineHeight = this->y + this->height / 2 - startY;

		// 2.�� �귣ġ�� ����� ���Ȱ� ������ �߰��Ѵ�.
	
		branch=new Branch(); 
		branch->Add(new Line(startX, startY, lineWidth, lineHeight, ""));
		branch->Add(new Topic(this->x, this->y, this->width, this->height, ""));
	
	
		// 3.���õ� �귣ġ�� �� �귣ġ�� �߰��Ѵ�.
		selection->GetLastSelection()->Add(branch);
	
		//�������� �߰��� �귣ġ �����ϱ�
		selection->Clear();
		selection->Add(branch);
	}
	else {
		//ũ�� �ʹ� ������ ���û��·� �ٲٱ�
		if (this->width <= 1 || this->height <= 1) {
			selection->Clear();
		}
		mouseAction->ChangeState(SelectionMouse::Instance());
	}

}


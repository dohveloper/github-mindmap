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

		// 1.라인의 시작점,너비,높이를 구한다.
		selectedTopic = selection->GetLastSelection()->GetTopic();
		startX = selectedTopic->GetX() + selectedTopic->GetWidth() / 2;
		startY = selectedTopic->GetY() + selectedTopic->GetHeight() / 2;
		lineWidth = this->x + this->width / 2 - startX;
		lineHeight = this->y + this->height / 2 - startY;

		// 2.새 브랜치를 만들고 토픽과 라인을 추가한다.
	
		branch=new Branch(); 
		branch->Add(new Line(startX, startY, lineWidth, lineHeight, ""));
		branch->Add(new Topic(this->x, this->y, this->width, this->height, ""));
	
	
		// 3.선택된 브랜치에 새 브랜치를 추가한다.
		selection->GetLastSelection()->Add(branch);
	
		//모두지우고 추가된 브랜치 선택하기
		selection->Clear();
		selection->Add(branch);
	}
	else {
		//크기 너무 작으면 선택상태로 바꾸기
		if (this->width <= 1 || this->height <= 1) {
			selection->Clear();
		}
		mouseAction->ChangeState(SelectionMouse::Instance());
	}

}


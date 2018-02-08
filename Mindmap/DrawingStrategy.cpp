#include "DrawingStrategy.h"
#include "Array.h"
#include "Branch.h"
#include "Mark.h"
#include "Topic.h"
#include "Line.h"
#include "Mark.h"
#include "Selection.h"
#include "UnFoldVisitor.h"
#define minimumTopicWidth 30
#define minimumTopicHeight 30

DrawingStrategy::DrawingStrategy() {
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}
DrawingStrategy::~DrawingStrategy() {
}
void DrawingStrategy::OnLButtonDown(CPoint point, UINT nFlags, Selection *selection, Shape *shape) {
	this->x = point.x;
	this->y = point.y;
	this->width = 0;
	this->height = 0;
}

void DrawingStrategy::OnMouseMove(CPoint point) {
	this->width = point.x - this->x;
	this->height = point.y - this->y;
}
void DrawingStrategy::OnLButtonUp(Selection *selection, UINT nFlags) {
	Long startX;
	Long startY;
	Long lineWidth;
	Long lineHeight;
	Branch *branch;
	Topic *selectedTopic;

	if (selection->GetLength() > 0 && this->width > 1 && this->height > 1 && this->width > minimumTopicWidth && this->height > minimumTopicHeight) {
		// 1.라인의 시작점,너비,높이를 구한다.
		selectedTopic = selection->GetLastSelection()->GetTopic();
		startX = selectedTopic->GetX() + selectedTopic->GetWidth() / 2;
		startY = selectedTopic->GetY() + selectedTopic->GetHeight() / 2;
		lineWidth = this->x + this->width / 2 - startX;
		lineHeight = this->y + this->height / 2 - startY;

		// 2.새 브랜치를 만들고 토픽과 라인, 마크를 추가한다.

		branch = new Branch();
		branch->Add(new Line(startX, startY, lineWidth, lineHeight, "", branch));
		branch->Add(new Topic(this->x, this->y, this->width, this->height, "", branch));
		branch->Add(new Mark(this->x + 14 * this->width / 15, this->y + this->height / 4));

		UnFoldVisitor visitor;

		selection->GetLastSelection()->Accept(visitor);//새 브랜치 추가시 하위 브랜치 펼친다

													   // 3.선택된 브랜치에 새 브랜치를 추가한다.
		selection->GetLastSelection()->Add(branch);

		//선택된 브랜치의 마크를 +에서 -로 바꾼다.
		selection->GetLastSelection()->GetMark()->SetContent("-");

		//모두지우고 추가된 브랜치 선택하기
		selection->Clear();
		selection->Add(branch);
	}

	else if (selection->GetLength() > 0 && this->width < 1 && this->height < 1) {
		selection->Clear();
	}
}
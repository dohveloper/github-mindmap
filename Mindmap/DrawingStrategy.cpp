#include "DrawingStrategy.h"
#include "Array.h"
#include "Branch.h"
#include "Mark.h"
#include "Topic.h"
#include "Line.h"
#include "Mark.h"
#include "Selection.h"
#include "UnFoldVisitor.h"
#include "OverlappedConfirmVisitor.h"
#include "PageForm.h"
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
void DrawingStrategy::OnLButtonDown(PageForm *pageForm, CPoint point, UINT nFlags, Shape *shape) {
	this->x = point.x;
	this->y = point.y;
	this->width = 0;
	this->height = 0;
}

void DrawingStrategy::OnMouseMove(PageForm *pageForm, CPoint point) {
	this->width = point.x - this->x;
	this->height = point.y - this->y;
}
void DrawingStrategy::OnLButtonUp(PageForm *pageForm, UINT nFlags, Branch *branch) {
	bool isOverlapped;
	Long startX;
	Long startY;
	Long lineWidth;
	Long lineHeight;
	Branch *temp;
	Topic *selectedTopic;
	CRect rect(this->x, this->y, this->x + this->width, this->y + this->height);
	OverlappedConfirmVisitor testVisitor(rect);

	branch->Accept(testVisitor);
	isOverlapped = testVisitor.GetIsOverlapped();

	if (pageForm->selection.GetLength() > 0 && this->width > 1 && this->height > 1 && this->width > minimumTopicWidth && this->height > minimumTopicHeight && isOverlapped == false) {
		// 1.라인의 시작점,너비,높이를 구한다.
		selectedTopic = pageForm->selection.GetLastSelection()->GetTopic();
		startX = selectedTopic->GetX() + selectedTopic->GetWidth() / 2;
		startY = selectedTopic->GetY() + selectedTopic->GetHeight() / 2;
		lineWidth = this->x + this->width / 2 - startX;
		lineHeight = this->y + this->height / 2 - startY;

		// 2.새 브랜치를 만들고 토픽과 라인, 마크를 추가한다.

		temp = new Branch();
		temp->Add(new Line(startX, startY, lineWidth, lineHeight, "", temp));
		temp->Add(new Topic(this->x, this->y, this->width, this->height, "", temp));
		temp->Add(new Mark(this->x + 14 * this->width / 15, this->y + this->height / 4));

		//새 브랜치 추가시 하위 브랜치 펼친다
		if (pageForm->selection.GetLastSelection()->GetMark()->GetContent() == "+") {
			UnFoldVisitor visitor;
			pageForm->selection.GetLastSelection()->Accept(visitor);
		}
		// 3.선택된 브랜치에 새 브랜치를 추가한다.
		pageForm->selection.GetLastSelection()->Add(temp);

		//선택된 브랜치의 마크를 +에서 -로 바꾼다.
		pageForm->selection.GetLastSelection()->GetMark()->SetContent("-");

		//모두지우고 추가된 브랜치 선택하기
		pageForm->selection.Clear();
		pageForm->selection.Add(temp);
	}

	else if (pageForm->selection.GetLength() > 0 && this->width < 1 && this->height < 1) {
		pageForm->selection.Clear();
	}
}
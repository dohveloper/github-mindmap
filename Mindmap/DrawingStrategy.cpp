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
#include "BranchArrange.h"
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
void DrawingStrategy::OnLButtonUp(Selection *selection, UINT nFlags, Branch *branch) {
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

	if (selection->GetLength() > 0 && this->width > 1 && this->height > 1 && this->width > minimumTopicWidth && this->height > minimumTopicHeight && isOverlapped == false) {
		// 1.������ ������,�ʺ�,���̸� ���Ѵ�.
		selectedTopic = selection->GetLastSelection()->GetTopic();
		startX = selectedTopic->GetX() + selectedTopic->GetWidth() / 2;
		startY = selectedTopic->GetY() + selectedTopic->GetHeight() / 2;
		lineWidth = this->x + this->width / 2 - startX;
		lineHeight = this->y + this->height / 2 - startY;

		// 2.�� �귣ġ�� ����� ���Ȱ� ����, ��ũ�� �߰��Ѵ�.

		temp = new Branch();
		temp->Add(new Line(startX, startY, lineWidth, lineHeight, "", temp));
		temp->Add(new Topic(this->x, this->y, this->width, this->height, "", temp));
		temp->Add(new Mark(this->x + 14 * this->width / 15, this->y + this->height / 4));

		//�� �귣ġ �߰��� ���� �귣ġ ��ģ��
		if (selection->GetLastSelection()->GetMark()->GetContent() == "+") {
			UnFoldVisitor visitor;
			selection->GetLastSelection()->Accept(visitor);
		}
		// 3.���õ� �귣ġ�� �� �귣ġ�� �߰��Ѵ�.
		selection->GetLastSelection()->Add(temp);

		//�귣ġ ����
		BranchArrange branchArrange;
		branchArrange.Arrange(selection->GetLastSelection());


		//���õ� �귣ġ�� ��ũ�� +���� -�� �ٲ۴�.
		selection->GetLastSelection()->GetMark()->SetContent("-");

		//�������� �߰��� �귣ġ �����ϱ�
		selection->Clear();
		selection->Add(temp);
	}

	else if (selection->GetLength() > 0 && this->width < 1 && this->height < 1) {
		selection->Clear();
	}
}
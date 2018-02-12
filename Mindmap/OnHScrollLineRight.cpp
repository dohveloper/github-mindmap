//OnHScrollLineRight.cpp

#include "OnHScrollLineRight.h"
#include "ScrollingVisitor.h"

OnHScrollLineRight::OnHScrollLineRight()
{
}

OnHScrollLineRight::OnHScrollLineRight(const OnHScrollLineRight& source)
{
}

OnHScrollLineRight::~OnHScrollLineRight()
{
}

void OnHScrollLineRight::Scrolling(PageForm *pageForm)
{
	Long minmumPosition;
	Long maximumPosition;
	Long currentPosition;
	//Long length;
	//Branch branch;
	//Long i = 0;
	//Long x;
	//Long y;
	//Long width;
	//Long height;
	//string content;
	//Long drawingPosition;

	pageForm->GetScrollRange(SB_HORZ, (int*)&minmumPosition, (int*)&maximumPosition);
	maximumPosition = (Long)pageForm->GetScrollLimit(SB_HORZ);
	currentPosition = (Long)pageForm->GetScrollPos(SB_HORZ);

	//drawingPosition = 10;
	currentPosition += 10;

	if (currentPosition > maximumPosition)
	{
		currentPosition = maximumPosition;
	}

	pageForm->SetScrollPos(SB_HORZ, currentPosition);

	//ScrollingVisitor visitor(&dc);

	//pageForm->branch->Accept(visitor);

	//length = this->branch->GetLength();
	/*
	while (i < length)
	{
		x = this->branch->GetAt(i)->GetX();
		y = this->branch->GetAt(i)->GetY();
		width = this->branch->GetAt(i)->GetWidth();
		height = this->branch->GetAt(i)->GetHeight();
		content = this->branch->GetAt(i)->GetContent();

		if (i % 2 == 0 && i != 0)
		{
			this->branch->Correct(i, new Line(x + drawingPosition, y, width, height, content));
		}
		else
		{

			this->branch->Correct(i, new Topic(x + drawingPosition, y, width, height, content));
		}
		*/
}

OnHScrollLineRight& OnHScrollLineRight::operator=(const OnHScrollLineRight& source)
{
	return *this;
}

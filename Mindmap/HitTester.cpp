#include "HitTester.h"
#include "Shape.h"
#include "TopicHitTest.h"
#include "MarkHitTest.h"

HitTester::HitTester()
{
	this->branch = NULL;
	this->hitObject = NULL;
	this->isHit = false;
}

HitTester::HitTester(Branch * branch)
{
	this->branch = branch;
}

HitTester::HitTester(const HitTester & source)
{
	this->branch = source.branch;
	this->hitObject = source.hitObject;
	this->isHit = source.isHit;
}

HitTester::~HitTester()
{
}

HitTester & HitTester::operator=(const HitTester & source)
{
	this->branch = source.branch;
	this->hitObject = source.hitObject;
	this->isHit = source.isHit;
	return *this;
}

bool HitTester::TestTopic(CPoint point)
{
	TopicHitTest topicHitTest(this->branch, point);
	topicHitTest.Traverse();

	this->hitObject = (Shape*)topicHitTest.GetHitTopic();
	this->isHit = topicHitTest.GetIsHit();

	return this->isHit;
}

bool HitTester::TestMark(CPoint point)
{
	MarkHitTest markHitTest(this->branch, point);
	markHitTest.Traverse();

	this->hitObject = (Shape*)markHitTest.GetHitMark();
	this->isHit = markHitTest.GetIsHit();

	return this->isHit;
}
#ifndef _HITTESTER_H
#define _HITTESTER_H
#include <afxwin.h>

class Shape;
class Branch;

class HitTester
{
public:
	HitTester();
	HitTester(Branch *branch);
	HitTester(const HitTester& source);
	~HitTester();

	HitTester& operator=(const HitTester& source);

	bool TestTopic(CPoint point);
	bool TestMark(CPoint point);

	Shape* GetHitObject() const;
	bool GetIsHit() const;

private:
	Branch * branch;
	Shape * hitObject;
	bool isHit;
};

inline Shape* HitTester::GetHitObject() const {
	return const_cast<Shape*>(this->hitObject);
}

inline bool HitTester::GetIsHit() const {
	return this->isHit;
}
#endif //_HITTESTER_H
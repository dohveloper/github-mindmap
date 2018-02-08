#ifndef _HITTESTER_H
#define _HITTESTER_H
#include <afxwin.h>

class Shape;

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

private:
	Branch * branch;
	Shape * hitObject;
	bool isHit;
};
#endif //_HITTESTER_H
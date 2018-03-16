//Page.h

#ifndef _PAGE_H
#define _PAGE_H

#include "Composite.h"
using namespace std;

typedef signed long int Long;

class Page : public Composite {
public:
	Page(Long capacity = 256);
	Page(const Page& source);
	virtual ~Page();

	Page& operator=(const Page& source);
};

#endif //_PAGE_H
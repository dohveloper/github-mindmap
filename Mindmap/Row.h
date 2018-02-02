//Row.h

#ifndef _ROW_H
#define _ROW_H

#include "TextComposite.h"

typedef signed long int Long;

class Row : public TextComposite {
public:
	Row(Long capacity = 256);
	Row(const Row& source);
	virtual ~Row();

	void Accept(TextVisitor& textVisitor);
	Row& operator=(const Row& source);
};

#endif //_ROW_H
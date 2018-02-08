//Text.h

#ifndef _TEXT_H
#define _TEXT_H

#include "Row.h"
#include "TextComposite.h"
typedef signed long int Long;

class Text : public TextComposite {
public:
	Text(Long capacity = 256);
	Text(const Text& source);
	virtual ~Text();

	string MakeString();

	virtual void Accept(TextVisitor& textVisitor);

	Text& operator=(const Text& source);
};

#endif //TEXT_H
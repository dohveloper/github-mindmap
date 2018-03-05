//Row.h

#ifndef _ROW_H
#define _ROW_H

#include "TextComposite.h"

typedef signed long int Long;

class Row : public TextComposite {
public:
	Row(Long capacity = 256);
	Row(bool isWordWrap);
	Row(const Row& source);
	virtual ~Row();

	string MakeString();
	Row* Clone();

	void Accept(TextVisitor& textVisitor);
	Row& operator=(const Row& source);

	bool SetIsWordWrap(bool isWordWrap);

	bool GetIsWordWrap() const;
private:
	bool isWordWrap;
};

inline bool Row::GetIsWordWrap() const {
	return this->isWordWrap;
}



#endif //_ROW_H
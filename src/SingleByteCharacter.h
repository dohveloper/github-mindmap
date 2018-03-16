//SingleByteCharacter.h

#ifndef _SINGLEBYTECHARACTER_H
#define _SINGLEBYTECHARACTER_H

#include "Character.h"

class SingleByteCharacter : public Character{

public:
	SingleByteCharacter();
	SingleByteCharacter(char character);
	SingleByteCharacter(const SingleByteCharacter& source);
	virtual ~SingleByteCharacter();
	
	void Accept(TextVisitor& textVisitor);

	bool IsEqual(const SingleByteCharacter& other);
	bool IsNotEqual(const SingleByteCharacter& other);

	string MakeString();
	bool operator==(const SingleByteCharacter& other);
	bool operator!=(const SingleByteCharacter& other);

	SingleByteCharacter& operator=(const SingleByteCharacter& source);

	char GetCharacter() const;

private:
	char character;
};


inline char SingleByteCharacter::GetCharacter() const {
	return this->character;
}

#endif //_SINGLEBYTECHARACTER_H

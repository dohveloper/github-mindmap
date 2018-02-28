//DoubleByteCharacter.h

#ifndef _DOUBLEBYTECHARACTER_H
#define _DOUBLEBYTECHARACTER_H

#include <string>

#include "Character.h"

class DoubleByteCharacter : public Character {
public:
	DoubleByteCharacter();
	DoubleByteCharacter(const char (*characters));
	DoubleByteCharacter(const DoubleByteCharacter& source);
	virtual ~DoubleByteCharacter();

	void Accept(TextVisitor& textVisitor);
	DoubleByteCharacter* Clone();

	bool IsEqual(const DoubleByteCharacter& other);
	bool IsNotEqual(const DoubleByteCharacter& other);
	string MakeString();
	DoubleByteCharacter* Clone();
	bool operator==(const DoubleByteCharacter& other);
	bool operator!=(const DoubleByteCharacter& other);

	DoubleByteCharacter& operator=(const DoubleByteCharacter& source);

	string GetCharacters() const;
private:
	char characters[3];

};

inline string DoubleByteCharacter::GetCharacters() const {
	string x;

	x = this->characters;

	return x;
}
#endif //_DOUBLEBYTECHARACTER_H
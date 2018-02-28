//Character.h

#ifndef _CHARACTER_H
#define _CHARACTER_H

typedef signed long int Long;

#include "afxwin.h"
#include "string"
using namespace std;

class TextVisitor;
class SingleByteCharacter;
class DoubleByteCharacter;
class Character {
public:
	Character();
	virtual ~Character()=0;
	virtual Long Write(Character *character);
	virtual Long Insert(Long index, Character *character);
	virtual Long Correct(Long index, Character *character);
	virtual Long Delete(Long index);
	virtual Character* GetAt(Long index);
	virtual string MakeString();
	virtual string MakeString(Long start,Long end);
	virtual bool IsEqual(const Character& source);
	virtual bool IsNotEqual(const Character& source);
	virtual Long GetRowWidth(CDC *cdc,Long start, Long end);
	virtual Long GetHeight(CDC *cdc, Long index);
	virtual void Accept(TextVisitor& textVisitor);
	virtual Character* Clone();
	virtual char GetCharacter() const;
	virtual string GetCharacters() const;
	virtual Long GetLength() const;
	virtual Long GetCapacity() const;
	virtual bool GetIsWordWrap() const;
};
inline char Character::GetCharacter() const {
	return 0;
}

inline string Character::GetCharacters() const {
	return 0;
}

inline Long Character::GetCapacity() const {
	return -1;
}

inline Long Character::GetLength() const {
	return -1;
}
inline bool Character::GetIsWordWrap() const {
	return 0;
}
#endif //_CHARACTER_H
//TextComposite.h

#ifndef _TEXTCOMPOSITE_H
#define _TEXTCOMPOSITE_H

#include "Character.h"
#include "Array.h"
#include <afxwin.h>

class Character;
class TextComposite :public Character {
public:
	TextComposite(Long capacity = 256);
	TextComposite(const TextComposite& source);
	virtual ~TextComposite();
	Long Write(Character *character);
	Long Insert(Long index, Character *character);
	Long Correct(Long index, Character *character);
	Character* GetAt(Long index);
	virtual string MakeString();
	string MakeString(Long start, Long end);
	TextComposite& operator=(const TextComposite& source);

	Long GetRowWidth(CDC *cdc,Long index);
	Long GetHeight(CDC *cdc, Long index);

	Long GetCapacity() const;
	Long GetLength() const;
protected:
	Array<Character*> characters;
	Long capacity;
	Long length;
};

inline Long TextComposite::GetCapacity() const {
	return this->capacity;
}

inline Long TextComposite::GetLength() const {
	return this->length;
}

#endif //_TEXTCOMPOSITE_H
//TextClipboard.h

#ifndef TEXTCLIPBOARD_H
#define TEXTCLIPBOARD_H

#include "Array.h"
#include <afxwin.h>

typedef signed long int Long;

class TextForm;
class Character;
class TextClipboard
{
public:
	TextClipboard(Long capacity = 256);
	TextClipboard(const TextClipboard& source);
	~TextClipboard();

	Long Add(Character *character);
	Character* GetAt(Long index);

	//TextClipboard& operator=(const TextClipboard& source);

	Long GetCapacity() const;
	Long GetLength() const;

private:
	Array<Character*> textClipboard;
	Long capacity;
	Long length;
};

inline Long TextClipboard::GetCapacity()const
{
	return this->capacity;
}

inline Long TextClipboard::GetLength()const
{
	return this->length;
}

#endif _TEXTCLIPBOARD_H

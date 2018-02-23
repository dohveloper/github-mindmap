//TextClipboard.cpp

#include "TextClipboard.h"
#include "TextForm.h"
#include "Row.h"
#include "Text.h"
#include "SelectText.h"

TextClipboard::TextClipboard(Long capacity)
:textClipboard(capacity){
	this->capacity = capacity;
	this->length = 0;
}

TextClipboard::TextClipboard(const TextClipboard& source)
:textClipboard(source.textClipboard){
	this->capacity = source.capacity;
	this->length = source.length;
}

TextClipboard::~TextClipboard()
{
}

Long TextClipboard::Add(Character *character) {
	Long index;

	if (this->length < this->capacity)
	{
		index = this->textClipboard.Store(this->length, character);
	}
	else
	{
		index = this->textClipboard.AppendFromRear(character);
		this->capacity++;
	}
	this->length++;

	return index;
}



Character* TextClipboard::GetAt(Long index) 
{
	return this->textClipboard.GetAt(index);
}



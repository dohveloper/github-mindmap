//TextComposite.cpp

#include "TextComposite.h"
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"



TextComposite::TextComposite(Long capacity)
	:characters(capacity) {
	this->capacity = capacity;
	this->length = 0;
}

TextComposite::TextComposite(const TextComposite& source)
	: characters(source.characters) {
	this->capacity = source.capacity;
	this->length = source.length;
}

TextComposite::~TextComposite() {

}

Long TextComposite::Write(Character *character) {
	Long index;

	if (this->length < this->capacity)
	{
		index = this->characters.Store(this->length, character);
	}
	else
	{
		index = this->characters.AppendFromRear(character);
		this->capacity++;
	}
	this->length++;

	return index;
}

Long TextComposite::Insert(Long index, Character *character) {
	index = this->characters.Insert(index, character);
	this->capacity++;
	this->length++;

	return index;
}

Long TextComposite::Correct(Long index, Character *character) {
	index = this->characters.Modify(index, character);
	return index;
}

Character* TextComposite::GetAt(Long index) {
	return this->characters.GetAt(index);
}

string TextComposite::MakeString() {
	string text = "";
	Long i = 0;
	Character *character;

	while (i < this->length)
	{
		character = this->characters[i];
		
		text = text + character->MakeString();
		
		i++;
	}
	
	return text;
}

Long TextComposite::GetRowWidth(CDC *cdc,Long index) {
	Long i = 0;
	string word;
	Long width=0;
	
	while (i < index)
	{
		word = this->GetAt(i)->MakeString();

		width += cdc->GetTextExtent((CString)word.c_str()).cx;
		
		i++;
	}
	
	return width;
}

Long TextComposite::GetHeight(CDC *cdc) {
	string word;

	word = this->GetAt(0)->MakeString();

	Long height = cdc->GetTextExtent((CString)word.c_str()).cy;

	return height;
}

TextComposite& TextComposite::operator=(const TextComposite& source) {
	this->characters = source.characters;
	this->capacity = source.capacity;
	this->length = source.length;

	return *this;
}

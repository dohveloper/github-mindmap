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

Long TextComposite::Delete(Long index) {
	index = this->characters.Delete(index);
	this->capacity--;
	this->length--;
	return index;
}

Character* TextComposite::GetAt(Long index) {
	return this->characters.GetAt(index);
}

string TextComposite::MakeString() {
	
	return 0;
}

string TextComposite::MakeString(Long start, Long end) {
	string text = "";
	Character *character;

	while (start < end)
	{
		if (this->GetAt(start)->MakeString().compare("\t") == 0)
		{
			text += "        ";
		}
		else
		{
			text += this->GetAt(start)->MakeString();
		}
		start++;
	}
	return text;
}

Long TextComposite::GetRowWidth(CDC *cdc,Long start,Long end) {
	string word;
	Long width=0;
	
	while (start < end)
	{
		if (this->GetAt(start)->MakeString().compare("\t")==0)
		{
			word += "        ";
		}
		else
		{
			word += this->GetAt(start)->MakeString();
		}
		start++;
	}
	width = cdc->GetTextExtent((CString)word.c_str()).cx;
	return width;
}

Long TextComposite::GetHeight(CDC *cdc, Long index) 
{
	string word;
	Long i = 0;
	Long height=0;

	while (i < index)
	{
		word = this->GetAt(i)->MakeString();
		height += cdc->GetTextExtent((CString)word.c_str()).cy;
		i++;
	}

	return height;
}


TextComposite& TextComposite::operator=(const TextComposite& source) {
	this->characters = source.characters;
	this->capacity = source.capacity;
	this->length = source.length;

	return *this;
}

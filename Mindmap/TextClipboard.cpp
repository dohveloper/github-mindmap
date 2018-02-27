//TextClipboard.cpp

#include "TextClipboard.h"
#include "Character.h"
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
	Long index=0;
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

/*
#include <iostream>
#include <string>
using namespace std;
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
int main(int argc, char *argv[])
{
	TextClipboard* textClipboard = new TextClipboard();
	SingleByteCharacter singleByteCharacter1('a');
	SingleByteCharacter singleByteCharacter2('b');
	DoubleByteCharacter doubleByteCharacter1("°¡");
	DoubleByteCharacter doubleByteCharacter2("³ª");

	textClipboard->Add(&singleByteCharacter1);
	textClipboard->Add(&singleByteCharacter2);
	textClipboard->Add(&doubleByteCharacter1);
	textClipboard->Add(&doubleByteCharacter2);

	cout << textClipboard->GetLength() << endl;
	cout << textClipboard->GetAt(0)->MakeString() << endl;
	cout << textClipboard->GetAt(1)->MakeString() << endl;
	cout << textClipboard->GetAt(2)->MakeString() << endl;
	cout << textClipboard->GetAt(3)->MakeString() << endl;

	return 0;
}*/


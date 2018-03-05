//DoubleByteCharacter.cpp

#include "DoubleByteCharacter.h"
#include "TextVisitor.h"
#include <string.h>
#pragma warning(disable : 4996)

DoubleByteCharacter::DoubleByteCharacter() {

}

DoubleByteCharacter::DoubleByteCharacter(const char(*characters))
{
	strcpy(this->characters, characters);
}

DoubleByteCharacter::DoubleByteCharacter(const DoubleByteCharacter& source)
{
	strcpy(this->characters, source.characters);
}

DoubleByteCharacter::~DoubleByteCharacter()
{

}

void DoubleByteCharacter::Accept(TextVisitor& textVisitor) {
	textVisitor.VisitDoubleByteCharacter(this);
}

DoubleByteCharacter* DoubleByteCharacter::Clone()
{
	return new DoubleByteCharacter(*this);
}

bool DoubleByteCharacter::IsEqual(const DoubleByteCharacter& other) {
	bool ret = false;

	if (strcmp(this->characters, other.characters) == 0)
	{
		ret = true;
	}
	return ret;
}

bool DoubleByteCharacter::IsNotEqual(const DoubleByteCharacter& other) {
	bool ret = false;

	if (strcmp(this->characters, other.characters) != 0)
	{
		ret = true;
	}
	return ret;
}

string DoubleByteCharacter::MakeString() {
	string word = this->characters;

	return word;
}

bool DoubleByteCharacter::operator==(const DoubleByteCharacter& other) {
	bool ret = false;
	if (strcmp(this->characters, other.characters) == 0)
	{
		ret = true;
	}
	return ret;
}

bool DoubleByteCharacter::operator!=(const DoubleByteCharacter& other) {
	bool ret = false;
	if (strcmp(this->characters, other.characters) != 0)
	{
		ret = true;
	}
	return ret;
}

DoubleByteCharacter& DoubleByteCharacter::operator=(const DoubleByteCharacter& source) {
	strcpy(this->characters, source.characters);
	return *this;
}

/*
#include <iostream>
int main(int argc, char *argv[]) {

DoubleByteCharacter doubleByteCharacter1("±Ë");
DoubleByteCharacter doubleByteCharacter2("¿Â");
DoubleByteCharacter doubleByteCharacter3("±Ë");
bool ret;

ret = doubleByteCharacter1.IsEqual(doubleByteCharacter3);
if (ret == true)
{
cout << "¿œ™y¥œ¥Ÿ" << endl;
}
ret = doubleByteCharacter1.IsNotEqual(doubleByteCharacter2);
if (ret != false)
{
cout << "æ»¿œ™y¥œ¥Ÿ" << endl;
}

string x;

x = doubleByteCharacter1.GetCharacters();

cout << x << endl;

x= doubleByteCharacter1.MakeString();
cout << x << endl;
return 0;
}
*/
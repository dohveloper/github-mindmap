//SingleByteCharacter.cpp

#include "TextVisitor.h"
#include "SingleByteCharacter.h"
#include <string>

SingleByteCharacter::SingleByteCharacter() {

}

SingleByteCharacter::SingleByteCharacter(char character) {
	this->character = character;
}

SingleByteCharacter::SingleByteCharacter(const SingleByteCharacter& source) {
	this->character = source.character;
}

SingleByteCharacter::~SingleByteCharacter() {

}

void SingleByteCharacter::Accept(TextVisitor& textVisitor) {
	textVisitor.VisitSingleByteCharacter(this);
}

SingleByteCharacter* SingleByteCharacter::Clone()
{
	return new SingleByteCharacter(*this);
}


bool SingleByteCharacter::IsEqual(const SingleByteCharacter& other) {
	bool ret = false;

	if (this->character == other.character)
	{
		ret = true;
	}
	return ret;
}

bool SingleByteCharacter::IsNotEqual(const SingleByteCharacter& other) {
	bool ret = false;

	if (this->character != other.character)
	{
		ret = true;
	}
	return ret;
}

string SingleByteCharacter::MakeString() {
	char x[2];

	x[0] = this->character;
	x[1] = '\0';

	string word(x);

	return word;
}


bool SingleByteCharacter::operator==(const SingleByteCharacter& other) {
	bool ret= false;

	if (this->character == other.character) {
		ret = true;
	}
	return ret;
}

bool SingleByteCharacter::operator!=(const SingleByteCharacter& other) {
	bool ret = false;

	if (this->character != other.character) {
		ret = true;
	}
	return ret;
}

SingleByteCharacter& SingleByteCharacter::operator=(const SingleByteCharacter& source) {
	this->character = source.character;

	return *this;
}


/*

#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
SingleByteCharacter singleByteCharacter('a');
SingleByteCharacter singleByteCharacter1('b');
SingleByteCharacter singleByteCharacter2('c');
SingleByteCharacter singleByteCharacter3(singleByteCharacter);

bool ret;

ret=singleByteCharacter.IsEqual(singleByteCharacter3);

if (ret == true)
{
cout << "일치합니다" << endl;
}

ret = singleByteCharacter.IsNotEqual(singleByteCharacter2);

if (ret == true)
{
cout << "일치ㄴㄴ합니다" << endl;
}

if (singleByteCharacter == singleByteCharacter3)
{
cout << "일치합니다" << endl;
}

if (singleByteCharacter2 != singleByteCharacter3)
{
cout << "일치ㄴㄴ합니다" << endl;
}
singleByteCharacter2 = singleByteCharacter3;
if (singleByteCharacter2 == singleByteCharacter3)
{
cout << "일치합니다" << endl;
}

string x = singleByteCharacter1.MakeString();

cout << x << endl;
return 0;
}
*/
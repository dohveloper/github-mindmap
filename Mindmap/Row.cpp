//Row.cpp

#include "Row.h"
#include "TextVisitor.h"

Row::Row(Long capacity) {

}

Row::Row(const Row& source)
	:TextComposite(source){

}

Row::~Row()
{

}

string Row::MakeString() {
	string text = "";
	Long i = 0;
	Character *character;

	while (i < this->length)
	{
		if (this->GetAt(i)->MakeString().compare("\t") == 0)
		{
			text += "        ";
		}
		else
		{
			text += this->GetAt(i)->MakeString();
		}
		i++;
	}
	return text;
}

void Row::Accept(TextVisitor& textVisitor) {
	textVisitor.VisitRow(this);
}


Row& Row::operator=(const Row& source)
{
	this->characters = source.characters;
	this->capacity = source.capacity;
	this->length = source.length;

	return *this;
}

/*
#include <iostream>
#include "SingleByteCharacter.h"
#include "DoubleByteCharacter.h"
int main(int argc, char *argv[]) {
	Row row;
	Long index;
	Long i = 0;

	index = row.Write(new SingleByteCharacter('a'));
	cout << row.GetAt(index)->GetCharacter() << endl;

	index = row.Write(new SingleByteCharacter('b'));
	cout << row.GetAt(index)->GetCharacter() << endl;

	

	Row branch1(row);

	branch1.Correct(index, new SingleByteCharacter('c'));

	while (i < branch1.GetLength())
	{
		cout << branch1.GetAt(i)->GetCharacter() << endl;
		i++;
	}

	Row branch2;
	branch2 = branch1;
	i = 0;
	while (i < branch2.GetLength())
	{
		cout << branch2.GetAt(i)->GetCharacter() << endl;
		i++;
	}

	index = row.Write(new DoubleByteCharacter("°¢"));
	cout << row.GetAt(index)->GetCharacters() << endl;

	index = row.Write(new DoubleByteCharacter(""));
	cout << row.GetAt(index)->GetCharacters() << endl;
	index = row.Write(new SingleByteCharacter(' '));
	cout << row.GetAt(index)->GetCharacter() << endl;

	string text = "";
	i = 0;
	SingleByteCharacter *singleLink;
	DoubleByteCharacter *doubleLink;
	Character *character;

	while (i < row.GetLength())
	{
		character = row.GetAt(i);
		if (typeid(*character) == typeid(SingleByteCharacter))
		{
			singleLink = (SingleByteCharacter*)character;
			if (singleLink->GetCharacter() == ' ')
			{
				cout << "aaa" << endl;
			}
			text = text + singleLink->GetCharacter();

		}
		else if (typeid(*character) == typeid(DoubleByteCharacter))
		{
			doubleLink = (DoubleByteCharacter*)character;
			if (doubleLink->GetCharacters().compare("")==0)
			{
				cout << "aaa" << endl;
			}
			text = text + doubleLink->GetCharacters();
		}
		cout << text << endl;
		i++;
	}

	string x = row.MakeString();
	cout << x << endl;

	return 0;
}
*/
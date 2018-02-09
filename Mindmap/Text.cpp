//Text.cpp

#include "Text.h"
#include "TextVisitor.h"
#include "TextComposite.h"

Text::Text(Long capacity)
{

}
Text::Text(const Text& source)
	:TextComposite(source) {

}

Text::~Text()
{

}

string Text::MakeString() {
	string text = "";
	Long i = 0;
	Character *character;

	while (i < this->length)
	{
		text += this->GetAt(i)->MakeString();

		i++;
	}
	return text;
}

Text& Text::operator=(const Text& source)
{
	this->characters = source.characters;
	this->capacity = source.capacity;
	this->length = source.length;

	return*this;
}

void Text::Accept(TextVisitor& textVisitor) {
	
	textVisitor.VisitText(this);
}
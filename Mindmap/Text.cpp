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

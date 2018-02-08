//Character.cpp

#include "Character.h"

Character::Character() {

}

Character::~Character() {

}

Long Character::Write(Character *character) {
	return -1;
}

Long Character::Insert(Long index, Character *character){
	return -1;
}

Long Character::Correct(Long index, Character *character) {
	return -1;
}

Character* Character::GetAt(Long index) {
	return 0;
}

string Character::MakeString() {
	return 0;
}

bool Character::IsEqual(const Character& other) {
	return 0;
}

bool Character::IsNotEqual(const Character& other) {
	return 0;
}

Long Character::GetRowWidth(CDC *cdc,Long index) {
	return -1;
}

Long Character::GetHeight(CDC *cdc, Long index) {
	return -1;
}

void Character::Accept(TextVisitor& textVisitor) {

}

char Character::GetCharacter() const {
	return 0;
}

string Character::GetCharacters() const {
	return 0;
}

Long Character::GetCapacity() const {
	return -1;
}

Long Character::GetLength() const {
	return -1;
}
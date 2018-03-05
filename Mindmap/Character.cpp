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

Long Character::Delete(Long index) {
	return -1;
}

Character* Character::GetAt(Long index) {
	return 0;
}

Character* Character::Clone() {
	return 0;
}

string Character::MakeString() {
	return 0;
}
string Character::MakeString(Long start, Long end) {
	return 0;
}

bool Character::IsEqual(const Character& other) {
	return 0;
}

bool Character::IsNotEqual(const Character& other) {
	return 0;
}

Long Character::GetRowWidth(CDC *cdc,Long start,Long end) {
	return -1;
}

Long Character::GetHeight(CDC *cdc, Long index) {
	return -1;
}

void Character::Accept(TextVisitor& textVisitor) {

}

bool Character::SetIsWordWrap(bool isWordWrap) {
	return 0;
}
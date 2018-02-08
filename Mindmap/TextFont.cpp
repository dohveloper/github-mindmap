//TextFont.cpp

#include "TextFont.h"


TextFont::TextFont() 
	:lpszFacename("") {
	this->height = 0;
	this->width = 0;
	this->weight = 0;
	this->italic = NULL;
	this->underline = NULL;
	this->strikeOut = NULL;
}

TextFont::TextFont(Long height, Long width, Long weight, BYTE italic, BYTE underline, BYTE strikeOut, CString lpszFacename)
	:lpszFacename(lpszFacename) {
	this->height = height;
	this->width = width;
	this->weight = weight;
	this->italic = italic;
	this->underline = underline;
	this->strikeOut = strikeOut;
}

TextFont::TextFont(const TextFont& source)
	:lpszFacename(source.lpszFacename) {
	this->height = source.height;
	this->width = source.width;
	this->weight = source.weight;
	this->italic = source.italic;
	this->underline = source.underline;
	this->strikeOut = source.strikeOut;
}

TextFont::~TextFont() {
}

void TextFont::SetHeight(Long height) {
	this->height = height;
}
void TextFont::SetWidth(Long width) {
	this->width = width;
}
void TextFont::SetWeight(Long weight) {
	this->weight = weight;
}
void TextFont::SetItalic(BYTE italic) {
	this->italic = italic;
}
void TextFont::SetUnderline(BYTE underline) {
	this->underline = underline;
}
void TextFont::SetStrikeOut(BYTE strikeOut) {
	this->strikeOut = strikeOut;
}
void TextFont::SetLpszFacename(CString lpszFacename) {
	this->lpszFacename = lpszFacename;
}
TextFont& TextFont::operator=(const TextFont& source) {
	this->height = source.height;
	this->width = source.width;
	this->weight = source.weight;
	this->italic = source.italic;
	this->underline = source.underline;
	this->strikeOut = source.strikeOut;
	this->lpszFacename = source.lpszFacename;

	return *this;
}
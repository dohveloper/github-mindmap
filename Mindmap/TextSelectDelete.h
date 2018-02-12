//TextSelectDelete.h
#ifndef _TEXTSELECTDELETE_H
#define _TEXTSELECTDELETE_H

typedef signed long int Long;

class TextForm;
class TextSelectDelete
{
public:
	TextSelectDelete();
	~TextSelectDelete();

	void TextSelectDeleteAction(TextForm *textForm, Long start, Long end);

};

#endif // _TEXTSELECTDELETE_H
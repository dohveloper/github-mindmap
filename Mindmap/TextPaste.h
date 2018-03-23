//textPaste.h

#ifndef TEXTPASTE_H
#define TEXTPASTE_H
#include "TextForm.h"

class TextForm;
class TextPaste
{
public:
	TextPaste();
	TextPaste(const TextPaste& source);
	~TextPaste();
	void Paste(TextForm *textForm);
	void CaretMove(TextForm *textForm);

	TextPaste& operator=(const TextPaste& source);

	

private:
	Long startTextRowLength;
	Long caretRowIndexSave;
	Long startCaretIndex;
	Long startPasteTextLength;
	bool isWrite;

};



#endif //TEXTPASTE_H

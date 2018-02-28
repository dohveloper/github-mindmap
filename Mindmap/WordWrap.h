//WordWrap.h

#ifndef _WORDWRAP_H
#define _WORDWRAP_H

#include "afxwin.h"

class TextForm;
class WordWrap {
public:
	WordWrap();
	~WordWrap();

	void Writing(TextForm *textForm,CDC *cdc);
	void Deleting(TextForm *textForm,CDC *cdc);
};

#endif //_WORDWRAP_H
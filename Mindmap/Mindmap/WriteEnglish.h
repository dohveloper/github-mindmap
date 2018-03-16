//WriteEnglish.h

#ifndef _WRITEENGLISH_H
#define _WRITEENGLISH_H

#include <afxwin.h>

class TextForm;
class WriteEnglish {
public:
	WriteEnglish();
	~WriteEnglish();

	void Write(TextForm *textForm,CDC *cdc,char word);
};

#endif //_WRITEENGLISH_H
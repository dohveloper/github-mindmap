//TextDrag.h

#ifndef _TEXTDRAG_H
#define _TEXTDRAG_H

#include "afxwin.h"

class TextForm;
class TextDrag {
public:
	TextDrag();
	~TextDrag();

	void SingleLineDrag(TextForm *textForm,CDC *cdc);
	void DoubleLineDrag(TextForm *textForm,CDC *cdc);
	void MultiLineDrag(TextForm *textForm, CDC *cdc);

};

#endif //_TEXTDRAG_H
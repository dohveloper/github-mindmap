//WriteKorean.h

#ifndef _WRITEKOREAN_H
#define _WRITEKOREAN_H

#include <afxwin.h>

class TextForm;
class WriteKorean {
public:
	WriteKorean();
	~WriteKorean();

	void KoreanMixing(TextForm *textForm, HIMC hIMC, HWND hWnd, CDC *cdc);
	void KoreanMixed(TextForm *textForm, HIMC hIMC, HWND hWnd);
};

#endif //WRITEKOREAN_H
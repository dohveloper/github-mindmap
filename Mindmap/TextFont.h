//TextFont.h

#ifndef _TEXTFONT_H
#define _TEXTFONT_H

#include <afxwin.h>

typedef signed long int Long;

class TextFont {
public:
	TextFont();
	TextFont(Long height, Long width, Long weight, BYTE italic, BYTE underline, BYTE strikeOut, CString lpszFacename);
	TextFont(const TextFont& source);
	~TextFont();

	void SetHeight(Long height);
	void SetWidth(Long width);
	void SetWeight(Long weight);
	void SetItalic(BYTE bItalic);
	void SetUnderline(BYTE underline);
	void SetStrikeOut(BYTE strikeOut);
	void SetLpszFacename(CString lpszFacename);

	TextFont& operator=(const TextFont& source);

	Long GetHeight() const;
	Long GetWidth() const;
	Long GetWeight() const;
	BYTE GetItalic() const;
	BYTE GetUnderline() const;
	BYTE GetStrikeOut() const;
	CString& GetLpszFacename() const;

private:
	//높이
	Long height;
	//넓이
	Long width;
	//굵기
	Long weight;
	//기울임
	BYTE italic;
	//밑줄
	BYTE underline;
	//취소선
	BYTE strikeOut;
	//폰트명
	CString lpszFacename;
};

inline Long TextFont::GetHeight() const {
	return this->height;
}
inline Long TextFont::GetWidth() const {
	return this->width;
}
inline Long TextFont::GetWeight() const {
	return this->weight;
}
inline BYTE TextFont::GetItalic() const {
	return this->italic;
}
inline BYTE TextFont::GetUnderline() const {
	return this->underline;
}
inline BYTE TextFont::GetStrikeOut() const {
	return this->strikeOut;
}
inline CString& TextFont::GetLpszFacename() const {
	return const_cast<CString&>(this->lpszFacename);
}
#endif //_TEXTFONT_H
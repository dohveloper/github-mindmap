//WriteKorean.h

#ifndef _WRITEKOREAN_H
#define _WRITEKOREAN_H

class TextForm;
class WriteKorean {
public:
	WriteKorean();
	~WriteKorean();

	void Compositing(TextForm *textForm);
	void Composited(TextForm *textForm);
};



#endif //WRITEKOREAN_H
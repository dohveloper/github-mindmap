#ifndef _CLIPBOARD_H
#define _CLIPBOARD_H
#include "Selection.h"

class Clipboard {
public:
	Clipboard(Long capacity = 256);
	Clipboard(const Clipboard& source);
	~Clipboard();

	void Copy(Selection *selection);
	void Paste(Selection *selection);
	//void Cut(Selection *selection);


	Clipboard& operator=(const Clipboard& source);

	Long GetCapacity() const;
	Long GetLength() const;

private:
	Array<Branch*> clipboard;
	Long capacity;
	Long length;

};

inline Long Clipboard::GetCapacity() const {
	return this->capacity;
}

inline Long Clipboard::GetLength() const {
	return this->length;
}

#endif //_Clipboard_H

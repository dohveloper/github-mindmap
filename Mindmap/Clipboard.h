#ifndef _CLIPBOARD_H
#define _CLIPBOARD_H
#include "BranchArray.h"

class Selection;
class Clipboard {
public:
	Clipboard(Selection *selection, Long capacity = 256);
	Clipboard(const Clipboard& source);
	~Clipboard();

	void Copy();
	void Paste();
	//void Cut(Selection *selection);

	Clipboard& operator=(const Clipboard& source);
	BranchArray GetClipboard() const;
private:
	BranchArray clipboard;
	Selection *selection;
};
inline BranchArray Clipboard::GetClipboard() const {
	return this->clipboard;
}
#endif //_Clipboard_H

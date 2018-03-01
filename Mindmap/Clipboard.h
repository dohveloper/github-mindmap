#ifndef _CLIPBOARD_H
#define _CLIPBOARD_H
#include "Selection.h"
#include "BranchArray.h"

class Clipboard {
public:
	Clipboard(Selection *selection, Long capacity = 256);
	Clipboard(const Clipboard& source);
	~Clipboard();

	void Copy();
	void Paste();
	//void Cut(Selection *selection);

	Clipboard& operator=(const Clipboard& source);

private:
	BranchArray clipboard;
	Selection *selection;
};

#endif //_Clipboard_H

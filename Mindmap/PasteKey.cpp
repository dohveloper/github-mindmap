#include "PasteKey.h"
#include "PageForm.h"
#include "Clipboard.h"

PasteKey::PasteKey()
{
}

PasteKey::~PasteKey()
{
}

void PasteKey::KeyPress(PageForm * pageForm)
{
	pageForm->clipboard.Paste();
}
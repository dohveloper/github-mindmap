#include "CopyKey.h"
#include "PageForm.h"
#include "Clipboard.h"

CopyKey::CopyKey()
{
}

CopyKey::~CopyKey()
{
}

void CopyKey::KeyPress(PageForm * pageForm)
{
	pageForm->clipboard.Copy();
}
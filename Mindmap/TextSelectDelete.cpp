//TextSelectDelete.h

#include "TextSelectDelete.h"
#include "TextForm.h"
#include "Text.h"
#include "Caret.h"

TextSelectDelete::TextSelectDelete()
{
}

TextSelectDelete::~TextSelectDelete()
{
}

void TextSelectDelete::TextSelectDeleteAction(TextForm *textForm, Long start, Long end)
{
	while (end - 1 < start)
	{
		textForm->text->GetAt(textForm->caret->GetCharacterIndex());
	}
}
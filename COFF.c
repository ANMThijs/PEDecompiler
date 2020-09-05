#include "COFF.h"

COFFHEADER CoffRead(FILE* file) {
	COFFHEADER head;

	fread_s(&head.Machine,			2, 2, 1, file);
	fread_s(&head.Sectioncount,		2, 2, 1, file);
	fread_s(&head.TimeDate,			4, 4, 1, file);
	fread_s(&head.Symboltableptr,	4, 4, 1, file);
	fread_s(&head.Symbolcount,		4, 4, 1, file);
	fread_s(&head.Optheadsize,		2, 2, 1, file);
	fread_s(&head.chars,			2, 2, 1, file);

	return head;
}
#include "Section.h"

SECTION SectionRead(FILE* file) {
	SECTION sect;

	fread_s(&sect.name, 8, 1, 8, file);
	fread_s(&sect.VirtSize, 4, 4, 1, file);
	fread_s(&sect.VirtAddr, 4, 4, 1, file);
	fread_s(&sect.RawDataSize, 4, 4, 1, file);
	fread_s(&sect.RawDataPtr, 4, 4, 1, file);
	fread_s(&sect.RelocPtr, 4, 4, 1, file);
	fread_s(&sect.LineNumPtr, 4, 4, 1, file);
	fread_s(&sect.RelocCount, 2, 2, 1, file);
	fread_s(&sect.LineNumCount, 2, 2, 1, file);
	fread_s(&sect.Chars, 4, 4, 1, file);

	return sect;
}
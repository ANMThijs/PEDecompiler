#include "Section.h"

SECTION SectionRead(FILE* file) {
	SECTION sect;

	fread_s(&sect.name, 8, 1, 8, file);
	sect.name[9] = '\0';

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

void SectionDump(FILE* file, SECTION* sect) {
	fseek(file, sect->RawDataPtr, 0L);

	char OutName[50] = { 0 };
	strcpy_s(OutName, strlen(sect->name) + 1, sect->name);
	strcpy_s(OutName + strlen(sect->name), strlen(".txt") + 1, ".txt");

	FILE* outputfile;
	fopen_s(&outputfile, OutName, "wb");
	if (outputfile != NULL) {
		for (int i = 0; i < sect->RawDataSize; i++) {
			uint8_t c = fgetc(file);
			fputc(c, outputfile);
		}
	}
	else {
		printf("Failed to open outputfile: %s\n", OutName);
	}
}
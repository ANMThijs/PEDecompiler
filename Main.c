#include <stdlib.h>
#include <string.h>

#include "Signature.h"
#include "COFF.h"
#include "OptHeader.h"
#include "Section.h"

int main(int argc, char** argv) {
	argc = 2;
	argv[1] = "test.exe";
	if (argc > 1) {
		FILE* file;
		fopen_s(&file, argv[1], "rb");

		if (file) {
			GetSign(file);

			COFFHEADER coff = CoffRead(file);
			OPTHEADER opt = OptHeadRead(file);
			OHWINSPEC opw = OHWHeadRead(file, opt.magic);
			OPTDATADIR odd = ODDHeadRead(file);

			SECTION* sects = malloc(coff.Sectioncount * sizeof(SECTION));
			long prevpos;
			if (sects) {
				for (int i = 0; i < coff.Sectioncount; i++) {
					sects[i] = SectionRead(file);

					prevpos = ftell(file);

					SectionDump(file, &sects[i]);

					fseek(file, prevpos, 0L);
				}
			}

			free(sects);
			fclose(file);
		}
		else {
			printf("Failed to find file: %s\n", argv[1]);
		}
	}
	else {
		printf("No input file detected\n");
	}
	return 0;
}
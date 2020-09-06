#include <stdlib.h>

#include "Signature.h"
#include "COFF.h"
#include "OptHeader.h"
#include "Section.h"

int main(int argc, char** argv) {
	FILE* file;
	fopen_s(&file, "test.exe", "rb");

	if (file != NULL) {
		GetSign(file);

		COFFHEADER coff = CoffRead(file);
		OPTHEADER opt = OptHeadRead(file);
		OHWINSPEC opw = OHWHeadRead(file, opt.magic);
		OPTDATADIR odd = ODDHeadRead(file);

		SECTION* sects = malloc(coff.Sectioncount * sizeof(SECTION));
		if (sects) {
			for (int i = 0; i < coff.Sectioncount; i++) {
				sects[i] = SectionRead(file);
				printf("%s\n", sects[i].name);
			}
		}

		free(sects);
		fclose(file);
	}

	return 0;
}
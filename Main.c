#include "Signature.h"
#include "COFF.h"
#include "OptHeader.h"

int main(int argc, char** argv) {
	FILE* file;
	fopen_s(&file, "test.exe", "rb");

	if (file != NULL) {
		GetSign(file);

		COFFHEADER coff = CoffRead(file);
		OPTHEADER opt = OptHeadRead(file);
		OHWINSPEC opw = OHWHeadRead(file, opt.magic);
		OPTDATADIR odd = ODDHeadRead(file);

		fclose(file);
	}

	return 0;
}
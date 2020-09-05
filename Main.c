#include "Signature.h"
#include "COFF.h"

int main(int argc, char** argv) {
	FILE* file;
	fopen_s(&file, "test.exe", "rb");

	if (file != NULL) {
		GetSign(file);

		COFFHEADER coff = CoffRead(file);

		fclose(file);
	}

	return 0;
}
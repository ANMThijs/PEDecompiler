#include "Signature.h"

void GetSign(FILE* file) {
	//Signature pointer is located at offset 0x3c
	fseek(file, 0x3c, 0L);

	int ret = 0;
	for (int i = 0; i < 4; i++) {
		unsigned char c = fgetc(file);

		int p = pow(16, (double)i + 1);
		ret += c * p;
	}

	fseek(file, ret, 0L);
}
#include "Signature.h"

void GetSign(FILE* file) {
	//Signature pointer is located at offset 0x3c
	fseek(file, 0x3c, 0L);

	int ret = 0;
	fread_s(&ret, 4, 4, 1, file);

	char sign[4];
	fseek(file, ret, 0L);
	for (int i = 0; i < 4; i++) {
		sign[i] = fgetc(file);
	}
}
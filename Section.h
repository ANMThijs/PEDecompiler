#pragma once
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct Section {
	char name[9];
	uint32_t VirtSize;
	uint32_t VirtAddr;
	uint32_t RawDataSize;
	uint32_t RawDataPtr;
	uint32_t RelocPtr;
	uint32_t LineNumPtr;
	uint16_t RelocCount;
	uint16_t LineNumCount;
	uint32_t Chars;
} SECTION;

SECTION SectionRead(FILE* file);

void SectionDump(FILE* file, SECTION* sect);
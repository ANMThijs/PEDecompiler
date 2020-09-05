#pragma once
#include <stdio.h>

typedef struct Coff_Header {
	unsigned short Machine;
	unsigned short Sectioncount;
	unsigned int TimeDate;
	unsigned int Symboltableptr;
	unsigned int Symbolcount;
	unsigned short Optheadsize;
	unsigned short chars;
} COFFHEADER;

//returns the location of the PE signature
COFFHEADER CoffRead(FILE* file);
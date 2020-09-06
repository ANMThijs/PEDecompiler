#pragma once
#include <stdio.h>
#include <stdint.h>

typedef struct Optional_Header {
	unsigned short magic;
	unsigned char Linkvermaj;
	unsigned char Linkvermin;
	unsigned int Codesize;
	unsigned int Initdatasize;
	unsigned int Uninitdatasize;
	unsigned int Entryaddr;
	unsigned int Codebase;

	//Is only there with PE32, not with PE32+
	unsigned int Database;
} OPTHEADER;

typedef struct OHW_32 {
	uint32_t ImageBase;

	uint32_t StackReserveSize;
	uint32_t StackCommitSize;

	uint32_t HeapReserveSize;
	uint32_t HeapCommitSize;
} OHW32;

typedef struct OHW_32plus {
	uint64_t ImageBase;

	uint64_t StackReserveSize;
	uint64_t StackCommitSize;

	uint64_t HeapReserveSize;
	uint64_t HeapCommitSize;
} OHW32PLUS;

typedef struct OH_Window_Specific {
	OHW32 settings;
	OHW32PLUS settingsplus;

	uint32_t SectAlign;
	uint32_t FileAlign;
	uint16_t OSvermaj;
	uint16_t OSvermin;
	uint16_t Imgvermaj;
	uint16_t Imgvermin;
	uint16_t Subsysvermaj;
	uint16_t Subsysvermin;
	uint32_t Win32VerVal;

	uint32_t ImgSize;
	uint32_t HeaderSize;
	uint32_t Checksum;
	uint16_t Subsys;
	uint16_t DLLChars;

	uint32_t LoadFlags;
	uint32_t RvaandSizecount;
} OHWINSPEC;

typedef struct OPT_data_dirs {
	uint64_t TableExport;
	uint64_t TableImport;
	uint64_t TableResource;
	uint64_t TableException;
	uint64_t TableCertificate;
	uint64_t TableBaseReloc;
	uint64_t Debug;
	uint64_t Arch;
	uint64_t GlobalPtr;
	uint64_t TableTLS;
	uint64_t TableLoadConfig;
	uint64_t ImportBound;
	uint64_t IAT;
	uint64_t ImportDelayDesc;
	uint64_t CLRRunheader;
	uint64_t Reserved;
} OPTDATADIR;

OPTHEADER OptHeadRead(FILE* file);

OHWINSPEC OHWHeadRead(FILE* file, uint16_t magic);

OPTDATADIR ODDHeadRead(FILE* file);
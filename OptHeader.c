#include "OptHeader.h"

OPTHEADER OptHeadRead(FILE* file) {
	OPTHEADER head;

	fread_s(&head.magic, 2, 2, 1, file);
	fread_s(&head.Linkvermaj, 1, 1, 1, file);
	fread_s(&head.Linkvermin, 1, 1, 1, file);
	fread_s(&head.Codesize, 4, 4, 1, file);
	fread_s(&head.Initdatasize, 4, 4, 1, file);
	fread_s(&head.Uninitdatasize, 4, 4, 1, file);
	fread_s(&head.Entryaddr, 4, 4, 1, file);
	fread_s(&head.Codebase, 4, 4, 1, file);

	if (head.magic == 0x10b) {
		fread_s(&head.Database, 4, 4, 1, file);
	}

	return head;
}

OHWINSPEC OHWHeadRead(FILE* file, uint16_t magic) {
	OHWINSPEC head;

	if (magic == 0x10b) {
		fread_s(&head.settings.ImageBase, 4, 4, 1, file);
	}
	else if (magic == 0x20b) {
		fread_s(&head.settingsplus.ImageBase, 8, 8, 1, file);
	}

	fread_s(&head.SectAlign, 4, 4, 1, file);
	fread_s(&head.FileAlign, 4, 4, 1, file);
	fread_s(&head.OSvermaj, 2, 2, 1, file);
	fread_s(&head.OSvermin, 2, 2, 1, file);
	fread_s(&head.Imgvermaj, 2, 2, 1, file);
	fread_s(&head.Imgvermin, 2, 2, 1, file);
	fread_s(&head.Subsysvermaj, 2, 2, 1, file);
	fread_s(&head.Subsysvermin, 2, 2, 1, file);
	fread_s(&head.Win32VerVal, 4, 4, 1, file);

	fread_s(&head.ImgSize, 4, 4, 1, file);
	fread_s(&head.HeaderSize, 4, 4, 1, file);
	fread_s(&head.Checksum, 4, 4, 1, file);
	fread_s(&head.Subsys, 2, 2, 1, file);
	fread_s(&head.DLLChars, 2, 2, 1, file);

	if (magic == 0x10b) {
		fread_s(&head.settings.StackReserveSize, 4, 4, 1, file);
		fread_s(&head.settings.StackCommitSize, 4, 4, 1, file);
		fread_s(&head.settings.HeapReserveSize, 4, 4, 1, file);
		fread_s(&head.settings.HeapCommitSize, 4, 4, 1, file);
	}
	else if (magic == 0x20b) {
		fread_s(&head.settingsplus.StackReserveSize, 8, 8, 1, file);
		fread_s(&head.settingsplus.StackCommitSize, 8, 8, 1, file);
		fread_s(&head.settingsplus.HeapReserveSize, 8, 8, 1, file);
		fread_s(&head.settingsplus.HeapCommitSize, 8, 8, 1, file);
	}

	fread_s(&head.LoadFlags, 4, 4, 1, file);
	fread_s(&head.RvaandSizecount, 4, 4, 1, file);

	return head;
}

OPTDATADIR ODDHeadRead(FILE* file) {
	OPTDATADIR data;

	fread_s(&data.TableExport, 8, 8, 1, file);
	fread_s(&data.TableImport, 8, 8, 1, file);
	fread_s(&data.TableResource, 8, 8, 1, file);
	fread_s(&data.TableException, 8, 8, 1, file);
	fread_s(&data.TableCertificate, 8, 8, 1, file);
	fread_s(&data.TableBaseReloc, 8, 8, 1, file);
	fread_s(&data.Debug, 8, 8, 1, file);
	fread_s(&data.Arch, 8, 8, 1, file);
	fread_s(&data.GlobalPtr, 8, 8, 1, file);
	fread_s(&data.TableTLS, 8, 8, 1, file);
	fread_s(&data.TableLoadConfig, 8, 8, 1, file);
	fread_s(&data.ImportBound, 8, 8, 1, file);
	fread_s(&data.IAT, 8, 8, 1, file);
	fread_s(&data.ImportDelayDesc, 8, 8, 1, file);
	fread_s(&data.CLRRunheader, 8, 8, 1, file);
	fread_s(&data.Reserved, 8, 8, 1, file);

	return data;
}
#ifndef EFI_TABLEHEADER_H
#define EFI_TABLEHEADER_H

#include <EFI/Types.h>

typedef struct {
    UINT64 Signature;
    UINT32 Revision;
    UINT32 HeaderSize;
    UINT32 CRC32;
    UINT32 Reserved;
} EFI_TABLE_HEADER;

#endif // EFI_TABLEHEADER_H
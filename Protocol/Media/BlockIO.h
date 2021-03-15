#ifndef EFI_PROTOCOL_MEDIA_BLOCKIO_H
#define EFI_PROTOCOL_MEDIA_BLOCKIO_H

#include <EFI/Types.h>

#define EFI_BLOCK_IO_PROTOCOL_GUID \
    { 0x964E5B21, 0x6459, 0x11D2, { 0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B } }

#define EFI_BLOCK_IO_PROTOCOL_REVISION2     (0x00020001)
#define EFI_BLOCK_IO_PROTOCOL_REVISION3     ((2 << 16) | (31))

typedef struct _EFI_BLOCK_IO_PROTOCOL EFI_BLOCK_IO_PROTOCOL;

//
// EFI_BLOCK_IO_MEDIA
//
typedef struct {
    UINT32      MediaId;
    BOOLEAN     RemovableMedia;
    BOOLEAN     MediaPresent;
    BOOLEAN     LogicalPartition;
    BOOLEAN     ReadOnly;
    BOOLEAN     WriteCaching;
    UINT32      BlockSize;
    UINT32      IoAlign;
    EFI_LBA     LastBlock;
    EFI_LBA     LowestAlignedLba;                   // added in Revision 2
    UINT32      LogicalBlocksPerPhysicalBlock;      // added in Revision 2
    UINT32      OptimalTransferLengthGranularity;   // added in Revision 3
} EFI_BLOCK_IO_MEDIA;

typedef
EFI_STATUS
(EFIAPI *EFI_BLOCK_RESET) (
    IN EFI_BLOCK_IO_PROTOCOL    *This,
    IN BOOLEAN                  ExtendedVerification
);

typedef
EFI_STATUS
(EFIAPI *EFI_BLOCK_READ) (
    IN EFI_BLOCK_IO_PROTOCOL    *This,
    IN UINT32                   MediaId,
    IN EFI_LBA                  LBA,
    IN UINTN                    BufferSize,
    OUT VOID                    *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_BLOCK_WRITE) (
    IN EFI_BLOCK_IO_PROTOCOL    *This,
    IN UINT32                   MediaId,
    IN EFI_LBA                  LBA,
    IN UINTN                    BufferSize,
    IN VOID                     *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_BLOCK_FLUSH) (
    IN EFI_BLOCK_IO_PROTOCOL    *This
);

struct _EFI_BLOCK_IO_PROTOCOL {
    UINT64                  Revision;
    EFI_BLOCK_IO_MEDIA      *Media;
    EFI_BLOCK_RESET         Reset;
    EFI_BLOCK_READ          ReadBlocks;
    EFI_BLOCK_WRITE         WriteBlocks;
    EFI_BLOCK_FLUSH         FlushBlocks;
};

#endif // EFI_PROTOCOL_MEDIA_BLOCKIO_H
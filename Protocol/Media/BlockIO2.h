#ifndef EFI_PROTOCOL_MEDIA_BLOCKIO2_H
#define EFI_PROTOCOL_MEDIA_BLOCKIO2_H

#include <EFI/Types.h>

#define EFI_BLOCK_IO2_PROTOCOL_GUID \
    { 0xA77B2472, 0xE282, 0x4E9F, { 0xA2, 0x45, 0xC2, 0xC0, 0xE2, 0x7B, 0xBC, 0xC1 } }

typedef struct _EFI_BLOCK_IO2_PROTOCOL EFI_BLOCK_IO2_PROTOCOL;

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

//
// EFI_BLOCK_IO2_TOKEN
//
typedef struct {
    EFI_EVENT       Event;
    EFI_STATUS      TransactionStatus;
} EFI_BLOCK_IO2_TOKEN;


typedef
EFI_STATUS
(EFIAPI *EFI_BLOCK_RESET_EX) (
    IN EFI_BLOCK_IO2_PROTOCOL   *This,
    IN BOOLEAN                  ExtendedVerification
);

typedef
EFI_STATUS
(EFIAPI *EFI_BLOCK_READ_EX) (
    IN EFI_BLOCK_IO2_PROTOCOL   *This,
    IN UINT32                   MediaId,
    IN EFI_LBA                  LBA,
    IN OUT EFI_BLOCK_IO2_TOKEN  *Token,
    IN UINTN                    BufferSize,
    OUT VOID                    *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_BLOCK_WRITE_EX) (
    IN EFI_BLOCK_IO2_PROTOCOL   *This,
    IN UINT32                   MediaId,
    IN EFI_LBA                  LBA,
    IN OUT EFI_BLOCK_IO2_TOKEN  *Token,
    IN UINTN                    BufferSize,
    IN VOID                     *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_BLOCK_FLUSH_EX) (
    IN EFI_BLOCK_IO2_PROTOCOL   *This,
    IN OUT EFI_BLOCK_IO2_TOKEN  *Token
);

struct _EFI_BLOCK_IO2_PROTOCOL {
    EFI_BLOCK_IO_MEDIA      *Media;
    EFI_BLOCK_RESET_EX      Reset;
    EFI_BLOCK_READ_EX       ReadBlocksEx;
    EFI_BLOCK_WRITE_EX      WriteBlocksEx;
    EFI_BLOCK_FLUSH_EX      FlushBlocksEx;
};

#endif // EFI_PROTOCOL_MEDIA_BLOCKIO2_H
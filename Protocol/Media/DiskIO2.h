#ifndef EFI_PROTOCOL_MEDIA_DISKIO2_H
#define EFI_PROTOCOL_MEDIA_DISKIO2_H

#include <EFI/Types.h>

#define EFI_DISK_IO2_PROTOCOL_GUID \
    { 0x151C8EAE, 0x7F2C, 0x472C, { 0x9E, 0x54, 0x98, 0x28, 0x19, 0x4F, 0x6A, 0x88 } }

#define EFI_DISK_IO2_PROTOCOL_REVISION  (0x00020000)

typedef struct _EFI_DISK_IO2_PROTOCOL EFI_DISK_IO2_PROTOCOL;

//
// EIF_DISK_IO2_TOKEN
//
typedef struct {
    EFI_EVENT   Event;
    EFI_STATUS  TransactionStatus;
} EFI_DISK_IO2_TOKEN;

typedef
EFI_STATUS
(EFIAPI *EFI_DISK_CANCEL_EX) (
    IN EFI_DISK_IO2_PROTOCOL    *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_DISK_READ_EX) (
    IN EFI_DISK_IO2_PROTOCOL    *This,
    IN UINT32                   MediaId,
    IN UINT64                   Offset,
    IN OUT EFI_DISK_IO2_TOKEN   *Token,
    IN UINTN                    BufferSize,
    OUT VOID                    *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_DISK_WRITE_EX) (
    IN EFI_DISK_IO2_PROTOCOL    *This,
    IN UINT32                   MediaId,
    IN UINT64                   Offset,
    IN OUT EFI_DISK_IO2_TOKEN   *Token,
    IN UINTN                    BufferSize,
    IN VOID                     *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_DISK_FLUSH_EX) (
    IN EFI_DISK_IO2_PROTOCOL    *This,
    IN OUT EFI_DISK_IO2_TOKEN   *Token
);

struct _EFI_DISK_IO2_PROTOCOL {
    UINT64              Revision;
    EFI_DISK_CANCEL_EX  Cancel;
    EFI_DISK_READ_EX    ReadDiskEx;
    EFI_DISK_WRITE_EX   WriteDiskEx;
    EFI_DISK_FLUSH_EX   FlushDiskEx;
};

#endif // EFI_PROTOCOL_MEDIA_DISKIO2_H
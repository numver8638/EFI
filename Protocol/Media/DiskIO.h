#ifndef EFI_PROTOCL_MEDIA_DISKIO_H
#define EFI_PROTOCL_MEDIA_DISKIO_H

#include <EFI/Types.h>

#define EFI_DISK_IO_PROTOCOL_GUID \
    { 0xCE345171, 0xBA0B, 0x11D2, { 0x8E, 0x4F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B } }

#define EFI_DISK_IO_PROTOCOL_REVISION (0x00010000)

typedef struct _EFI_DISK_IO_PROTOCOL EFI_DISK_IO_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_DISK_READ) (
    IN EFI_DISK_IO_PROTOCOL     *This,
    IN UINT32                   MediaId,
    IN UINT64                   Offset,
    IN UINTN                    BufferSize,
    OUT VOID                    *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_DISK_WRITE) (
    IN EFI_DISK_IO_PROTOCOL     *This,
    IN UINT32                   MediaId,
    IN UINT64                   Offset,
    IN UINTN                    BufferSize,
    IN VOID                     *Buffer
);

struct _EFI_DISK_IO_PROTOCOL {
    UINT64          Revision;
    EFI_DISK_READ   ReadDisk;
    EFI_DISK_WRITE  WriteDisk;
};

#endif // EFI_PROTOCL_MEDIA_DISKIO_H
#ifndef EFI_PROTOCOL_MEDIA_LOADFILE_H
#define EFI_PROTOCOL_MEDIA_LOADFILE_H

#include <EFI/Types.h>
#include <EFI/Protocol/Path/DevicePath.h>

#define EFI_LOAD_FILE_PROTOCOL_GUID \
    { 0x56EC3091, 0x954C, 0x11D2, { 0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B } }

typedef struct _EFI_LOAD_FILE_PROTOCOL EFI_LOAD_FILE_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_LOAD_FILE) (
    IN EFI_LOAD_FILE_PROTOCOL       *This,
    IN EFI_DEVICE_PATH_PROTOCOL     *FilePath,
    IN BOOLEAN                      BootPolicy,
    IN OUT UINTN                    *BufferSize,
    IN VOID                         *Buffer OPTIONAL
);

struct _EFI_LOAD_FILE_PROTOCOL {
    EFI_LOAD_FILE       LoadFile;
};

#endif // EFI_PROTOCOL_MEDIA_LOADFILE_H
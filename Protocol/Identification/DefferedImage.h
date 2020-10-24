#ifndef EFI_PROTOCOL_IDENTIFICATION_DEFFEREDIMAGE_H
#define EFI_PROTOCOL_IDENTIFICATION_DEFFEREDIMAGE_H

#include <EFI/Types.h>
#include <EFI/Protocol/Path/DevicePath.h>

#define EFI_DEFFERED_IMAGE_LOAD_PROTOCOL_GUID \
    { 0x15853D7C, 0x3DDF, 0x43E0, { 0xA1, 0xCB, 0xEB, 0xF8, 0x5B, 0x8F, 0x87, 0x2C } }

typedef struct _EFI_DEFFERED_IMAGE_LOAD_PROTOCOL EFI_DEFFERED_IMAGE_LOAD_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_DEFFERED_IMAGE_INFO) (
    IN EFI_DEFFERED_IMAGE_LOAD_PROTOCOL     *This,
    IN UINTN                                ImageIndex,
    OUT EFI_DEVICE_PATH_PROTOCOL            **ImageDevicePath,
    OUT VOID                                **Image,
    OUT UINTN                               *ImageSize,
    OUT BOOLEAN                             *BootOption
);

struct _EFI_DEFFERED_IMAGE_LOAD_PROTOCOL {
    EFI_DEFFERED_IMAGE_INFO     GetImageInfo;
};

#endif // EFI_PROTOCOL_IDENTIFICATION_DEFFEREDIMAGE_H
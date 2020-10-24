#ifndef EFI_PROTOCOL_PATH_DEVICEPATHFROMTEXT_H
#define EFI_PROTOCOL_PATH_DEVICEPATHFROMTEXT_H

#include <EFI/Types.h>
#include <EFI/Protocol/Path/DevicePath.h>

#define EFI_DEVICE_PATH_FROM_TEXT_PROTOCOL_GUID \
    { 0x5C99A21, 0xC70F, 0x4AD2, { 0x8A, 0x5F, 0x35, 0xDF, 0x33, 0x43, 0xF5, 0x1E } }

typedef struct _EFI_DEVICE_PATH_FROM_TEXT_PROTOCOL {
    EFI_DEVICE_PATH_PROTOCOL* (EFIAPI *ConvertTextToDeviceNode)(IN CONST CHAR16*);
    EFI_DEVICE_PATH_PROTOCOL* (EFIAPI *COnvertTextToDevicePath)(IN CONST CHAR16*);
} EFI_DEVICE_PATH_FROM_TEXT_PROTOCOL;

#endif // EFI_PROTOCOL_PATH_DEVICEPATHFROMTEXT_H
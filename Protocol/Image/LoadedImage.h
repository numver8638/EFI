#ifndef EFI_PROTOCOL_IMAGE_LOADEDIMAGE_H
#define EFI_PROTOCOL_IMAGE_LOADEDIMAGE_H

#include <EFI/Types.h>
#include <EFI/SystemTable.h>
#include <EFI/Protocol/Path/DevicePath.h>

#define EFI_LOADED_IMAGE_PROTOCOL_GUID \
    { 0x5B1B31A1, 0x9562, 0x11D2, { 0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B } }

#define EFI_LOADED_IMAGE_DEVICE_PATH_PROTOCOL_GUID \
    { 0xBC62157E, 0x3E33, 0x3FEC, { 0x99, 0x20, 0x2D, 0x3B, 0x36, 0xD7, 0x50, 0xDF } }

#define EFI_LOADED_IMAGE_PROTOCOL_REVISION  ((UINT32)0x1000)

typedef struct {
    UINT32 Revision;
    EFI_HANDLE ParentHandle;
    EFI_SYSTEM_TABLE* SystemTable;

    // Source location of the image
    EFI_HANDLE DeviceHandle;
    EFI_DEVICE_PATH_PROTOCOL* FilePath;
    VOID* Reserved;

    // Image's load options
    UINT32 LoadOptionsSize;
    VOID* LoadOptions;

    // Location where image was loaded
    VOID* ImageBase;
    UINT64 ImageSize;
    EFI_MEMORY_TYPE ImageCodeType;
    EFI_MEMORY_TYPE ImageDataType;
    EFI_STATUS (EFIAPI *Unload)(IN EFI_HANDLE);
} EFI_LOADED_IMAGE_PROTOCOL;

#endif // EFI_PROTOCOL_IMAGE_LOADEDIMAGE_H
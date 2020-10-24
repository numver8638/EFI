#ifndef EFI_PROTOCOL_DEBUG_DEBUGSUPPORTTABLE_H
#define EFI_PROTOCOL_DEBUG_DEBUGSUPPORTTABLE_H

#include <EFI/Types.h>
#include <EFI/Protocol/Image/LoadedImage.h>

#define EFI_DEBUG_IMAGE_INFO_TABLE_GUID \
    { 0x49152E77, 0x1ADA, 0x4764, { 0xB7, 0xA2, 0x7A, 0xFE, 0xFE, 0xD9, 0x5E, 0x8B } }

typedef struct _EFI_SYSTEM_TABLE_POINTER {
    UINT64                  Signature;
    EFI_PHYSICAL_ADDRESS    EfiSystemTableBase;
    UINT32                  Crc32;
} EFI_SYSTEM_TABLE_POINTER;

//
// UpdateStatus bits
//
#define EFI_DEBUG_IMAGE_INFO_UPDATE_IN_PROGRESS (0x01)
#define EFI_DEBUG_IMAGE_INFO_TABLE_MODIFIED     (0x02)

#define EFI_DEBUG_IMAGE_INFO_TYPE_NORMAL        (0x01)

typedef struct {
    UINT32                      ImaegInfoType;
    EFI_LOADED_IMAGE_PROTOCOL   *LoadedImageProtocolInstance;
    EFI_HANDLE                  ImageHandle;
} EFI_DEBUG_IMAGE_INFO_NORMAL;

typedef union {
    UINT32                      *ImageInfoType;
    EFI_DEBUG_IMAGE_INFO_NORMAL *NormalImage;
} EFI_DEBUG_IMAGE_INFO;

typedef struct {
    volatile UINT32         UpdateStatus;
    UINT32                  TableSize;
    EFI_DEBUG_IMAGE_INFO    *EfiDebugImageInfoTable;
} EFI_DEBUG_IMAGE_INFO_TABLE_HEADER;

#endif // EFI_PROTOCOL_DEBUG_DEBUGSUPPORTTABLE_H
#ifndef EFI_PROTOCOL_HII_PACKAGE_DEVICEPATH_H
#define EFI_PROTOCOL_HII_PACKAGE_DEVICEPATH_H

#include <EFI/Protocol/HII/Types.h>
#include <EFI/Protocol/Path/DevicePath.h>

//
// EFI_HII_DEVICE_PATH_PACKAGE
//
typedef struct {
    EFI_HII_PACKAGE_HDR             Header;
    // EFI_DEVICE_PATH_PROTOCOL     DevicePath[];
} EFI_HII_DEVICE_PATH_PACKAGE;

#endif // EFI_PROTOCOL_HII_PACKAGE_DEVICEPATH_H
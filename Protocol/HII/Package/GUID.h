#ifndef EFI_PROTOCOL_HII_PACKAGE_GUID_H
#define EFI_PROTOCOL_HII_PACKAGE_GUID_H

#include <EFI/Protocol/HII/Types.h>

//
// EFI_HII_GUID_PACKAGE_HDR
//
typedef struct {
    EFI_HII_PACKAGE_HDR     Header;
    EFI_GUID                Guid;
    // Data per GUID definition may follow
} EFI_HII_GUID_PACKAGE_HDR;

#endif // EFI_PROTOCOL_HII_PACKAGE_GUID_H
#ifndef EFI_PROTOCOL_DRIVER_FAMILYOVERRIDE_H
#define EFI_PROTOCOL_DRIVER_FAMILYOVERRIDE_H

#include <EFI/Types.h>

#define EFI_DRIVER_FAMILY_OVERRIDE_PROTOCOL_GUID \
    { 0xB1EE129E, 0xDA36, 0x4181, { 0x91, 0xF8, 0x04, 0xA4, 0x92, 0x37, 0x66, 0xA7 } }

typedef struct _EFI_DRIVER_FAMILY_OVERRIDE_PROTOCOL EFI_DRIVER_FAMILY_OVERRIDE_PROTOCOL;

typedef
UINT32
(EFIAPI *EFI_DRIVER_FAMILY_OVERRIDE_GET_VERSION) (
    IN EFI_DRIVER_FAMILY_OVERRIDE_PROTOCOL *This
);

struct _EFI_DRIVER_FAMILY_OVERRIDE_PROTOCOL {
    EFI_DRIVER_FAMILY_OVERRIDE_GET_VERSION GetVersion;
};

#endif // EFI_PROTOCOL_DRIVER_FAMILYOVERRIDE_H
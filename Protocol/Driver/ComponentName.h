#ifndef EFI_PROTOCOL_DRIVER_COMPONENTNAME_H
#define EFI_PROTOCOL_DRIVER_COMPONENTNAME_H

#include <EFI/Types.h>

#define EFI_COMPONENT_NAME2_PROTOCOL_GUID \
    { 0x6A7A5CFF, 0xE8D9, 0x4F70, { 0xBA, 0xDA, 0x75, 0xAB, 0x30, 0x25, 0xCE, 0x14 } }

typedef struct _EFI_COMPONENT_NAME2_PROTOCOL EFI_COMPONENT_NAME2_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_COMPONENT_NAME_GET_DRIVER_NAME) (
    IN EFI_COMPONENT_NAME2_PROTOCOL *This,
    IN CHAR8                        *Language,
    OUT CHAR16                      **DriverName
);

typedef
EFI_STATUS
(EFIAPI *EFI_COMPONENT_NAME_GET_CONTROLLER_NAME) (
    IN EFI_COMPONENT_NAME2_PROTOCOL *This,
    IN EFI_HANDLE                   ControllerHandle,
    IN EFI_HANDLE                   ChildHandle OPTIONAL,
    IN CHAR8                        *Language,
    OUT CHAR16                      **ControllerName
);

struct _EFI_COMPONENT_NAME2_PROTOCOL {
    EFI_COMPONENT_NAME_GET_DRIVER_NAME     GetDriverName;
    EFI_COMPONENT_NAME_GET_CONTROLLER_NAME GetControllerName;
    CHAR8*                                 SupportedLanguages;
};

#endif // EFI_PROTOCOL_DRIVER_COMPONENTNAME_H
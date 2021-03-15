#ifndef EFI_PROTOCOL_DRIVER_DRIVERCONFIGURATION_H
#define EFI_PROTOCOL_DRIVER_DRIVERCONFIGURATION_H

#include <EFI/Types.h>

#define EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL_GUID \
    { 0x642CD590, 0x8059, 0x4C0A, { 0xA9, 0x58, 0xC5, 0xEC, 0x07, 0xD2, 0x3C, 0x4B } }

#define EFI_PLATFORM_TO_DRIVER_CONFIGURATION_CLP_GUID \
    { 0x345ECC0E, 0xCB6, 0x4B75, { 0xBB, 0x57, 0x1B, 0x12, 0x9C, 0x47, 0x33, 0x3E } }

typedef struct _EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL;

typedef struct {
    CHAR8* CLPCommand;
    UINT32 CLPCommandLength;
    CHAR8* CLPReturnString;
    UINT32 CLPReturnStringLength;
    UINT8 CLPCmdStatus;
    UINT8 CLPErrorValue;
    UINT16 CLPMsgCode;
} EFI_CONFIGURATION_CLP_PARAMETER_BLK;

typedef enum {
    EfiPlatformConfigurationActionNone = 0,
    EfiPlatformConfigurationActionStopController = 1,
    EfiPlatformConfigurationActionRestartController = 2,
    EfiPlatformConfigurationActionRestartPlatform = 3,
    EfiPlatformConfigurationActionNvramFailed = 4,
    EfiPlatformConfigurationActionMaximum
} EFI_PLATFORM_CONFIGURATION_ACTION;

typedef
EFI_STATUS
(EFIAPI *EFI_PLATFORM_TO_DRIVER_CONFIGURATION_QUERY) (
    IN EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL *This,
    IN EFI_HANDLE                                    ControllerHandle,
    IN EFI_HANDLE                                    ChildHandle OPTIONAL,
    IN UINTN                                         *Instance,
    OUT EFI_GUID                                     **ParameterTypeGuid,
    OUT VOID                                         **ParameterBlock,
    OUT UINTN                                        *ParameterBlockSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_PLATFORM_TO_DRIVER_CONFIGURATION_RESPONSE) (
    IN EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL *This,
    IN EFI_HANDLE                                    ControllerHandle,
    IN EFI_HANDLE                                    ChildHandle OPTIONAL,
    IN UINTN                                         *Instance,
    IN EFI_GUID                                      *ParameterTypeGuid,
    IN VOID                                          *ParameterBlock,
    IN UINTN                                         ParameterBlockSize,
    IN EFI_PLATFORM_CONFIGURATION_ACTION             ConfigurationAction
);


struct _EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL {
EFI_PLATFORM_TO_DRIVER_CONFIGURATION_QUERY    Query;
EFI_PLATFORM_TO_DRIVER_CONFIGURATION_RESPONSE Response;
};

#endif // EFI_PROTOCOL_DRIVER_DRIVERCONFIGURATION_H
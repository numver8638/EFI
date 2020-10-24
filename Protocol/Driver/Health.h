#ifndef EFI_PROTOCOL_DRIVER_HEALTH_H
#define EFI_PROTOCOL_DRIVER_HEALTH_H

#include <EFI/Types.h>
#include <EFI/Protocol/HII/Types.h>

#define EFI_DRIVER_HEALTH_PROTOCOL_GUID \
    { 0x2A534210, 0x9280, 0x41D8, { 0xAE, 0x79, 0xCA, 0xDA, 0x01, 0xA2, 0xB1, 0x27 } }

typedef struct _EFI_DRIVER_HEALTH_PROTOCOL EFI_DRIVER_HEALTH_PROTOCOL;

typedef enum {
    EfiDriverHealthStatusHealthy,
    EfiDriverHealthStatusRepairRequired,
    EfiDriverHealthStatusConfigurationRequired,
    EfiDriverHealthStatusFailed,
    EfiDriverHealthStatusReconnectRequired,
    EfiDriverHealthStatusRebootRequired
} EFI_DRIVER_HEALTH_STATUS;

typedef struct {
    EFI_HII_HANDLE HiiHandle;
    EFI_STRING_ID StringId;
    UINT64 MessageCode;
} EFI_DRIVER_HEALTH_HII_MESSAGE;

typedef EFI_STATUS (EFIAPI *EFI_DRIVER_HEALTH_REPAIR_NOTIFY)(IN UINTN, IN UINTN);

typedef
EFI_STATUS
(EFIAPI *EFI_DRIVER_HEALTH_GET_HEALTH_STATUS) (
    IN EFI_DRIVER_HEALTH_PROTOCOL     *This,
    IN EFI_HANDLE                     ControllerHandle OPTIONAL,
    IN EFI_HANDLE                     ChildHandle OPTIONAL,
    OUT EFI_DRIVER_HEALTH_STATUS      *HealthStatus,
    OUT EFI_DRIVER_HEALTH_HII_MESSAGE **MessageList OPTIONAL,
    OUT EFI_HII_HANDLE                *FormHiiHandle OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_DRIVER_HEALTH_REPAIR) (
    IN EFI_DRIVER_HEALTH_PROTOCOL      *This,
    IN EFI_HANDLE                      ControllerHandle,
    IN EFI_HANDLE                      ChildHandle OPTIONAL,
    IN EFI_DRIVER_HEALTH_REPAIR_NOTIFY RepairNotify OPTIONAL
);


struct _EFI_DRIVER_HEALTH_PROTOCOL {
    EFI_DRIVER_HEALTH_GET_HEALTH_STATUS GetHealthStatus;
    EFI_DRIVER_HEALTH_REPAIR            Repair;
};

#endif // EFI_PROTOCOL_DRIVER_HEALTH_H
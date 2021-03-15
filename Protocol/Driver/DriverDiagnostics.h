#ifndef EFI_PROTOCOL_DRIVER_DRIVERDIAGNOSTICS_H
#define EFI_PROTOCOL_DRIVER_DRIVERDIAGNOSTICS_H

#include <EFI/Types.h>

#define EFI_DRIVER_DIAGNOSTICS_PROTOCOL_GUID \
    { 0x4D330321, 0x025F, 0x4AAC, { 0x90, 0xD8, 0x5E, 0xD9, 0x00, 0x17, 0x3B, 0x63 } }

typedef enum {
    EfiDriverDiagnosticTypeStandard = 0,
    EfiDriverDiagnosticTypeExtended = 1,
    EfiDriverDiagnosticTypeManufacturing = 2,
    EfiDriverDiagnosticTypeCancel = 3,
    EfiDriverDiagnosticTypeMaximum
} EFI_DRIVER_DIAGNOSTIC_TYPE;

typedef struct _EFI_DRIVER_DIAGNOSTICS2_PROTOCOL EFI_DRIVER_DIAGNOSTICS2_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_DRIVER_DIAGNOSTICS2_RUN_DIAGNOSTICS) (
    IN EFI_DRIVER_DIAGNOSTICS2_PROTOCOL *This,
    IN EFI_HANDLE                       ControllerHandle,
    IN EFI_HANDLE                       ChildHandle OPTIONAL,
    IN EFI_DRIVER_DIAGNOSTIC_TYPE       DiagnosticType,
    IN CHAR8                            *Language,
    OUT EFI_GUID                        **ErrorType,
    OUT UINTN                           *BufferSize,
    OUT CHAR16                          **Buffer
);

struct _EFI_DRIVER_DIAGNOSTICS2_PROTOCOL {
    EFI_DRIVER_DIAGNOSTICS2_RUN_DIAGNOSTICS RunDiagnostics;
    CHAR8*                                  SupportedLanguages;
};

#endif // EFI_PROTOCOL_DRIVER_DRIVERDIAGNOSTICS_H
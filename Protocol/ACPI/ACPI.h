#ifndef EFI_PROTOCOL_ACPI_ACPI_H
#define EFI_PROTOCOL_ACPI_ACPI_H

#include <EFI/Types.h>

#define EFI_ACPI_TABLE_PROTOCOL_GUID \
    { 0xFFE06BDD, 0x6107, 0x46A6, { 0x7B, 0xB2, 0x5A, 0x9C, 0x7E, 0xC5, 0x27, 0x5C } }

typedef struct _EFI_ACPI_TABLE_PROTOCOL EFI_ACPI_TABLE_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_ACPI_TABLE_INSTALL_ACPI_TABLE) (
    IN EFI_ACPI_TABLE_PROTOCOL  *This,
    IN VOID                     *AcpiTableBuffer,
    IN UINTN                    AcpiTableBufferSize,
    OUT UINTN                   *TableKey
);

typedef
EFI_STATUS
(EFIAPI *EFI_ACPI_TABLE_UNINSTALL_ACPI_TABLE) (
    IN EFI_ACPI_TABLE_PROTOCOL  *This,
    IN UINTN                    TableKey
);

struct _EFI_ACPI_TABLE_PROTOCOL {
    EFI_ACPI_TABLE_INSTALL_ACPI_TABLE       InstallAcpiTable;
    EFI_ACPI_TABLE_UNINSTALL_ACPI_TABLE     UninstallAcpiTable;
};

#endif // EFI_PROTOCOL_ACPI_ACPI_H
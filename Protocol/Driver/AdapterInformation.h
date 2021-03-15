#ifndef EFI_PROTOCOL_DRIVER_ADAPTERINFORMATION_H
#define EFI_PROTOCOL_DRIVER_ADAPTERINFORMATION_H

#include <EFI/Types.h>

#define EFI_ADAPTER_INFORMATION_PROTOCOL_GUID \
    { 0xE5DD1403, 0xD622, 0xC24E, { 0x84, 0x88, 0xC7, 0x1B, 0x17, 0xF5, 0xE8, 0x02 } }

#define EFI_ADAPTER_INFO_MEDIA_STATE_GUID \
    { 0xD7C74207, 0xA831, 0x4A26 { 0xB1, 0xF5, 0xD1, 0x93, 0x06, 0x5C, 0xE8, 0xB6 } }

#define EFI_ADAPTER_INFO_NETWORK_BOOT_GUID \
    { 0x1FBD2960, 0x4130, 0x41E5, { 0x94, 0xAC, 0xD2, 0xCF, 0x03, 0x7F, 0xB3, 0x7C } }

#define EFI_ADAPTER_INFO_SAN_MAC_ADDRESS_GUID \
    { 0x114da5ef, 0x2cf1, 0x4e12, { 0x9b, 0xbb, 0xc4, 0x70, 0xb5, 0x52, 0x05, 0xd9 } }

typedef struct _EFI_ADAPTER_INFORMATION_PROTOCOL EFI_ADAPTER_INFORMATION_PROTOCOL;

typedef struct {
    EFI_STATUS MediaState;
} EFI_ADAPTER_INFO_MEDIA_STATE;

typedef struct {
    BOOLEAN iScsiIpv4BootCapability;
    BOOLEAN iScsiIpv6BootCapability;
    BOOLEAN FCoeBootCapability;
    BOOLEAN OffloadCapability;
    BOOLEAN iScsiMpioCapability;
    BOOLEAN iScsiIpv4Boot;
    BOOLEAN iScsiIpv6Boot;
    BOOLEAN FCoeBoot;
} EFI_ADAPTER_INFO_NETWORK_BOOT;

typedef struct {
    EFI_MAC_ADDRESS SanMacAddress;
} EFI_ADAPTER_INFO_SAN_MAC_ADDRESS;

typedef
EFI_STATUS
(EFIAPI *EFI_ADAPTER_INFO_GET_INFO) (
    IN EFI_ADAPTER_INFORMATION_PROTOCOL *This,
    IN EFI_GUID                         *InformationType,
    OUT VOID                            **InformationBlock,
    OUT UINTN                           *InformationBlockSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_ADAPTER_INFO_SET_INFO) (
    IN EFI_ADAPTER_INFORMATION_PROTOCOL *This,
    IN EFI_GUID                         *InformationType,
    IN VOID                             *InformationBlock,
    IN UINTN                            InformationBlockSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_ADAPTER_INFO_GET_SUPPORTED_TYPES) (
    IN EFI_ADAPTER_INFORMATION_PROTOCOL *This,
    OUT EFI_GUID                        **InfoTypesBuffer,
    OUT UINTN                           *InfoTypesBufferCount
);


struct _EFI_ADAPTER_INFORMATION_PROTOCOL {
    EFI_ADAPTER_INFO_GET_INFO            GetInformation;
    EFI_ADAPTER_INFO_SET_INFO            SetInformation;
    EFI_ADAPTER_INFO_GET_SUPPORTED_TYPES GetSupportedTypes;
};

#endif // EFI_PROTOCOL_DRIVER_ADAPTERINFORMATION_H
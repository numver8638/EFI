#ifndef EFI_PROTOCOL_NETWORK_ARP_H
#define EFI_PROTOCOL_NETWORK_ARP_H

#include <EFI/Types.h>

#define EFI_ARP_SERVICE_BINDING_PROTOCOL_GUID \
    { 0xF44C00EE, 0x1F2C, 0x4A00, { 0xAA, 0x09, 0x1C, 0x9F, 0x3E, 0x08, 0x00, 0xA3 } }

#define EFI_ARP_PROTOCOL_GUID \
    { 0xF4B427BB, 0xBA21, 0x4F16, { 0xBC, 0x4E, 0x43, 0xE4, 0x16, 0xAB, 0x61, 0x9C } }

typedef struct _EFI_ARP_PROTOCOL EFI_ARP_PROTOCOL;

//
// EFI_ARP_CONFIG_DATA
//
typedef struct {
    UINT16              SwAddressType;
    UINT8               SwAddressLength;
    VOID                *StationAddress;
    UINT32              EntryTimeout;
    UINT32              RetryCount;
    UINT32              RetryTimeout;
} EFI_ARP_CONFIG_DATA;

//
// EFI_ARP_FIND_DATA
//
typedef struct {
    UINT32      Size;
    BOOLEAN     DenyFlag;
    BOOLEAN     StaticFlag;
    UINT16      HwAddressType;
    UINT16      SwAddressType;
    UINT8       HwAddressLength;
    UINT8       SwAddressLength;
} EFI_ARP_FIND_DATA;

typedef
EFI_STATUS
(EFIAPI *EFI_ARP_CONFIGURE) (
    IN EFI_ARP_PROTOCOL     *This,
    IN EFI_ARP_CONFIG_DATA  *ConfigData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_ARP_ADD) (
    IN EFI_ARP_PROTOCOL     *This,
    IN BOOLEAN              DenyFlag,
    IN VOID                 *TargetSwAddress, OPTIONAL
    IN VOID                 *TargetHwAddress, OPTIONAL
    IN UINT32               TimeoutValue,
    IN BOOLEAN              Overwrite
);

typedef
EFI_STATUS
(EFIAPI *EFI_ARP_FIND) (
    IN EFI_ARP_PROTOCOL     *This,
    IN BOOLEAN              BySwAddress,
    IN VOID                 *AddressBuffer, OPTIONAL
    OUT UINT32              *EntryLength, OPTIONAL
    OUT UINT32              *EntryCount, OPTIONAL
    OUT EFI_ARP_FIND_DATA   **Entries, OPTIONAL
    IN BOOLEAN              Refresh
);

typedef
EFI_STATUS
(EFIAPI *EFI_ARP_DELETE) (
    IN EFI_ARP_PROTOCOL     *This,
    IN BOOLEAN              BySwAddress,
    IN VOID                 *AddressBuffer OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_ARP_FLUSH) (
    IN EFI_ARP_PROTOCOL     *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_ARP_REQUEST) (
    IN EFI_ARP_PROTOCOL     *This,
    IN VOID                 *TargetSwAddress, OPTIONAL
    IN EFI_EVENT            ResolvedEvent, OPTIONAL
    OUT VOID                *TargetHwAddress
);

typedef
EFI_STATUS
(EFIAPI *EFI_ARP_CANCEL) (
    IN EFI_ARP_PROTOCOL     *This,
    IN VOID                 *TargetSwAddress, OPTIONAL
    IN EFI_EVENT            ResolvedEvent  OPTIONAL
);

struct _EFI_ARP_PROTOCOL {
    EFI_ARP_CONFIGURE       Configure;
    EFI_ARP_ADD             Add;
    EFI_ARP_FIND            Find;
    EFI_ARP_DELETE          Delete;
    EFI_ARP_FLUSH           Flush;
    EFI_ARP_REQUEST         Request;
    EFI_ARP_CANCEL          Cancel;
};

#endif // EFI_PROTOCOL_NETWORK_ARP_H
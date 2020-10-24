#ifndef EFI_PROTOCOL_NETWORK_VLANCONFIGURE_H
#define EFI_PROTOCOL_NETWORK_VLANCONFIGURE_H

#include <EFI/Types.h>

#define EFI_VLAN_CONFIG_PROTOCOL_GUID \
    { 0x9E23D768, 0xD2F3, 0x4366, { 0x9F, 0xC3, 0x3A, 0x7A, 0xBA, 0x86, 0x43, 0x74 } }

typedef struct _EFI_VLAN_CONFIG_PROTOCOL EFI_VLAN_CONFIG_PROTOCOL;

//
// EFI_VLAN_FIND_DATA
//
typedef struct {
    UINT16      VlanId;
    UINT8       Priority;
} EFI_VLAN_FIND_DATA;

typedef
EFI_STATUS
(EFIAPI *EFI_VLAN_CONFIG_SET) (
    IN EFI_VLAN_CONFIG_PROTOCOL     *This,
    IN UINT16                       VlanId,
    IN UINT8                        Priority
);

typedef
EFI_STATUS
(EFIAPI *EFI_VALN_CONFIG_FIND) (
    IN EFI_VLAN_CONFIG_PROTOCOL     *This,
    IN UINT16                       *VlanId, OPTIONAL
    OUT UINT16                      *NumberOfVlan,
    OUT EFI_VLAN_FIND_DATA          **Entries
);

typedef
EFI_STATUS
(EFIAPI *EFI_VALN_CONFIG_REMOVE) (
    IN EFI_VLAN_CONFIG_PROTOCOL     *This,
    IN UINT16                       VlanId
);

struct _EFI_VLAN_CONFIG_PROTOCOL {
    EFI_VLAN_CONFIG_SET         Set;
    EFI_VALN_CONFIG_FIND        Find;
    EFI_VALN_CONFIG_REMOVE      Remove;
};

#endif // EFI_PROTOCOL_NETWORK_VLANCONFIGURE_H
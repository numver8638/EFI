#ifndef EFI_PROTOCOL_NETWORK_IPSEC2_H
#define EFI_PROTOCOL_NETWORK_IPSEC2_H

#include <EFI/Types.h>

#define EFI_IPSEC2_PROTOCOL_GUID \
    { 0xA3779E64, 0xACE8, 0x4DDC, { 0xBC, 0x07, 0x4D, 0x66, 0xB8, 0xFD, 0x09, 0x77 } }

typedef struct _EFI_IPSEC2_PROTOCOL EFI_IPSEC2_PROTOCOL;

//
// EFI_IPSEC_FRAGMENT_DATA
//
typedef struct {
    UINT32  FragmentLength;
    VOID    *FragmentBuffer;
} EFI_IPSEC_FRAGMENT_DATA;

//
// EFI_IPSEC_TRAFFIC_DIR
//
typedef enum {
    EfiIPsecInBound,
    EfiIPsecOutBound
} EFI_IPSEC_TRAFFIC_DIR;

typedef
EFI_STATUS
(EFIAPI *EFI_IPSEC2_PROCESSEXT) (
    IN EFI_IPSEC2_PROTOCOL          *This,
    IN EFI_HANDLE                   NicHandle,
    IN UINT8                        IpVer,
    IN OUT VOID                     *IpHead,
    IN OUT UINT8                    *LastHead,
    IN OUT VOID                     **OptionsBuffer,
    IN OUT UINT32                   *OptionsLength,
    IN OUT EFI_IPSEC_FRAGMENT_DATA  **FragmentTable,
    IN OUT UINT32                   *FragmentCount,
    IN EFI_IPSEC_TRAFFIC_DIR        TrafficDirection,
    OUT EFI_EVENT                   *RecycleSignal
);

struct _EFI_IPSEC2_PROTOCOL {
    EFI_IPSEC2_PROCESSEXT   ProcessExt;
    EFI_EVENT               DisabledEvent;
    BOOLEAN                 DisabledFlag;
};

#endif // EFI_PROTOCOL_NETWORK_IPSEC2_H
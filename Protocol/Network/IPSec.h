#ifndef EFI_PROTOCOL_NETWORK_IPSEC_H
#define EFI_PROTOCOL_NETWORK_IPSEC_H

#include <EFI/Types.h>

#define EFI_IPSEC_PROTOCOL_GUID \
    { 0xDFB386F7, 0xE100, 0x43AD, { 0x9C, 0x9A, 0xED, 0x90, 0xD0, 0x8A, 0x5E, 0x12 } }

typedef struct _EFI_IPSEC_PROTOCOL EFI_IPSEC_PROTOCOL;

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
(EFIAPI *EFI_IPSEC_PROCESS) (
    IN EFI_IPSEC_PROTOCOL           *This,
    IN EFI_HANDLE                   NicHandle,
    IN UINT8                        IpVer,
    IN OUT VOID                     *IpHead,
    IN UINT8                        *LastHead,
    IN VOID                         *OptionsBuffer,
    IN UINT32                       OptionsLength,
    IN OUT EFI_IPSEC_FRAGMENT_DATA  **FragmentTable,
    IN UINT32                       *FragmentCount,
    IN EFI_IPSEC_TRAFFIC_DIR        TrafficDirection,
    OUT EFI_EVENT                   *RecycleSignal
);

struct _EFI_IPSEC_PROTOCOL {
    EFI_IPSEC_PROCESS   Process;
    EFI_EVENT           DisabledEvent;
    BOOLEAN             DisabledFlag;
};

#endif // EFI_PROTOCOL_NETWORK_IPSEC_H
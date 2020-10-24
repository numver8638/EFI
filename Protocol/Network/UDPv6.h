#ifndef EFI_PROTOCOL_NETWORK_UDPV6_H
#define EFI_PROTOCOL_NETWORK_UDPV6_H

#include <EFI/Types.h>
#include <EFI/Protocol/Network/IPv6.h>

#define EFI_UDP6_SERVICE_BINDING_PROTOCOL_GUID \
    { 0x66ED4721, 0x3C98, 0x4D3E, { 0x81, 0xE3, 0xD0, 0x3D, 0xD3, 0x9A, 0x72, 0x54 } }

#define EFI_UDP6_PROTOCOL_GUID \
    { 0x4F948815, 0xB4B9, 0x43CB, { 0x8A, 0x33, 0x90, 0xE0, 0x60, 0xB3, 0x49, 0x55 } }

typedef struct _EFI_UDP6_PROTOCOL EFI_UDP6_PROTOCOL;

//
// EFI_UDP6_CONFIG_DATA
//
typedef struct {
    // Receiving Filters
    BOOLEAN             AcceptPromiscuous;
    BOOLEAN             AcceptAnyPort;
    BOOLEAN             AllowDuplicatePort;

    // I/O parameters
    UINT8               TrafficClass;
    UINT8               HopLimit;
    UINT32              ReceiveTimeout;
    UINT32              TransmitTimeout;

    // Access Point
    BOOLEAN             UseDefaultAddress;
    EFI_IPv6_ADDRESS    StationAddress;
    UINT16              StationPort;
    EFI_IPv6_ADDRESS    RemoteAddress;
    UINT16              RemotePort;
} EFI_UDP6_CONFIG_DATA;

//
// EFI_UDP6_SESSION_DATA
//
typedef struct {
    EFI_IPv6_ADDRESS    SourceAddress;
    UINT16              SourcePort;
    EFI_IPv6_ADDRESS    DestinationAddress;
    UINT16              DestinationPort;
} EFI_UDP6_SESSION_DATA;

//
// EFI_UDP6_FRAGMENT_DATA
//
typedef struct {
    UINT32      FragmentLength;
    VOID        *FragmentBuffer;
} EFI_UDP6_FRAGMENT_DATA;

//
// EFI_UDP6_RECEIVE_DATA
//
typedef struct {
    EFI_TIME                TimeStamp;
    EFI_EVENT               RecycleSignal;
    EFI_UDP6_SESSION_DATA   UdpSession;
    UINT32                  DataLength;
    UINT32                  FragmentCount;
    EFI_UDP6_FRAGMENT_DATA  FragmentTable[1];
} EFI_UDP6_RECEIVE_DATA;

//
// EFI_UDP6_TRANSMIT_DATA
//
typedef struct {
    EFI_UDP6_SESSION_DATA   *UdpSessionData;
    UINT32                  DataLength;
    UINT32                  FragmentCount;
    EFI_UDP6_FRAGMENT_DATA  FragmentTable[1];
} EFI_UDP6_TRANSMIT_DATA;

//
// EFI_UDP6_COMPLETION_TOKEN
//
typedef struct {
    EFI_EVENT                   Event;
    EFI_STATUS                  Status;
    union {
        EFI_UDP6_RECEIVE_DATA   *RxData;
        EFI_UDP6_TRANSMIT_DATA  *TxData;
    }                           Packet;
} EFI_UDP6_COMPLETION_TOKEN;

typedef
EFI_STATUS
(EFIAPI *EFI_UDP6_GET_MODE_DATA) (
    IN EFI_UDP6_PROTOCOL                *This,
    OUT EFI_UDP6_CONFIG_DATA            *Udp4ConfigData, OPTIONAL
    OUT EFI_IP6_MODE_DATA               *Ip4ModeData, OPTIONAL
    OUT EFI_MANAGED_NETWORK_CONFIG_DATA *MnpConfigData, OPTIONAL
    OUT EFI_SIMPLE_NETWORK_MODE         *SnpModeData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_UDP6_CONFIGURE) (
    IN EFI_UDP6_PROTOCOL        *This,
    IN EFI_UDP6_CONFIG_DATA     *UdpConfigData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_UDP6_GROUPS) (
    IN EFI_UDP6_PROTOCOL    *This,
    IN BOOLEAN              JoinFlag,
    IN EFI_IPv6_ADDRESS     *MulticastAddress OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI* EFI_UDP6_TRANSMIT) (
    IN EFI_UDP6_PROTOCOL            *This,
    IN EFI_UDP6_COMPLETION_TOKEN    *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_UDP6_RECEIVE) (
    IN EFI_UDP6_PROTOCOL            *This,
    IN EFI_UDP6_COMPLETION_TOKEN    *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_UDP6_CANCEL) (
    IN EFI_UDP6_PROTOCOL            *This,
    IN EFI_UDP6_COMPLETION_TOKEN    *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_UDP6_POLL) (
    IN EFI_UDP6_PROTOCOL    *This
);

struct _EFI_UDP6_PROTOCOL {
    EFI_UDP6_GET_MODE_DATA      GetModeData;
    EFI_UDP6_CONFIGURE          Configure;
    EFI_UDP6_GROUPS             Groups;
    EFI_UDP6_TRANSMIT           Transmit;
    EFI_UDP6_RECEIVE            Recieve;
    EFI_UDP6_CANCEL             Cancel;
    EFI_UDP6_POLL               Poll;
};

#endif // EFI_PROTOCOL_NETWORK_UDPV6_H
#ifndef EFI_PROTOCOL_NETWORK_UDPV4_H
#define EFI_PROTOCOL_NETWORK_UDPV4_H

#include <EFI/Types.h>
#include <EFI/Protocol/Network/IPv4.h>

#define EFI_UDP4_SERVICE_BINDING_PROTOCOL_GUID \
    { 0x83F01464, 0x99BD, 0x45E5, { 0xB3, 0x83, 0xAF, 0x63, 0x05, 0xD8, 0xE9, 0xE6 } }

#define EFI_UDP4_PROTOCOL_GUID \
    { 0x3AD9DF29, 0x4501, 0x478D, { 0xB1, 0xF8, 0x7F, 0x7F, 0xE7, 0x0E, 0x50, 0xF3 } }

typedef struct _EFI_UDP4_PROTOCOL EFI_UDP4_PROTOCOL;

//
// EFI_UDP4_CONFIG_DATA
//
typedef struct {
    // Receiving Filters
    BOOLEAN             AcceptBroadcast;
    BOOLEAN             AcceptPromiscuous;
    BOOLEAN             AcceptAnyPort;
    BOOLEAN             AllowDuplicatePort;

    // I/O parameters
    UINT8               TypeOfService;
    UINT8               TimeToLive;
    BOOLEAN             DoNotFragment;
    UINT32              ReceiveTimeout;
    UINT32              TransmitTimeout;

    // Access Point
    BOOLEAN             UseDefaultAddress;
    EFI_IPv4_ADDRESS    StationAddress;
    EFI_IPv4_ADDRESS    SubnetMask;
    UINT16              StationPort;
    EFI_IPv4_ADDRESS    RemoteAddress;
    UINT16              RemotePort;
} EFI_UDP4_CONFIG_DATA;

//
// EFI_UDP4_SESSION_DATA
//
typedef struct {
    EFI_IPv4_ADDRESS    SourceAddress;
    UINT16              SourcePort;
    EFI_IPv4_ADDRESS    DestinationAddress;
    UINT16              DestinationPort;
} EFI_UDP4_SESSION_DATA;

//
// EFI_UDP4_FRAGMENT_DATA
//
typedef struct {
    UINT32      FragmentLength;
    VOID        *FragmentBuffer;
} EFI_UDP4_FRAGMENT_DATA;

//
// EFI_UDP4_RECEIVE_DATA
//
typedef struct {
    EFI_TIME                TimeStamp;
    EFI_EVENT               RecycleSignal;
    EFI_UDP4_SESSION_DATA   UdpSession;
    UINT32                  DataLength;
    UINT32                  FragmentCount;
    EFI_UDP4_FRAGMENT_DATA  FragmentTable[1];
} EFI_UDP4_RECEIVE_DATA;

//
// UDP4 Token Status definition
//
#define EFI_NETWORK_UNREACHABLE     EFIERR(100)
#define EFI_HOST_UNREACHABLE        EFIERR(101)
#define EFI_PROTOCOL_UNREACHABLE    EFIERR(102)
#define EFI_PORT_UNREACHABLE        EFIERR(103)

//
// EFI_UDP4_TRANSMIT_DATA
//
typedef struct {
    EFI_UDP4_SESSION_DATA   *UdpSessionData;
    EFI_IPv4_ADDRESS        *GatewayAddress;
    UINT32                  DataLength;
    UINT32                  FragmentCount;
    EFI_UDP4_FRAGMENT_DATA  FragmentTable[1];
} EFI_UDP4_TRANSMIT_DATA;

//
// EFI_UDP4_COMPLETION_TOKEN
//
typedef struct {
    EFI_EVENT                   Event;
    EFI_STATUS                  Status;
    union {
        EFI_UDP4_RECEIVE_DATA   *RxData;
        EFI_UDP4_TRANSMIT_DATA  *TxData;
    }                           Packet;
} EFI_UDP4_COMPLETION_TOKEN;

typedef
EFI_STATUS
(EFIAPI *EFI_UDP4_GET_MODE_DATA) (
    IN EFI_UDP4_PROTOCOL                *This,
    OUT EFI_UDP4_CONFIG_DATA            *Udp4ConfigData, OPTIONAL
    OUT EFI_IP4_MODE_DATA               *Ip4ModeData, OPTIONAL
    OUT EFI_MANAGED_NETWORK_CONFIG_DATA *MnpConfigData, OPTIONAL
    OUT EFI_SIMPLE_NETWORK_MODE         *SnpModeData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_UDP4_CONFIGURE) (
    IN EFI_UDP4_PROTOCOL        *This,
    IN EFI_UDP4_CONFIG_DATA     *UdpConfigData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_UDP4_GROUPS) (
    IN EFI_UDP4_PROTOCOL    *This,
    IN BOOLEAN              JoinFlag,
    IN EFI_IPv4_ADDRESS     *MulticastAddress OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_UDP4_ROUTES) (
    IN EFI_UDP4_PROTOCOL    *This,
    IN BOOLEAN              DeleteRoute,
    IN EFI_IPv4_ADDRESS     *SubnetAddress,
    IN EFI_IPv4_ADDRESS     *SubnetMask,
    IN EFI_IPv4_ADDRESS     *GatewayAddress
);

typedef
EFI_STATUS
(EFIAPI* EFI_UDP4_TRANSMIT) (
    IN EFI_UDP4_PROTOCOL            *This,
    IN EFI_UDP4_COMPLETION_TOKEN    *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_UDP4_RECEIVE) (
    IN EFI_UDP4_PROTOCOL            *This,
    IN EFI_UDP4_COMPLETION_TOKEN    *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_UDP4_CANCEL) (
    IN EFI_UDP4_PROTOCOL            *This,
    IN EFI_UDP4_COMPLETION_TOKEN    *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_UDP4_POLL) (
    IN EFI_UDP4_PROTOCOL    *This
);

struct _EFI_UDP4_PROTOCOL {
    EFI_UDP4_GET_MODE_DATA      GetModeData;
    EFI_UDP4_CONFIGURE          Configure;
    EFI_UDP4_GROUPS             Groups;
    EFI_UDP4_ROUTES             Routes;
    EFI_UDP4_TRANSMIT           Transmit;
    EFI_UDP4_RECEIVE            Recieve;
    EFI_UDP4_CANCEL             Cancel;
    EFI_UDP4_POLL               Poll;
};

#endif // EFI_PROTOCOL_NETWORK_UDPV4_H
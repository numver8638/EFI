#ifndef EFI_PROTOCOL_NETWORK_IPV4_H
#define EFI_PROTOCOL_NETWORK_IPV4_H

#include <EFI/Types.h>
#include <EFI/Protocol/Network/ManagedNetwork.h>

#define EFI_IP4_SERVICE_BINDING_PROTOCOL_GUID \
    { 0xC51711E7, 0xB4BF, 0x404A, { 0xBF, 0xB8, 0x0A, 0x04, 0x8E, 0xF1, 0xFF, 0xE4 } }

#define EFI_IP4_PROTOCOL_GUID \
    { 0x41D94CD2, 0x35B6, 0x455A, { 0x82, 0x58, 0xD4, 0xE5, 0x13, 0x34, 0xAA, 0xDD } }

typedef struct _EFI_IP4_PROTOCOL EFI_IP4_PROTOCOL;

//
// EFI_IP4_CONFIG_DATA
//
typedef struct {
    UINT8               DefaultProtocol;
    BOOLEAN             AcceptAnyProtocol;
    BOOLEAN             AcceptIcmpErrors;
    BOOLEAN             AcceptBroadcast;
    BOOLEAN             AcceptPromiscuous;
    BOOLEAN             UseDefaultAddress;
    EFI_IPv4_ADDRESS    StationAddress;
    EFI_IPv4_ADDRESS    SubnetMask;
    UINT8               TypeOfService;
    UINT8               TimeToLive;
    BOOLEAN             DoNotFragment;
    BOOLEAN             RawData;
    UINT32              ReceiveTimeout;
    UINT32              TransmitTimeout;
} EFI_IP4_CONFIG_DATA;

//
// EFI_IP4_ROUTE_TABLE
//
typedef struct {
    EFI_IPv4_ADDRESS    SubnetAddress;
    EFI_IPv4_ADDRESS    SubnetMask;
    EFI_IPv4_ADDRESS    GatewayAddress;
} EFI_IP4_ROUTE_TABLE;

//
// EFI_IP4_ICMP_TYPE
//
typedef struct {
    UINT8       Type;
    UINT8       Code;
} EFI_IP4_ICMP_TYPE;

//
// EFI_IP4_MODE_DATA
//
typedef struct {
    BOOLEAN                 IsStarted;
    UINT32                  MaxPacketSize;
    EFI_IP4_CONFIG_DATA     ConfigData;
    BOOLEAN                 IsConfigured;
    UINT32                  GroupCount;
    EFI_IPv4_ADDRESS        *GroupTable;
    UINT32                  RouteCount;
    EFI_IPv4_ADDRESS        *RouteTable;
    UINT32                  IcmpTypeCount;
    EFI_IP4_ICMP_TYPE       *IcmpTypeList;
} EFI_IP4_MODE_DATA;

//
// EFI_IP4_HEADER
#pragma pack(1)
typedef struct {
    UINT8               HeaderLength:4;
    UINT8               Version:4;
    UINT8               TypeOfService;
    UINT16              TotalLength;
    UINT16              Identification;
    UINT16              Fragmentation;
    UINT8               TimeToLive;
    UINT8               Protocol;
    UINT16              Checksum;
    EFI_IPv4_ADDRESS    SourceAddress;
    EFI_IPv4_ADDRESS    DestinationAddress;
} EFI_IP4_HEADER;
#pragma pack()

//
// EFI_IP4_FRAGMENT_DATA
//
typedef struct {
    UINT32      FragmentLength;
    VOID        *FragmentBuffer;
} EFI_IP4_FRAGMENT_DATA;

//
// EFI_IP4_RECEIVE_DATA
//
typedef struct {
    EFI_TIME                TimeStamp;
    EFI_EVENT               RecycleSignal;
    UINT32                  HeaderLength;
    EFI_IP4_HEADER          *Header;
    UINT32                  OptionsLength;
    VOID                    *Options;
    UINT32                  DataLength;
    UINT32                  FragmentCount;
    EFI_IP4_FRAGMENT_DATA   FragmentTable[1];
} EFI_IP4_RECEIVE_DATA;

//
// EFI_IP4_OVERRIDE_DATA
//
typedef struct {
    EFI_IPv4_ADDRESS        SourceAddress;
    EFI_IPv4_ADDRESS        GatewayAddress;
    UINT8                   Protocol;
    UINT8                   TypeOfService;
    UINT8                   TimeToLive;
    BOOLEAN                 DoNotFragment;
} EFI_IP4_OVERRIDE_DATA;

//
// EFI_IP4_TRANSMIT_DATA
//
typedef struct {
    EFI_IPv4_ADDRESS        DestinationAddress;
    EFI_IP4_OVERRIDE_DATA   *OverrideData;
    UINT32                  OptionsLength;
    VOID                    *OptionsBuffer;
    UINT32                  TotalDataLength;
    UINT32                  FragmentCount;
    EFI_IP4_FRAGMENT_DATA   FragmentTable[1];
} EFI_IP4_TRANSMIT_DATA;

//
// EFI_IP4_COMPLETION_TOKEN
//
typedef struct {
    EFI_EVENT                       Event;
    EFI_STATUS                      Status;
    union {
        EFI_IP4_RECEIVE_DATA        *RxData;
        EFI_IP4_TRANSMIT_DATA       *TxData;
    }                               Packet;
} EFI_IP4_COMPLETION_TOKEN;

typedef
EFI_STATUS
(EFIAPI *EFI_IP4_GET_MODE_DATA) (
    IN EFI_IP4_PROTOCOL                 *This,
    OUT EFI_IP4_MODE_DATA               *Ip4ModeData, OPTIONAL
    OUT EFI_MANAGED_NETWORK_CONFIG_DATA *MnpConfigData, OPTIONAL
    OUT EFI_SIMPLE_NETWORK_MODE         *SnpModeData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP4_CONFIGURE) (
    IN EFI_IP4_PROTOCOL     *This,
    IN EFI_IP4_CONFIG_DATA  *IpConfigData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP4_GROUPS) (
    IN EFI_IP4_PROTOCOL     *This,
    IN BOOLEAN              JoinFlag,
    IN EFI_IPv4_ADDRESS     *GroupAddress OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP4_ROUTES) (
    IN EFI_IP4_PROTOCOL     *This,
    IN BOOLEAN              DeleteRoute,
    IN EFI_IPv4_ADDRESS     *SubnetAddress,
    IN EFI_IPv4_ADDRESS     *SubnetMask,
    IN EFI_IPv4_ADDRESS     *GatewayAddress
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP4_TRANSMIT) (
    IN EFI_IP4_PROTOCOL             *This,
    IN EFI_IP4_COMPLETION_TOKEN     *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP4_RECEIVE) (
    IN EFI_IP4_PROTOCOL             *This,
    IN EFI_IP4_COMPLETION_TOKEN     *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP4_CANCEL) (
    IN EFI_IP4_PROTOCOL             *This,
    IN EFI_IP4_COMPLETION_TOKEN     *Token OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP4_POLL) (
    IN EFI_IP4_PROTOCOL             *This
);

struct _EFI_IP4_PROTOCOL {
    EFI_IP4_GET_MODE_DATA       GetModeData;
    EFI_IP4_CONFIGURE           Configure;
    EFI_IP4_GROUPS              Groups;
    EFI_IP4_ROUTES              Routes;
    EFI_IP4_TRANSMIT            Transmit;
    EFI_IP4_RECEIVE             Receive;
    EFI_IP4_CANCEL              Cancel;
    EFI_IP4_POLL                Poll;
};

#endif // EFI_PROTOCOL_NETWORK_IPV4_H
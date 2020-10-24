#ifndef EFI_PROTOCOL_NETWORK_IPV6_H
#define EFI_PROTOCOL_NETWORK_IPV6_H

#include <EFI/Types.h>
#include <EFI/Protocol/Network/ManagedNetwork.h>

#define EFI_IP6_SERVICE_BINDING_PROTOCOL_GUID \
    { 0xEC835DD3, 0xFE0F, 0x617B, { 0xA6, 0x21, 0xB3, 0x50, 0xC3, 0xE1, 0x33, 0x88 } }

#define EFI_IP6_PROTOCOL_GUID \
    { 0x2C8759D5, 0x5C2D, 0x66EF, { 0x92, 0x5F, 0xB6, 0x6C, 0x10, 0x19, 0x57, 0xE2 } }

typedef struct _EFI_IP6_PROTOCOL EFI_IP6_PROTOCOL;

//
// EFI_IP6_CONFIG_DATA
//
typedef struct {
    UINT8               DefaultProtocol;
    BOOLEAN             AcceptAnyProtocol;
    BOOLEAN             AcceptIcmpErrors;
    BOOLEAN             AcceptPromiscuous;
    EFI_IPv6_ADDRESS    DestinationAddress;
    EFI_IPv6_ADDRESS    StationAddress;
    UINT8               TrafficClass;
    UINT8               HopLimit;
    UINT32              FlowLabel;
    UINT32              ReceiveTimeout;
    UINT32              TransmitTimeout;
} EFI_IP6_CONFIG_DATA;

//
// EFI_IP6_ADDRESS_INFO
//
typedef struct {
    EFI_IPv6_ADDRESS    Address;
    UINT8               PrefixLength;
} EFI_IP6_ADDRESS_INFO;

//
// EFI_IP6_ROUTE_TABLE
//
typedef struct {
    EFI_IPv6_ADDRESS    Gateway;
    EFI_IPv6_ADDRESS    Destination;
    UINT8               PrefixLength;
} EFI_IP6_ROUTE_TABLE;

//
// EFI_IP6_NEIGHBOR_STATE
//
typedef enum {
    EfiNeighborInComplete,
    EfiNeighborReachable,
    EfiNeighborStale,
    EfiNeighborDelay,
    EfiNeighborProbe
} EFI_IP6_NEIGHBOR_STATE;

//
// EFI_IP6_NEIGHBOR_CACHE
//
typedef struct {
    EFI_IPv6_ADDRESS        Neighbor;
    EFI_MAC_ADDRESS         LinkAddress;
    EFI_IP6_NEIGHBOR_STATE  State;
} EFI_IP6_NEIGHBOR_CACHE;

//
// EFI_IP6_ICMP_TYPE
//
typedef struct {
    UINT8       Type;
    UINT8       Code;
} EFI_IP6_ICMP_TYPE;

//
// ICMPv6 type definitions for error messages
//
#define ICMP_V6_DEST_UNREACHABLE            (0x1)
#define ICMP_V6_PACKET_TOO_BIG              (0x2)
#define ICMP_V6_TIME_EXCEEDED               (0x3)
#define ICMP_V6_PARAMETER_PROBLEM           (0x4)

//
// ICMPv6 type definition for informational messages
//
#define ICMP_V6_ECHO_REQUEST                (0x80)
#define ICMP_V6_ECHO_REPLY                  (0x81)
#define ICMP_V6_LISTENER_QUERY              (0x82)
#define ICMP_V6_LISTENER_REPORT             (0x83)
#define ICMP_V6_LISTENER_DONE               (0x84)
#define ICMP_V6_ROUTER_SOLICIT              (0x85)
#define ICMP_V6_ROUTER_ADVERTISE            (0x86)
#define ICMP_V6_NEIGHBOR_SOLICIT            (0x87)
#define ICMP_V6_NEIGHBOR_ADVERTISE          (0x88)
#define ICMP_V6_REDIRECT                    (0x89)
#define ICMP_V6_LISTENER_REPORT_2           (0x8F)

//
// ICMPv6 code definitions for ICMP_V6_DEST_UNREACHABLE
//
#define ICMP_V6_NO_ROUTE_TO_DEST            (0x0)
#define ICMP_V6_COMM_PROHIBITED             (0x1)
#define ICMP_V6_BEYOND_SCOPE                (0x2)
#define ICMP_V6_ADDR_UNREACHABLE            (0x3)
#define ICMP_V6_PORT_UNREACHABLE            (0x4)
#define ICMP_V6_SOURCE_ADDR_FAILED          (0x5)
#define ICMP_V6_ROUTE_REJECTED              (0x6)

//
// ICMPv6 code definitions for ICMP_V6_TIME_EXCEEDED
//
#define ICMP_V6_TIMEOUT_HOP_LIMIT           (0x0)
#define ICMP_V6_TIMEOUT_REASSEMBLE          (0x1)

//
// ICMPv6 code definitions for ICMPV6_PARAMETER_PROBLEM
//
#define ICMP_V6_ERRONEOUS_HEADER            (0x0)
#define ICMP_V6_UNRECOGNIZE_NEXT_HDR        (0x1)
#define ICMP_V6_UNRECOGNIZE_OPTION          (0x2)

//
// EFI_IP6_MODE_DATA
//
typedef struct {
    BOOLEAN                 IsStarted;
    UINT32                  MaxPacketSize;
    EFI_IP6_CONFIG_DATA     ConfigData;
    BOOLEAN                 IsConfigured;
    UINT32                  AddressCount;
    EFI_IP6_ADDRESS_INFO    *AddressList;
    UINT32                  GroupCount;
    EFI_IPv6_ADDRESS        *GroupTable;
    UINT32                  RouteCount;
    EFI_IPv6_ADDRESS        *RouteTable;
    UINT32                  NeighborCount;
    EFI_IP6_NEIGHBOR_CACHE  *NeighborCache;
    UINT32                  PrefixCount;
    EFI_IP6_ADDRESS_INFO    *PrefixTable;
    UINT32                  IcmpTypeCount;
    EFI_IP6_ICMP_TYPE       *IcmpTypeList;
} EFI_IP6_MODE_DATA;

//
// EFI_IP6_HEADER
#pragma pack(1)
typedef struct {
    UINT8               TrafficClassH:4;
    UINT8               Version:4;
    UINT8               FlowLabelH:4;
    UINT8               TrafficClassL:4;
    UINT16              FlowLabelL;
    UINT16              PayloadLength;
    UINT8               NextHeader;
    UINT8               HopLimit;
    EFI_IPv6_ADDRESS    SourceAddress;
    EFI_IPv6_ADDRESS    DestinationAddress;
} EFI_IP6_HEADER;
#pragma pack()

//
// EFI_IP6_FRAGMENT_DATA
//
typedef struct {
    UINT32      FragmentLength;
    VOID        *FragmentBuffer;
} EFI_IP6_FRAGMENT_DATA;

//
// EFI_IP6_RECEIVE_DATA
//
typedef struct {
    EFI_TIME                TimeStamp;
    EFI_EVENT               RecycleSignal;
    UINT32                  HeaderLength;
    EFI_IP6_HEADER          *Header;
    UINT32                  DataLength;
    UINT32                  FragmentCount;
    EFI_IP6_FRAGMENT_DATA   FragmentTable[1];
} EFI_IP6_RECEIVE_DATA;

//
// EFI_IP6_OVERRIDE_DATA
//
typedef struct {
    UINT8                   Protocol;
    UINT8                   HopLimit;
    UINT32                  FlowLabel;
} EFI_IP6_OVERRIDE_DATA;

//
// EFI_IP6_TRANSMIT_DATA
//
typedef struct {
    EFI_IPv6_ADDRESS        DestinationAddress;
    EFI_IP6_OVERRIDE_DATA   *OverrideData;
    UINT32                  ExtHdrsLength;
    VOID                    *ExtHdrs;
    UINT8                   NextHeader;
    UINT32                  DataLength;
    UINT32                  FragmentCount;
    EFI_IP6_FRAGMENT_DATA   FragmentTable[1];
} EFI_IP6_TRANSMIT_DATA;

//
// EFI_IP6_COMPLETION_TOKEN
//
typedef struct {
    EFI_EVENT                       Event;
    EFI_STATUS                      Status;
    union {
        EFI_IP6_RECEIVE_DATA        *RxData;
        EFI_IP6_TRANSMIT_DATA       *TxData;
    }                               Packet;
} EFI_IP6_COMPLETION_TOKEN;

typedef
EFI_STATUS
(EFIAPI *EFI_IP6_GET_MODE_DATA) (
    IN EFI_IP6_PROTOCOL                 *This,
    OUT EFI_IP6_MODE_DATA               *Ip6ModeData, OPTIONAL
    OUT EFI_MANAGED_NETWORK_CONFIG_DATA *MnpConfigData, OPTIONAL
    OUT EFI_SIMPLE_NETWORK_MODE         *SnpModeData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP6_CONFIGURE) (
    IN EFI_IP6_PROTOCOL     *This,
    IN EFI_IP6_CONFIG_DATA  *IpConfigData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP6_GROUPS) (
    IN EFI_IP6_PROTOCOL     *This,
    IN BOOLEAN              JoinFlag,
    IN EFI_IPv6_ADDRESS     *GroupAddress OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP6_ROUTES) (
    IN EFI_IP6_PROTOCOL     *This,
    IN BOOLEAN              DeleteRoute,
    IN EFI_IPv6_ADDRESS     *Destination, OPTIONAL
    IN UINT8                PrefixLength,
    IN EFI_IPv6_ADDRESS     *GatewayAddress OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP6_NEIGHBORS) (
    IN EFI_IP6_PROTOCOL     *This,
    IN BOOLEAN              DeleteFlag,
    IN EFI_IPv6_ADDRESS     *TargetIp6Address,
    IN EFI_MAC_ADDRESS      *TargetLinkAddress, OPTIONAL
    IN UINT32               Timeout,
    IN BOOLEAN              Override
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP6_TRANSMIT) (
    IN EFI_IP6_PROTOCOL             *This,
    IN EFI_IP6_COMPLETION_TOKEN     *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP6_RECEIVE) (
    IN EFI_IP6_PROTOCOL             *This,
    IN EFI_IP6_COMPLETION_TOKEN     *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP6_CANCEL) (
    IN EFI_IP6_PROTOCOL             *This,
    IN EFI_IP6_COMPLETION_TOKEN     *Token OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP6_POLL) (
    IN EFI_IP6_PROTOCOL             *This
);

struct _EFI_IP6_PROTOCOL {
    EFI_IP6_GET_MODE_DATA       GetModeData;
    EFI_IP6_CONFIGURE           Configure;
    EFI_IP6_GROUPS              Groups;
    EFI_IP6_ROUTES              Routes;
    EFI_IP6_NEIGHBORS           Neighbors;
    EFI_IP6_TRANSMIT            Transmit;
    EFI_IP6_RECEIVE             Receive;
    EFI_IP6_CANCEL              Cancel;
    EFI_IP6_POLL                Poll;
};

#endif // EFI_PROTOCOL_NETWORK_IPV6_H
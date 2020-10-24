#ifndef EFI_PROTOCOL_NETWORK_MANAGEDNETWORK_H
#define EFI_PROTOCOL_NETWORK_MANAGEDNETWORK_H

#include <EFI/Types.h>
#include <EFI/Protocol/Network/SimpleNetwork.h>

#define EFI_MANAGED_NETWORK_SERVICE_BINDING_PROTOCOL_GUID \
    { 0xF36FF770, 0xA7E1, 0x42CF, { 0x9E, 0xD2, 0x56, 0xF0, 0xF2, 0x71, 0xF4, 0x4C } }

#define EFI_MANAGED_NETWORK_PROTOCOL_GUID \
    { 0x7AB33A91, 0xACE5, 0x4326, { 0xB5, 0x72, 0xE7, 0xEE, 0x33, 0xD3, 0x9F, 0x16 } }

typedef struct _EFI_MANAGED_NETWORK_PROTOCOL EFI_MANAGED_NETWORK_PROTOCOL;

//
// EFI_MANAGED_NETWORK_CONFIG_DATA
//
typedef struct {
    UINT32      ReceivedQueueTimeoutValue;
    UINT32      TransmitQueueTimeoutValue;
    UINT16      ProtocolTypeFilter;
    BOOLEAN     EnableUnicastReceive;
    BOOLEAN     EnableMulticastReceive;
    BOOLEAN     EnablePromiscuousReceive;
    BOOLEAN     FlushQueuesOnReset;
    BOOLEAN     EnableReceiveTimestamps;
    BOOLEAN     DisableBackgroundPolling;
} EFI_MANAGED_NETWORK_CONFIG_DATA;

//
// EFI_MANAGED_NETWORK_RECEIVE_DATA
//
typedef struct {
    EFI_TIME        Timestamp;
    EFI_EVENT       RecycleEvent;
    UINT32          PacketLength;
    UINT32          HeaderLength;
    UINT32          AddressLength;
    UINT32          DataLength;
    BOOLEAN         BroadcastFlag;
    BOOLEAN         MulticastFlag;
    BOOLEAN         PromiscuousFlag;
    UINT16          ProtocolType;
    VOID            *DestinationAddress;
    VOID            *SourceAddress;
    VOID            *MediaHeader;
    VOID            *PacketData;
} EFI_MANAGED_NETWORK_RECEIVE_DATA;

//
// EFI_MANAGED_NETWORK_FRAGMENT_DATA
//
typedef struct {
    UINT32      FragmentLength;
    VOID        *FragmentBuffer;
} EFI_MANAGED_NETWORK_FRAGMENT_DATA;

//
// EFI_MANAGED_NETWORK_TRANSMIT_DATA
//
typedef struct {
    EFI_MAC_ADDRESS                     *DestinationAddress OPTIONAL;
    EFI_MAC_ADDRESS                     *SourceAddress      OPTIONAL;
    UINT16                              ProtocolType        OPTIONAL;
    UINT32                              DataLength;
    UINT16                              HeaderLength        OPTIONAL;
    UINT16                              FragmentCount;
    EFI_MANAGED_NETWORK_FRAGMENT_DATA   FragmentTable[1];
} EFI_MANAGED_NETWORK_TRANSMIT_DATA;

//
// EFI_MANAGED_NETWORK_COMPLETION_TOKEN
//
typedef struct {
    EFI_EVENT                               Event;
    EFI_STATUS                              Status;
    union {
        EFI_MANAGED_NETWORK_RECEIVE_DATA    *RxData;
        EFI_MANAGED_NETWORK_TRANSMIT_DATA   *TxData;
    }                                       Packet;
} EFI_MANAGED_NETWORK_COMPLETION_TOKEN;

typedef
EFI_STATUS
(EFIAPI *EFI_MANAGED_NETWORK_GET_MODE_DATA) (
    IN EFI_MANAGED_NETWORK_PROTOCOL         *This,
    OUT EFI_MANAGED_NETWORK_CONFIG_DATA     *MnpConfigData, OPTIONAL
    OUT EFI_SIMPLE_NETWORK_MODE             *SnpModeData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_MANAGED_NETWORK_CONFIGURE) (
    IN EFI_MANAGED_NETWORK_PROTOCOL         *This,
    IN EFI_MANAGED_NETWORK_CONFIG_DATA      *MnpConfigData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_MANAGED_NETWORK_MCAST_IP_TO_MAC) (
    IN EFI_MANAGED_NETWORK_PROTOCOL     *This,
    IN BOOLEAN                          Ipv6Flag,
    IN EFI_IP_ADDRESS                   *IpAddress,
    OUT EFI_MAC_ADDRESS                 *MacAddress
);

typedef
EFI_STATUS
(EFIAPI *EFI_MANAGED_NETWORK_GROUPS) (
    IN EFI_MANAGED_NETWORK_PROTOCOL     *This,
    IN BOOLEAN                          JoinFlag,
    IN EFI_MAC_ADDRESS                  *MacAddress OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_MANAGED_NETWORK_TRANSMIT) (
    IN EFI_MANAGED_NETWORK_PROTOCOL             *This,
    IN EFI_MANAGED_NETWORK_COMPLETION_TOKEN     *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_MANAGED_NETWORK_RECEIVE) (
    IN EFI_MANAGED_NETWORK_PROTOCOL             *This,
    IN EFI_MANAGED_NETWORK_COMPLETION_TOKEN     *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_MANAGED_NETWORK_CANCEL) (
    IN EFI_MANAGED_NETWORK_PROTOCOL             *This,
    IN EFI_MANAGED_NETWORK_COMPLETION_TOKEN     *Token OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_MANAGED_NETWORK_POLL) (
    IN EFI_MANAGED_NETWORK_PROTOCOL     *This
);

struct _EFI_MANAGED_NETWORK_PROTOCOL {
    EFI_MANAGED_NETWORK_GET_MODE_DATA       GetModeData;
    EFI_MANAGED_NETWORK_CONFIGURE           Configure;
    EFI_MANAGED_NETWORK_MCAST_IP_TO_MAC     McastIpToMac;
    EFI_MANAGED_NETWORK_GROUPS              Groups;
    EFI_MANAGED_NETWORK_TRANSMIT            Transmit;
    EFI_MANAGED_NETWORK_RECEIVE             Receive;
    EFI_MANAGED_NETWORK_CANCEL              Cancel;
    EFI_MANAGED_NETWORK_POLL                Poll;
};

#endif // EFI_PROTOCOL_NETWORK_MANAGEDNETWORK_H
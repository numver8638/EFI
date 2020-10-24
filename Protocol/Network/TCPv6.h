#ifndef EFI_PROTOCOL_NETWORK_TCPV6_H
#define EFI_PROTOCOL_NETWORK_TCPV6_H

#include <EFI/Types.h>
#include <EFI/Protocol/Network/IPv6.h>

#define EFI_TCP6_SERVICE_BINDIG_PROROCOL_GUID \
    { 0xERC20EB79, 0x6C1A, 0x4664, { 0x9A, 0x0D, 0xD2, 0xE4, 0xCC, 0x16, 0xD6, 0x64 } }

#define EFI_TCP6_PROTOCOL_GUID \
    { 0x46E44855, 0xBD00, 0x4AB7, { 0xAB, 0x0D, 0xA6, 0x79, 0xB9, 0x44, 0x7D, 0x77 } }

typedef struct _EFI_TCP6_PROTOCOL EFI_TCP6_PROTOCOL;

//
// EFI_TCP6_ACCESS_POINT
//
typedef struct {
    EFI_IPv6_ADDRESS    StationAddress;
    UINT16              StationPort;
    EFI_IPv6_ADDRESS    RemoteAddress;
    UINT16              RemotePort;
    BOOLEAN             ActiveFlag;
} EFI_TCP6_ACCESS_POINT;

//
// EFI_TCP6_OPTION
//
typedef struct {
    UINT32          ReceiveBufferSize;
    UINT32          SendBufferSize;
    UINT32          MaxSynBackLog;
    UINT32          ConnectionTimeout;
    UINT32          DataRetries;
    UINT32          FinTimeout;
    UINT32          TimeWaitTimeout;
    UINT32          KeepAliveProbes;
    UINT32          KeepAliveTime;
    UINT32          KeepAliveInterval;
    BOOLEAN         EnableNagle;
    BOOLEAN         EnableTimeStamp;
    BOOLEAN         EnableWindowScaling;
    BOOLEAN         EnableSelectiveAck;
    BOOLEAN         EnablePathMtuDiscovery;
} EFI_TCP6_OPTION;

//
// EFI_TCP6_CONFIG_DATA
//
typedef struct {
    UINT8                   TrafficClass;
    UINT8                   HopLimit;
    EFI_TCP6_ACCESS_POINT   AccessPoint;
    EFI_TCP6_OPTION         *ControlOption;
} EFI_TCP6_CONFIG_DATA;

//
// EFI_TCP6_CONNECTION_STATE
//
typedef enum {
    Tcp6StateClosed         = 0,
    Tcp6StateListen         = 1,
    Tcp6StateSynSent        = 2,
    Tcp6StateSynReceived    = 3,
    Tcp6StateEstablished    = 4,
    Tcp6StateFinWait1       = 5,
    Tcp6StateFinWait2       = 6,
    Tcp6StateClosing        = 7,
    Tcp6StateTimeWait       = 8,
    Tcp6StateCloseWait      = 9,
    Tcp6StateLastAck        = 10
} EFI_TCP6_CONNECTION_STATE;

//
// EFI_TCP6_COMPLETION_TOKEN
//
typedef struct {
    EFI_EVENT       Event;
    EFI_STATUS      Status;
} EFI_TCP6_COMPLETION_TOKEN;

//
// EFI_TCP6_CONNECTION_TOKEN
//
typedef struct {
    EFI_TCP6_COMPLETION_TOKEN   CompletionToken;
} EFI_TCP6_CONNECTION_TOKEN;

//
// EFI_TCP6_LISTEN_TOKEN
//
typedef struct {
    EFI_TCP6_COMPLETION_TOKEN   CompletionToken;
    EFI_HANDLE                  NewChildHandle;
} EFI_TCP6_LISTEN_TOKEN;

//
// TCP6 Token Status definition
//
#define EFI_CONNECTION_FIN          EFIERR(104)
#define EFI_CONNECTION_RESET        EFIERR(105)
#define EFI_CONNECTION_REFUSED      EFIERR(106)

//
// EFI_TCP6_FRAGMENT_DATA
//
typedef struct {
    UINT32      FragmentLength;
    VOID        *FragmentBuffer;
} EFI_TCP6_FRAGMENT_DATA;

//
// EFI_TCP6_RECEIVE_DATA
//
typedef struct {
    BOOLEAN                 UrgentFlag;
    UINT32                  DataLength;
    UINT32                  FragmentCount;
    EFI_TCP6_FRAGMENT_DATA  FragmentTable[1];
} EFI_TCP6_RECEIVE_DATA;

//
// EFI_TCP6_TRANSMIT_DATA
//
typedef struct {
    BOOLEAN                 Push;
    BOOLEAN                 Urgent;
    UINT32                  DataLength;
    UINT32                  FragmentCount;
    EFI_TCP6_FRAGMENT_DATA  FragmentTable[1];
} EFI_TCP6_TRANSMIT_DATA;

//
// EFI_TCP6_IO_TOKEN
//
typedef struct {
    EFI_TCP6_COMPLETION_TOKEN       CompletionToken;
    union {
        EFI_TCP6_RECEIVE_DATA       *RxData;
        EFI_TCP6_TRANSMIT_DATA      *TxData;
    }                               Packet;
} EFI_TCP6_IO_TOKEN;

//
// EFI_TCP6_CLOSE_TOKEN
//
typedef struct {
    EFI_TCP6_COMPLETION_TOKEN       CompletionToken;
    BOOLEAN                         AbortOnClose;
} EFI_TCP6_CLOSE_TOKEN;

typedef
EFI_STATUS
(EFIAPI *EFI_TCP6_GET_MODE_DATA) (
    IN EFI_TCP6_PROTOCOL                *This,
    OUT EFI_TCP6_CONNECTION_STATE       *Tcp6State, OPTIONAL
    OUT EFI_TCP6_CONFIG_DATA            *Tcp6ConfigData, OPTIONAL
    OUT EFI_IPv6_MODE_DATA              *Ip6ModeData, OPTIONAL
    OUT EFI_MANAGED_NETWORK_CONFIG_DATA *MnpConfigData, OPTIONAL
    OUT EFI_SIMPLE_NETWORK_MODE         *SnpModeData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_TCP6_CONFIGURE) (
    IN EFI_TCP6_PROTOCOL        *This,
    IN EFI_TCP6_CONFIG_DATA     *Tcp6ConfigData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_TCP6_CONNECT) (
    IN EFI_TCP6_PROTOCOL            *This,
    IN EFI_TCP6_CONNECTION_TOKEN    *ConnectionToken
);

typedef
EFI_STATUS
(EFIAPI *EFI_TCP6_ACCEPT) (
    IN EFI_TCP6_PROTOCOL            *This,
    IN EFI_TCP6_LISTEN_TOKEN        *ListenToken
);

typedef
EFI_STATUS
(EFIAPI *EFI_TCP6_TRANSMIT) (
    IN EFI_TCP6_PROTOCOL            *This,
    IN EFI_TCP6_IO_TOKEN            *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_TCP6_RECEIVE) (
    IN EFI_TCP6_PROTOCOL            *This,
    IN EFI_TCP6_IO_TOKEN            *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_TCP6_CLOSE) (
    IN EFI_TCP6_PROTOCOL        *This,
    IN EFI_TCP6_CLOSE_TOKEN     *CloseToken
);

typedef
EFI_STATUS
(EFIAPI *EFI_TCP6_CANCEL) (
    IN EFI_TCP6_PROTOCOL            *This,
    IN EFI_TCP6_COMPLETION_TOKEN    *Token OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_TCP6_POLL) (
    IN EFI_TCP6_PROTOCOL    *This
);

struct _EFI_TCP6_PROTOCOL {
    EFI_TCP6_GET_MODE_DATA      GetModeData;
    EFI_TCP6_CONFIGURE          Configure;
    EFI_TCP6_CONNECT            Connect;
    EFI_TCP6_ACCEPT             Accept;
    EFI_TCP6_TRANSMIT           Transmit;
    EFI_TCP6_RECEIVE            Receive;
    EFI_TCP6_CLOSE              Close;
    EFI_TCP6_CANCEL             Cancel;
    EFI_TCP6_POLL               Poll;
};

#endif // EFI_PROTOCOL_NETWORK_TCPV6_H
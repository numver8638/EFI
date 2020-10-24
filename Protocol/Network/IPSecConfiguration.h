#ifndef EFI_PROTOCOL_NETWORK_IPSECCONFIGURATION_H
#define EFI_PROTOCOL_NETWORK_IPSECCONFIGURATION_H

#include <EFI/Types.h>

#define EFI_IPSEC_CONFIG_PROTOCOL_GUID \
    { 0xCE5E6929, 0xC7A3, 0x4602, { 0xAD, 0x9E, 0xC9, 0xDA, 0xF9, 0x4E, 0xBF, 0xCF } }

typedef struct _EFI_IPSEC_CONFIG_PROTOCOL EFI_IPSEC_CONFIG_PROTOCOL;

//
// EFI_IPSEC_CONFIG_DATA_TYPE
//
typedef enum {
    IPsecConfigDataTypeSpd,
    IPsecConfigDataTypeSad,
    IPsecConfigDataTypePad,
    IPsecConfigDataTypeMaximum
} EFI_IPSEC_CONFIG_DATA_TYPE;

//
// EFI_IP_ADDRESS_INFO
//
typedef struct {
    EFI_IP_ADDRESS      Address;
    UINT8               PrefixLength;
} EFI_IP_ADDRESS_INFO;

//
// EFI_IPSEC_SPD_SELECTOR
//
typedef struct {
    UINT32                  LocalAddressCount;
    EFI_IP_ADDRESS_INFO     *LocalAddress;
    UINT32                  RemoteAddressCount;
    EFI_IP_ADDRESS_INFO     *RemoteAddress;
    UINT16                  NextLayerProtocol;

    // Several additional selectors depend on the ProtoFamily
    UINT16                  LocalPort;
    UINT16                  LocalPortRange;
    UINT16                  RemotePort;
    UINT16                  RemotePortRange;
} EFI_IPSEC_SPD_SELECTOR;

//
// EFI_IPSEC_TRAFFIC_DIR
//
typedef enum {
    EfiIPsecInBound,
    EfiIPsecOutBound
} EFI_IPSEC_TRAFFIC_DIR;

//
// EFI_IPSEC_ACTION
//
typedef enum {
    EfiIPsecActionDiscard,
    EfiIPsecActionBypass,
    EfiIPsecActionProtect
} EFI_IPSEC_ACTION;

//
// EFI_IPSEC_SA_LIFETIME
//
typedef struct {
    UINT64      ByteCount;
    UINT64      SoftLifetime;
    UINT64      HardLifetime;
} EFI_IPSEC_SA_LIFETIME;

//
// EFI_IPSEC_MODE
//
typedef enum {
    EfiIPsecTransport,
    EfiIPsecTunnel
} EFI_IPSEC_MODE;

//
// EFI_IPSEC_TUNNEL_DF_OPTION
//
typedef enum {
    EfiIPsecTunnelClearDf,
    EfiIPsecTunnelSetDf,
    EfiIPsecTunnelCopyDf
} EFI_IPSEC_TUNNEL_DF_OPTION;

//
// EFI_IPSEC_TUNNEL_OPTION
//
typedef struct {
    EFI_IP_ADDRESS              LocalTunnelAddress;
    EFI_IP_ADDRESS              RemoteTunnelAddress;
    EFI_IPSEC_TUNNEL_DF_OPTION  DF;
} EFI_IPSEC_TUNNEL_OPTION;

//
// EFI_IPSEC_PROTOCOL_TYPE
//
typedef enum {
    EfiIPsecAH,
    EfiIPsecESP
} EFI_IPSEC_PROTOCOL_TYPE;

//
// EFI_IPSEC_PROCESS_POLICY
//
typedef struct {
    BOOLEAN                     ExtSeqNum;
    BOOLEAN                     SeqOverflow;
    BOOLEAN                     FragCheck;
    EFI_IPSEC_SA_LIFETIME       SaLifetime;
    EFI_IPSEC_MODE              Mode;
    EFI_IPSEC_TUNNEL_OPTION     *TunnelOption;
    EFI_IPSEC_PROTOCOL_TYPE     Proto;
    UINT8                       AuthAlgoId;
    UINT8                       EncAlgoId;
} EFI_IPSEC_PROCESS_POLICY;

//
// EFI_IPSEC_SA_ID
//
typedef struct {
    UINT32                      Spi;
    EFI_IPSEC_PROTOCOL_TYPE     Proto;
    EFI_IP_ADDRESS              DestAddress;
} EFI_IPSEC_SA_ID;

#define MAX_PEERID_LEN  (128)

//
// EFI_IPSEC_SPD_DATA
//
typedef struct {
    UINT8                       *Name[MAX_PEERID_LEN];
    UINT32                      PackageFlag;
    EFI_IPSEC_TRAFFIC_DIR       TrafficDirection;
    EFI_IPSEC_ACTION            Action;
    EFI_IPSEC_PROCESS_POLICY    *ProcessingPolicy;
    UINTN                       SaIdCount;
    EFI_IPSEC_SA_ID             *SaId[1];
} EFI_IPSEC_SPD_DATA;

//
// EFI_IPSEC_AH_ALGO_INFO
//
typedef struct {
    UINT8       AuthAlgoId;
    UINTN       KeyLength;
    VOID        *Key;
} EFI_IPSEC_AH_ALGO_INFO;

//
// EFI_IPSEC_ESP_ALGO_INFO
//
typedef struct {
    UINT8       EncAlgoId;
    UINTN       EncKeyLength;
    VOID        *EncKey;
    UINT8       AuthAlgoId;
    UINTN       AuthKeyLength;
    VOID        *AuthKey;
} EFI_IPSEC_ESP_ALGO_INFO;

//
// EFI_IPSEC_ALGO_INFO
//
typedef union {
    EFI_IPSEC_AH_ALGO_INFO      AhAlgoInfo;
    EFI_IPSEC_ESP_ALGO_INFO     EspAlgoInfo;
} EFI_IPSEC_ALGO_INFO;

//
// EFI_IPSEC_SA_DATA
//
typedef struct {
    EFI_IPSEC_MODE          Mode;
    UINT64                  SNCount;
    UINT8                   AntiReplayWindows;
    EFI_IPSEC_ALGO_INFO     AlgoInfo;
    EFI_IPSEC_SA_LIFETIME   SaLifetime;
    UINT32                  PathMTU;
    EFI_IPSEC_SPD_SELECTOR  *SpdSelector;
    BOOLEAN                 ManualSet;
} EFI_IPSEC_SA_DATA;

//
// EFI_IPSEC_SA_DATA2
//
typedef struct {
    EFI_IPSEC_MODE          Mode;
    UINT64                  SNCount;
    UINT8                   AntiReplayWindows;
    EFI_IPSEC_ALGO_INFO     AlgoInfo;
    EFI_IPSEC_SA_LIFETIME   SaLifetime;
    UINT32                  PathMTU;
    EFI_IPSEC_SPD_SELECTOR  *SpdSelector;
    BOOLEAN                 ManualSet;
    EFI_IP_ADDRESS          TunnelSourceAddress;
    EFI_IP_ADDRESS          TunnelDestinationAddress;
} EFI_IPSEC_SA_DATA2;

//
// EFI_IPSEC_PAD_ID
//
typedef struct {
    BOOLEAN                     PeerIdValid;
    union {
        EFI_IP_ADDRESS_INFO     IpAddress;
        UINT8                   PeerId[MAX_PEERID_LEN];
    } Id;
} EFI_IPSEC_PAD_ID;

//
// EFI_IPSEC_AUTH_PROTOCOL_TYPE
//
typedef enum {
    EfiIPsecAuthProtocolIKEv1,
    EfiIPsecAuthProtocolIKEv2,
    EfiIPsecAuthProtocolMaximum
} EFI_IPSEC_AUTH_PROTOCOL_TYPE;

//
// EFI_IPSEC_AUTH_METHOD
//
typedef enum {
    EfiIPsecAuthMethodPreSharedSecret,
    EfiIPsecAuthMethodCertificates,
    EfiIPsecAuthMethodMaximum
} EFI_IPSEC_AUTH_METHOD;

//
// EFI_IPSEC_PAD_DATA
//
typedef struct {
    EFI_IPSEC_AUTH_PROTOCOL_TYPE    AuthProtocol;
    EFI_IPSEC_AUTH_METHOD           AuthMethod;
    BOOLEAN                         IkeIdFlag;
    UINTN                           AuthDataSize;
    VOID                            *AuthData;
    UINTN                           RevocationDataSize;
    VOID                            *RevocationData;
} EFI_IPSEC_PAD_DATA;

//
// EFI_IPSEC_CONFIG_SELECTOR
//
typedef union {
    EFI_IPSEC_SPD_SELECTOR      SpdSelector;
    EFI_IPSEC_SA_ID             SaId;
    EFI_IPSEC_PAD_ID            PadId;
} EFI_IPSEC_CONFIG_SELECTOR;

typedef
EFI_STATUS
(EFIAPI *EFI_IPSEC_CONFIG_SET_DATA) (
    IN EFI_IPSEC_CONFIG_PROTOCOL    *This,
    IN EFI_IPSEC_CONFIG_DATA_TYPE   DataType,
    IN EFI_IPSEC_CONFIG_SELECTOR    *Selector,
    IN VOID                         *Data,
    IN EFI_IPSEC_CONFIG_SELECTOR    *InsertBefore OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IPSEC_CONFIG_GET_DATA) (
    IN EFI_IPSEC_CONFIG_PROTOCOL    *This,
    IN EFI_IPSEC_CONFIG_DATA_TYPE   DataType,
    IN EFI_IPSEC_CONFIG_SELECTOR    *Selector,
    IN OUT UINTN                    *DataSize,
    IN VOID                         *Data OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IPSEC_CONFIG_GET_NEXT_SELECTOR) (
    IN EFI_IPSEC_CONFIG_PROTOCOL        *This,
    IN EFI_IPSEC_CONFIG_DATA_TYPE       DataType,
    IN OUT UINTN                        *SelectorSize,
    IN OUT EFI_IPSEC_CONFIG_SELECTOR    *Selector
);

typedef
EFI_STATUS
(EFIAPI *EFI_IPSEC_CONFIG_REGISTER_NOTIFY) (
    IN EFI_IPSEC_CONFIG_PROTOCOL    *This,
    IN EFI_IPSEC_CONFIG_DATA_TYPE   DataType,
    IN EFI_EVENT                    Event
);

typedef
EFI_STATUS
(EFIAPI *EFI_IPSEC_CONFIG_UNREGISTER_NOTIFY) (
    IN EFI_IPSEC_CONFIG_PROTOCOL    *This,
    IN EFI_IPSEC_CONFIG_DATA_TYPE   DataType,
    IN EFI_EVENT                    Event
);

struct _EFI_IPSEC_CONFIG_PROTOCOL {
    EFI_IPSEC_CONFIG_SET_DATA               SetData;
    EFI_IPSEC_CONFIG_GET_DATA               GetData;
    EFI_IPSEC_CONFIG_GET_NEXT_SELECTOR      GetNextSelector;
    EFI_IPSEC_CONFIG_REGISTER_NOTIFY        RegisterDataNotify;
    EFI_IPSEC_CONFIG_UNREGISTER_NOTIFY      UnregisterDataNotify;
};

#endif // EFI_PROTOCOL_NETWORK_IPSECCONFIGURATION_H
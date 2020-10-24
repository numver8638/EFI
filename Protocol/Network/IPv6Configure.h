#ifndef EFI_PROTOCOL_NETWORK_IPV6CONFIGURE_H
#define EFI_PROTOCOL_NETWORK_IPV6CONFIGURE_H

#include <EFI/Types.h>
#include <EFI/Protocol/Network/IPv6.h> // for EFI_IP6_ROUTE_TABLE

#define EFI_IP6_CONFIG_PROTOCOL_GUID \
    { 0x937FE521, 0x95AE, 0x4D1A, { 0x89, 0x29, 0x48, 0xBC, 0xD9, 0x0A, 0xD3, 0x1A } }

typedef struct _EFI_IP6_CONFIG_PROTOCOL EFI_IP6_CONFIG_PROTOCOL;

//
// EFI_IP6_CONFIG_DATA_TYPE
//
typedef enum {
    Ip6ConfigDataTypeInterfaceInfo,
    Ip6ConfigDataTypeAltInterfaceId,
    Ip6ConfigDataTypePolicy,
    Ip6ConfigDataTypeDupAddrDetectTransmits,
    Ip6ConfigDataTypeManualAddress,
    Ip6ConfigDataTypeGateway,
    Ip6ConfigDataTypeDnsServer,
    Ip6ConfigDataTypeMaximum
} EFI_IP6_CONFIG_DATA_TYPE;

//
// EFI_IP6_CONFIG_INTERFACE_INFO
//
typedef struct {
    CHAR16                  Name[32];
    UINT8                   IfType;
    UINT32                  HwAddressSize;
    EFI_MAC_ADDRESS         HwAddress;
    UINT32                  AddressInfoSize;
    EFI_IP6_ADDRESS_INFO    *AddressInfo;
    UINT32                  RouteCount;
    EFI_IP6_ROUTE_TABLE     *RouteTable;
} EFI_IP6_CONFIG_INTERFACE_INFO;

//
// EFI_IP6_CONFIG_INTERFACE_ID
//
typedef struct {
    UINT8       Id[8];
} EFI_IP6_CONFIG_INTERFACE_ID;

//
// EFI_IP6_CONFIG_POLICY
//
typedef enum {
    Ip6ConfigPolicyManual,
    Ip6ConfigPolicyAutomatic
} EFI_IP6_CONFIG_POLICY;

//
// EFI_IP6_CONFIG_DUP_ADDR_DETECT_TRANSMITS
//
typedef struct {
    UINT32      DupAddrDetectTransmits;
} EFI_IP6_CONFIG_DUP_ADDR_DETECT_TRANSMITS;

//
// EFI_IP6_CONFIG_MANUAL_ADDRESS
//
typedef struct {
    EFI_IPv6_ADDRESS        Address;
    BOOLEAN                 IsAnycast;
    UINT8                   PrefixLength;
} EFI_IP6_CONFIG_MANUAL_ADDRESS;

typedef
EFI_STATUS
(EFIAPI *EFI_IP6_CONFIG_SET_DATA) (
    IN EFI_IP6_CONFIG_PROTOCOL      *This,
    IN EFI_IP6_CONFIG_DATA_TYPE     DataType,
    IN UINTN                        DataSize,
    IN VOID                         *Data
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP6_CONFIG_GET_DATA) (
    IN EFI_IP6_CONFIG_PROTOCOL      *This,
    IN EFI_IP6_CONFIG_DATA_TYPE     DataType,
    IN OUT UINTN                    *DataSize,
    IN VOID                         *Data OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP6_CONFIG_REGISTER_NOTIFY) (
    IN EFI_IP6_CONFIG_PROTOCOL      *This,
    IN EFI_IP6_CONFIG_DATA_TYPE     DataType,
    IN EFI_EVENT                    Event
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP6_CONFIG_UNREGISTER_NOTIFY) (
    IN EFI_IP6_CONFIG_PROTOCOL      *This,
    IN EFI_IP6_CONFIG_DATA_TYPE     DataType,
    IN EFI_EVENT                    Event
);

struct _EFI_IP6_CONFIG_PROTOCOL {
    EFI_IP6_CONFIG_SET_DATA             SetData;
    EFI_IP6_CONFIG_GET_DATA             GetData;
    EFI_IP6_CONFIG_REGISTER_NOTIFY      RegisterDataNotify;
    EFI_IP6_CONFIG_UNREGISTER_NOTIFY    UnregisterDataNotify;
};

#endif // EFI_PROTOCOL_NETWORK_IPV6CONFIGURE_H
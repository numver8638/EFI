#ifndef EFI_PROTOCOL_NETWORK_IPV4CONFIGURE_H
#define EFI_PROTOCOL_NETWORK_IPV4CONFIGURE_H

#include <EFI/Types.h>
#include <EFI/Protocol/Network/IPv4.h> // for EFI_IP4_ROUTE_TABLE

#define EFI_IP4_CONFIG_PROTOCOL_GUID \
    { 0x3B95AA31, 0x3793, 0x434B, { 0x86, 0x67, 0xC8, 0x07, 0x08, 0x92, 0xE0, 0x5E } }

typedef struct _EFI_IP4_CONFIG_PROTOCOL EFI_IP4_CONFIG_PROTOCOL;

//
// EFI_IP4_IPCONFIG_DATA
//
typedef struct {
    EFI_IPv4_ADDRESS        StationAddress;
    EFI_IPv4_ADDRESS        SubnetMask;
    UINT32                  RouteTableSize;
    EFI_IP4_ROUTE_TABLE     *RouteTable OPTIONAL;
} EFI_IP4_IPCONFIG_DATA;

typedef
EFI_STATUS
(EFIAPI *EFI_IP4_CONFIG_START) (
    IN EFI_IP4_CONFIG_PROTOCOL      *This,
    IN EFI_EVENT                    DoneEvent,
    IN EFI_EVENT                    ReconfigEvent
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP4_CONFIG_STOP) (
    IN EFI_IP4_CONFIG_PROTOCOL      *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_IP4_CONFIG_GET_DATA) (
    IN EFI_IP4_CONFIG_PROTOCOL      *This,
    IN OUT UINTN                    *IpConfigDataSize,
    OUT EFI_IP4_ROUTE_TABLE         *IpConfigData OPTIONAL
);

struct _EFI_IP4_CONFIG_PROTOCOL {
    EFI_IP4_CONFIG_START        Start;
    EFI_IP4_CONFIG_STOP         Stop;
    EFI_IP4_CONFIG_GET_DATA     GetData;
};

#endif // EFI_PROTOCOL_NETWORK_IPV4CONFIGURE_H
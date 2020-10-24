#ifndef EFI_PROTOCOL_HII_CONFIGURATIONROUTING_H
#define EFI_PROTOCOL_HII_CONFIGURATIONROUTING_H

#include <EFI/Types.h>
#include <EFI/Protocol/Path/DevicePath.h>

#define EFI_HII_CONFIG_ROUTING_PROTOCOL_GUID \
    { 0x587E72D7, 0xCC50, 0x4F79, { 0x82, 0x09, 0xCA, 0x29, 0x1F, 0xC1, 0xA1, 0x0F } }

typedef struct _EFI_HII_CONFIG_ROUTING_PROTOCOL EFI_HII_CONFIG_ROUTING_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_HII_EXTRACT_CONFIG) (
    IN CONST EFI_HII_CONFIG_ROUTING_PROTOCOL    *This,
    IN CONST EFI_STRING                         Request,
    OUT EFI_STRING                              *Progress,
    OUT EFI_STRING                              *Results
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_EXPORT_CONFIG) (
    IN CONST EFI_HII_CONFIG_ROUTING_PROTOCOL    *This,
    OUT EFI_STRING                              *Results
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_ROUTE_CONFIG) (
    IN CONST EFI_HII_CONFIG_ROUTING_PROTOCOL    *This,
    IN CONST EFI_STRING                         Configuration,
    OUT EFI_STRING                              *Progress
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_BLOCK_TO_CONFIG) (
    IN CONST EFI_HII_CONFIG_ROUTING_PROTOCOL    *This,
    IN CONST EFI_STRING                         ConfigRequest,
    IN CONST UINT8                              *Block,
    IN CONST UINTN                              BlockSize,
    OUT EFI_STRING                              *Config,
    OUT EFI_STRING                              *Progress
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_CONFIG_TO_BLOCK) (
    IN CONST EFI_HII_CONFIG_ROUTING_PROTOCOL    *This,
    IN CONST EFI_STRING                         *ConfigResp,
    IN OUT CONST UINT8                          *Block,
    IN OUT UINTN                                *BlockSize,
    OUT EFI_STRING                              *Progress
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_GET_ALT_CFG) (
    IN CONST EFI_HII_CONFIG_ROUTING_PROTOCOL    *This,
    IN CONST EFI_STRING                         ConfigResp,
    IN CONST EFI_GUID                           *Guid,
    IN CONST EFI_STRING                         Name,
    IN CONST EFI_DEVICE_PATH_PROTOCOL           *DevicePath,
    IN CONST EFI_STRING                         AltCfgId,
    OUT EFI_STRING                              *AltCfgResp
);

struct _EFI_HII_CONFIG_ROUTING_PROTOCOL {
    EFI_HII_EXTRACT_CONFIG      ExtractConfig;
    EFI_HII_EXPORT_CONFIG       ExportConfig;
    EFI_HII_ROUTE_CONFIG        RouteConfig;
    EFI_HII_BLOCK_TO_CONFIG     BlockToConfig;
    EFI_HII_CONFIG_TO_BLOCK     ConfigToBlock;
    EFI_HII_GET_ALT_CFG         GetAltConfig;
};

#endif // EFI_PROTOCOL_HII_CONFIGURATIONROUTING_H
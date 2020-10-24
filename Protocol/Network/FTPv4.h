#ifndef EFI_PROTOCOL_NETWORK_FTPV4_H
#define EFI_PROTOCOL_NETWORK_FTPV4_H

#include <EFI/Types.h>

#define EFI_FTP4_PROTOCOL_SERVICE_BINDING_PROTOCOL_GUID \
    { 0xFAAECB1, 0x226E, 0x4782, { 0xAA, 0xCE, 0x7D, 0xB9, 0xBC, 0xBF, 0x4D, 0xAF } }

#define EFI_FTP4_PROTOCOL_GUID \
    { 0xEB338826, 0x681B, 0x4295, { 0xB3, 0x56, 0x2B, 0x36, 0x4C, 0x75, 0x7B, 0x09 } }

typedef struct _EFI_FTP4_PROTOCOL EFI_FTP4_PROTOCOL;

//
// EFI_FTP4_CONNECTION_TOKEN
//
typedef struct {
    EFI_EVENT       Event;
    EFI_STATUS      Status;
} EFI_FTP4_CONNECTION_TOKEN;

//
// EFI_FTP4_CONFIG_DATA
//
typedef struct {
    UINT8               *Username;
    UINT8               *Password;
    BOOLEAN             Active;
    BOOLEAN             UseDefaultSetting;
    EFI_IPv4_ADDRESS    StationIp;
    EFI_IPv4_ADDRESS    SubnetMask;
    EFI_IPv4_ADDRESS    GatewayIp;
    EFI_IPv4_ADDRESS    ServerIp;
    UINT16              ServerPort;
    UINT16              AltDataPort;
    UINT8               RepType;
    UINT8               FileStruct;
    UINT8               TransMode;
} EFI_FTP4_CONFIG_DATA;

typedef
EFI_STATUS
(EFIAPI *EFI_FTP4_DATA_CALLBACK) (
    IN EFI_FTP4_PROTOCOL        *This,
    IN EFI_FTP4_COMMAND_TOKEN   *Token
);


//
// EFI_FTP4_COMMAND_TOKEN
//
typedef struct {
    EFI_EVENT               Event;
    UINT8                   *Pathname;
    UINT64                  DataBufferSize;
    VOID                    *DataBuffer;
    EFI_FTP4_DATA_CALLBACK  *DataCallback;
    VOID                    *Context;
    EFI_STATUS              Status;
} EFI_FTP4_COMMAND_TOKEN;

typedef
EFI_STATUS
(EFIAPI *EFI_FTP4_GET_MODE_DATA) (
    IN EFI_FTP4_PROTOCOL        *This,
    OUT EFI_FTP4_CONFIG_DATA    *ModeData
);

typedef
EFI_STATUS
(EFIAPI *EFI_FTP4_CONNECT) (
    IN EFI_FTP4_PROTOCOL            *This,
    IN EFI_FTP4_CONNECTION_TOKEN    *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_FTP4_CLOSE) (
    IN EFI_FTP4_PROTOCOL            *This,
    IN EFI_FTP4_CONNECTION_TOKEN    *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_FTP4_CONFIGURE) (
    IN EFI_FTP4_PROTOCOL        *This,
    OUT EFI_FTP4_CONFIG_DATA    *FtpConfigData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_FTP4_READ_FILE) (
    IN EFI_FTP4_PROTOCOL        *This,
    IN EFI_FTP4_COMMAND_TOKEN   *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_FTP4_WRITE_FILE) (
    IN EFI_FTP4_PROTOCOL        *This,
    IN EFI_FTP4_COMMAND_TOKEN   *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_FTP4_READ_DIRECTORY) (
    IN EFI_FTP4_PROTOCOL        *This,
    IN EFI_FTP4_COMMAND_TOKEN   *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_FTP4_POLL) (
    IN EFI_FTP4_PROTOCOL        *This
);

struct _EFI_FTP4_PROTOCOL {
    EFI_FTP4_GET_MODE_DATA      GetModeData;
    EFI_FTP4_CONNECT            Connect;
    EFI_FTP4_CLOSE              Close;
    EFI_FTP4_CONFIGURE          Configure;
    EFI_FTP4_READ_FILE          ReadFile;
    EFI_FTP4_WRITE_FILE         WriteFile;
    EFI_FTP4_READ_DIRECTORY     ReadDirectory;
    EFI_FTP4_POLL               Poll;
};

#endif // EFI_PROTOCOL_NETWORK_FTPV4_H
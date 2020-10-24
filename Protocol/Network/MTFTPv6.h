#ifndef EFI_PROTOCOL_NETWORK_MTFTPV6_H
#define EFI_PROTOCOL_NETWORK_MTFTPV6_H

#include <EFI/Types.h>

#define EFI_MTFTP6_SERVICE_BINDING_PROTOCOL_GUID \
    { 0xD9760FF3, 0x3CCA, 0x4267, { 0x80, 0xF9, 0x75, 0x27, 0xFA, 0xFA, 0x42, 0x23 } }

#define EFI_MTFTP6_PROTOCOL_GUID \
    { 0xBF0A78BA, 0xEC29, 0x49CF, { 0xA1, 0xC9, 0x7A, 0xE5, 0x4E, 0xAB, 0x6A, 0x51 } }

typedef struct _EFI_MTFTP6_PROTOCOL EFI_MTFTP6_PROTOCOL;

//
// EFI_MTFTP6_CONFIG_DATA
//
typedef struct {
    EFI_IPv6_ADDRESS    StationIp;
    UINT16              LocalPort;
    EFI_IPv6_ADDRESS    ServerIp;
    UINT16              InitialServerPort;
    UINT16              TryCount;
    UINT16              TimeoutValue;
} EFI_MTFTP6_CONFIG_DATA;

//
// EFI_MTFTP6_MODE_DATA
//
typedef struct {
    EFI_MTFTP6_CONFIG_DATA      ConfigData;
    UINT8                       SupportedOptionCount;
    UINT8                       **SupportedOptions;
} EFI_MTFTP6_MODE_DATA;
//
// EFI_MTFTP6_OVERRIDE_DATA
//
typedef struct {
    EFI_IPv6_ADDRESS    GatewayIp;
    UINT16              ServerPort;
    UINT16              TryCount;
    UINT16              TimeoutValue;
} EFI_MTFTP6_OVERRIDE_DATA;

//
// EFI_MTFTP6_OPTION
//
typedef struct {
    UINT8   *OptionStr;
    UINT8   *ValueStr;
} EFI_MTFTP6_OPTION;

#pragma pack(1)
//
// EFI_MTFTP6_REQ_HEADER
//
typedef struct {
    UINT16  OpCode;
    UINT8   Filename[1];
} EFI_MTFTP6_REQ_HEADER;

//
// EFI_MTFTP6_OACK_HEADER
//
typedef struct {
    UINT16  Opcode;
    UINT8   Data[1];
} EFI_MTFTP6_OACK_HEADER;

//
// EFI_MTFTP6_DATA_HEADER
//
typedef struct {
    UINT16  OpCode;
    UINT16  Block;
    UINT8   Data[1];
} EFI_MTFTP6_DATA_HEADER;

//
// EFI_MTFTP6_ACK_HEADER
//
typedef struct {
    UINT16  OpCode;
    UINT8   Block[1];
} EFI_MTFTP6_ACK_HEADER;

//
// EFI_MTFTP6_DATA8_HEADER
// This field should be ignored and treated as reserved
//
typedef struct {
    UINT16  OpCode;
    UINT64  Block;
    UINT8   Data[1];
} EFI_MTFTP6_DATA8_HEADER;

//
// EFI_MTFTP8_ACK8_HEADER
// This field should be ignored and treated as reserved
//
typedef struct {
    UINT16  OpCode;
    UINT64  Block[1];
} EFI_MTFTP8_ACK8_HEADER;

//
// EFI_MTFTP6_ERROR_HEADER
//
typedef struct {
    UINT16  OpCode;
    UINT16  ErrorCode;
    UINT8   ErrorMessage[1];
} EFI_MTFTP6_ERROR_HEADER;

//
// EFI_MTFTP6_PACKET
//
typedef union {
    UINT16                  OpCode;
    EFI_MTFTP6_REQ_HEADER   Rrq, Wrq;
    EFI_MTFTP6_OACK_HEADER  Oack;
    EFI_MTFTP6_DATA_HEADER  Data;
    EFI_MTFTP6_ACK_HEADER   Ack;
    // This field should be ignored and treated as reserved
    EFI_MTFTP6_DATA8_HEADER Data8;
    // This field should be ignored and treated as reserved
    EFI_MTFTP8_ACK8_HEADER  Ack8;
    EFI_MTFTP6_ERROR_HEADER Error;
} EFI_MTFTP6_PACKET;
#pragma pack()

//
// MTFTP Packet OpCodes
#define EFI_MTFTP6_OPCODE_RRQ       (1)
#define EFI_MTFTP6_OPCODE_WRQ       (2)
#define EFI_MTFTP6_OPCODE_DATA      (3)
#define EFI_MTFTP6_OPCODE_ACK       (6)
#define EFI_MTFTP6_OPCODE_ERROR     (5)
#define EFI_MTFTP6_OPCODE_OACK      (6)
#define EFI_MTFTP6_OPCODE_DIR       (7)
// This field should be ignored and treated as reserved
#define EFI_MTFTP6_OPCODE_DATA8     (8)
// This field should be ignored and treated as reserved
#define EFI_MTFTP6_OPCODE_ACK8      (9)

//
// MTFTP ERROR Packet ErrorCodes
#define EFI_MTFTP6_ERRORCODE_NOT_DEFINED            (0)
#define EFI_MTFTP6_ERRORCODE_FILE_NOT_FOUND         (1)
#define EFI_MTFTP6_ERRORCODE_ACCESS_VIOLATION       (2)
#define EFI_MTFTP6_ERRORCODE_DISK_FULL              (3)
#define EFI_MTFTP6_ERRORCODE_ILLEGAL_OPERATION      (6)
#define EFI_MTFTP6_ERRORCODE_UNKNOWN_TRANSFER_ID    (5)
#define EFI_MTFTP6_ERRORCODE_FILE_ALREADY_EXISTS    (6)
#define EFI_MTFTP6_ERRORCODE_NO_SUCH_USER           (7)
#define EFI_MTFTP6_ERRORCODE_REQUEST_DENIED         (8)

typedef struct _EFI_MTFTP6_TOKEN EFI_MTFTP6_TOKEN;

typedef
EFI_STATUS
(EFIAPI *EFI_MTFTP6_CHECK_PACKET) (
    IN EFI_MTFTP6_PROTOCOL      *This,
    IN EFI_MTFTP6_TOKEN         *Token,
    IN UINT16                   PacketLen,
    IN EFI_MTFTP6_PACKET        *Packet
);

typedef
EFI_STATUS
(EFIAPI *EFI_MTFTP6_TIMEOUT_CALLBACK) (
    IN EFI_MTFTP6_PROTOCOL      *This,
    IN EFI_MTFTP6_TOKEN         *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_MTFTP6_PACKET_NEEDED) (
    IN EFI_MTFTP6_PROTOCOL      *This,
    IN EFI_MTFTP6_TOKEN         *Token,
    IN OUT UINT16               *Length,
    OUT VOID                    **Buffer
);

//
// EFI_MTFTP6_TOKEN
//
struct _EFI_MTFTP6_TOKEN {
    EFI_STATUS                      Status;
    EFI_EVENT                       Event;
    EFI_MTFTP6_OVERRIDE_DATA        *OverrideData;
    UINT8                           *Filename;
    UINT8                           *ModeStr;
    UINT32                          OptionCount;
    EFI_MTFTP6_OPTION               *OptionList;
    UINT64                          BufferSize;
    VOID                            *Buffer;
    VOID                            *Context;
    EFI_MTFTP6_CHECK_PACKET         CheckPacket;
    EFI_MTFTP6_TIMEOUT_CALLBACK     TimeoutCallback;
    EFI_MTFTP6_PACKET_NEEDED        PacketNeeded;
};

typedef
EFI_STATUS
(EFIAPI *EFI_MTFTP6_GET_MODE_DATA) (
    IN EFI_MTFTP6_PROTOCOL      *This,
    OUT EFI_MTFTP6_MODE_DATA    *ModeData
);

typedef
EFI_STATUS
(EFIAPI *EFI_MTFTP6_CONFIGURE) (
    IN EFI_MTFTP6_PROTOCOL      *This,
    IN EFI_MTFTP6_CONFIG_DATA   *MtftpConfigData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_MTFTP6_GET_INFO) (
    IN EFI_MTFTP6_PROTOCOL      *This,
    IN EFI_MTFTP6_OVERRIDE_DATA *OverrideData, OPTIONAL
    IN UINT8                    *Filename,
    IN UINT8                    *ModeStr, OPTIONAL
    IN UINT8                    OptionCount,
    IN EFI_MTFTP6_OPTION        *OptionList, OPTIONAL
    OUT UINT32                  *PacketLength,
    OUT EFI_MTFTP6_PACKET       **Packet OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_MTFTP6_PARSE_OPTIONS) (
    IN EFI_MTFTP6_PROTOCOL      *This,
    IN UINT32                   PacketLen,
    IN EFI_MTFTP6_PACKET        *Packet,
    OUT UINT32                  *OptionCount,
    OUT EFI_MTFTP6_OPTION       **OptionList OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_MTFTP6_READ_FILE) (
    IN EFI_MTFTP6_PROTOCOL      *This,
    IN EFI_MTFTP6_TOKEN         *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_MTFTP6_WRITE_FILE) (
    IN EFI_MTFTP6_PROTOCOL      *This,
    IN EFI_MTFTP6_TOKEN         *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_MTFTP6_READ_DIRECTORY) (
    IN EFI_MTFTP6_PROTOCOL      *This,
    IN EFI_MTFTP6_TOKEN         *Token
);

typedef
EFI_STATUS
(EFIAPI *EFI_MTFTP6_POLL) (
    IN EFI_MTFTP6_PROTOCOL      *This
);

struct _EFI_MTFTP6_PROTOCOL {
    EFI_MTFTP6_GET_MODE_DATA        GetModeData;
    EFI_MTFTP6_CONFIGURE            Configure;
    EFI_MTFTP6_GET_INFO             GetInfo;
    EFI_MTFTP6_PARSE_OPTIONS        ParseOptions;
    EFI_MTFTP6_READ_FILE            ReadFile;
    EFI_MTFTP6_WRITE_FILE           WriteFile;
    EFI_MTFTP6_READ_DIRECTORY       ReadDirectory;
    EFI_MTFTP6_POLL                 Poll;
};

#endif // EFI_PROTOCOL_NETWORK_MTFTPV6_H
#ifndef EFI_PROTOCOL_SECURE_KMS_H
#define EFI_PROTOCOL_SECURE_KMS_H

#include <EFI/Types.h>

#define EFI_KMS_PROTOCOL_GUID \
    { 0xEC3A978D, 0x7C4E, 0x48FA, { 0x9A, 0xBE, 0x6A, 0xD9, 0x1C, 0xC8, 0xF8, 0x11 } }

typedef struct _EFI_KMS_SERVICE_PROTOCOL EFI_KMS_PROTOCOL;

#define EFI_KMS_DATA_TYPE_NONE      (0)
#define EFI_KMS_DATA_TYPE_BINARY    (1)
#define EFI_KMS_DATA_TYPE_ASCII     (2)
#define EFI_KMS_DATA_TYPE_UNICODE   (4)
#define EFI_KMS_DATA_TYPE_UTF8      (8)

//
// EFI_KMS_CLIENT_INFO
//
typedef struct {
    UINT16      ClientIdSize;
    VOID        *ClientId;
    UINT8       ClientNameType;
    UINT8       ClientNameCount;
    VOID        *ClientName;
} EFI_KMS_CLIENT_INFO;

//
// Generic key data
//
#define EFI_KMS_FORMAT_GENERIC_128_GUID \
    { 0xEC8A3D69, 0x6DDF, 0x4108, { 0x94, 0x76, 0x73, 0x37, 0xFC, 0x52, 0x21, 0x36 } }

#define EFI_KMS_FORMAT_GENERIC_160_GUID \
    { 0xA3B3E6F8, 0xEFCA, 0x4BC1, { 0x88, 0xFB, 0xCB, 0x87, 0x33, 0x9B, 0x25, 0x79 } }

#define EFI_KMS_FORMAT_GENERIC_256_GUID \
    { 0x70F64793, 0xC323, 0x4261, { 0xAC, 0x2C, 0xD8, 0x76, 0xF2, 0x7C, 0x53, 0x45 } }

#define EFI_KMS_FORMAT_GENERIC_512_GUID \
    { 0x978FE043, 0xD7AF, 0x422E, { 0x8A, 0x92, 0x2B, 0x48, 0xE4, 0x63, 0xBD, 0xE6 } }

#define EFI_KMS_FORMAT_GENERIC_1024_GUID \
    { 0x43BE0B44, 0x874B, 0x4EAD, { 0xB0, 0x9C, 0x24, 0x1A, 0x4F, 0xBD, 0x7E, 0xB3 } }

#define EFI_KMS_FORMAT_GENERIC_2048_GUID \
    { 0x40093F23, 0x630C, 0x4626, { 0x9C, 0x48, 0x40, 0x37, 0x3B, 0x19, 0xCB, 0xBE } }

#define EFI_KMS_FORMAT_GENERIC_3072_GUID \
    { 0xB9237513, 0x6C44, 0x4411, { 0xA9, 0x90, 0x21, 0xE5, 0x56, 0xE0, 0x5A, 0xDE } }

//
// Hash key data
//
#define EFI_KMS_FORMAT_MD2_128_GUID \
    { 0x78BE11C4, 0xEE44, 0x4A22, { 0x9F, 0x05, 0x03, 0x85, 0x2E, 0xC5, 0xC9, 0x78 } }

#define EFI_KMS_FORMAT_MDC2_128_GUID \
    { 0xF7AD60F8, 0xEFA8, 0x44A3, { 0x91, 0x13, 0x23, 0x1F, 0x39, 0x9E, 0xB4, 0xC7 } }

#define EFI_KMS_FORMAT_MD4_128_GUID \
    { 0xD1C17AA1, 0xCAC5, 0x400F, { 0xBE, 0x17, 0xE2, 0xA2, 0xAE, 0x06, 0x67, 0x7C } }

#define EFI_KMS_FORMAT_MDC4_128_GUID \
    { 0x3FA4F847, 0xD8EB, 0x4DF4, { 0xBD, 0x49, 0x10, 0x3A, 0x0A, 0x8A, 0x7B, 0xBC } }

#define EFI_KMS_FORMAT_MD5_128_GUID \
    { 0xDCBC3662, 0x9CDA, 0x4B52, { 0xA0, 0x4C, 0x82, 0xEB, 0x1D, 0x23, 0x48, 0xC7 } }

#define EFI_KMS_FORMAT_MD5SHA_128_GUID \
    { 0x1C178237, 0x6897, 0x459E, { 0x9D, 0x36, 0x67, 0xCE, 0x8E, 0xF9, 0x4F, 0x76 } }

#define EFI_KMS_FORMAT_SHA1_160_GUID \
    { 0x453C5E5A, 0x482D, 0x43F0, { 0x87, 0xC9, 0x59, 0x41, 0xF3, 0xA3, 0x8A, 0xC2 } }

#define EFI_KMS_FORMAT_SHA256_256_GUID \
    { 0x6BB4F5CD, 0x8022, 0x448D, { 0xBC, 0x6D, 0x77, 0x1B, 0xAE, 0x93, 0x5F, 0xC6 } }

#define EFI_KMS_FORMAT_SHA512_512_GUID \
    { 0x2F240E12, 0xE14D, 0x475C, { 0x83, 0xB0, 0xEF, 0xFF, 0x22, 0xD7, 0x7B, 0xE7 } }

//
// Encryption algorithm key data
//
#define EFI_KMS_FORMAT_AESXTS_128_GUID \
    { 0x4776E33F, 0xDB47, 0x479A, { 0xA2, 0x5F, 0xA1, 0xCD, 0x0A, 0xFA, 0xB3, 0x8B } }

#define EFI_KMS_FORMAT_AESXTS_256_GUID \
    { 0xDC7E8613, 0xC4BB, 0x4DB0, { 0x84, 0x62, 0x13, 0x51, 0x13, 0x57, 0xAB, 0xE2 } }

#define EFI_KMS_FORMAT_AESCBC_128_GUID \
    { 0xA0E8EE6A, 0x0E92, 0x44D4, { 0x86, 0x1B, 0x0E, 0xAA, 0x4A, 0xCA, 0x44, 0xA2 } }

#define EFI_KMS_FORMAT_AESCBC_256_GUID \
    { 0xD7E69789, 0x1F68, 0x45E8, { 0x96, 0xEF, 0x3B, 0x64, 0x07, 0xA5, 0xB2, 0xDC } }

#define EFI_KMS_FORMAT_RSASHA1_1024_GUID \
    { 0x56417BED, 0x6BBE, 0x4882, { 0x86, 0xA0, 0x3A, 0xE8, 0xBB, 0x17, 0xF8, 0xF9} }

#define EFI_KMS_FORMAT_RSASHA1_2048_GUID \
    { 0xF66447D4, 0x75A6, 0x463E, { 0xA8, 0x19, 0x07, 0x7F, 0x2D, 0xDA, 0x05, 0xE9 } }

#define EFI_KMS_FORMAT_RSASHA256_2048_GUID \
    { 0xA477AF13, 0x877D, 0x4060, { 0xBA, 0xA1, 0x25, 0xD1, 0xBE, 0xA0, 0x8A, 0xD3 } }

#define EFI_KMS_FORMAT_RSASHA256_3072_GUID \
    { 0x4E1356C2, 0x0EED, 0x463F, { 0x81, 0x47, 0x99, 0x33, 0xAB, 0xDB, 0xC7, 0xD5 } }

//
// EFI_KMS_KEY_DESCRIPTOR
//
typedef struct {
    UINT8       KeyIdentifierSize;
    VOID        *KeyIdentifier;
    EFI_GUID    KeyFormat;
    VOID        *KeyValue;
    EFI_STATUS  KeyStatus;
} EFI_KMS_KEY_DESCRIPTOR;

//
// EFI_KMS_ATTRIBUTE_TYPE
//
#define EFI_KMS_ATTRIBUTE_TYPE_NONE         (0x00)
#define EFI_KMS_ATTRIBUTE_TYPE_INTEGER      (0x01)
#define EFI_KMS_ATTRIBUTE_TYPE_LONG_INTEGER (0x02)
#define EFI_KMS_ATTRIBUTE_TYPE_BIG_INTEGER  (0x03)
#define EFI_KMS_ATTRIBUTE_TYPE_ENUMERATION  (0x04)
#define EFI_KMS_ATTRIBUTE_TYPE_BOOLEAN      (0x05)
#define EFI_KMS_ATTRIBUTE_TYPE_BYTE_STRING  (0x06)
#define EFI_KMS_ATTRIBUTE_TYPE_TEXT_STRING  (0x07)
#define EFI_KMS_ATTRIBUTE_TYPE_DATE_TIME    (0x08)
#define EFI_KMS_ATTRIBUTE_TYPE_INTERVAL     (0x09)
#define EFI_KMS_ATTRIBUTE_TYPE_STRUCTURE    (0x0A)
#define EFI_KMS_ATTRIBUTE_TYPE_DYNAMIC      (0x0B)

//
// EFI_KMS_DYNAMIC_FIELD
//
typedef struct {
    UINT16      Tag;
    UINT16      Type;
    UINT32      Length;
    UINT8       KeyAttributeData[1];
} EFI_KMS_DYNAMIC_FIELD;

//
// EFI_KMS_DYNAMIC_ATTRIBUTE
//
typedef struct {
    UINT32                  FieldCount;
    EFI_KMS_DYNAMIC_FIELD   Field[1];
} EFI_KMS_DYNAMIC_ATTRIBUTE;

//
// EFI_KMS_KEY_ATTRIBUTE
//
typedef struct {
    UINT8       KeyAttributeIdentifierType;
    UINT8       KeyAttributeIdentifierCount;
    VOID        *KeyAttributeIdentifier;
    UINT16      KeyAttributeInstance;
    UINT16      KeyAttributeType;
    UINT16      KeyAttributeValueSize;
    VOID*       KeyAttributeValue;
    EFI_STATUS  KeyAttributeStatus;
} EFI_KMS_KEY_ATTRIBUTE;

typedef
EFI_STATUS
(EFIAPI *EFI_KMS_GET_SERVICE_STATUS) (
    IN EFI_KMS_PROTOCOL             *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_KMS_REGISTER_CLIENT) (
    IN EFI_KMS_PROTOCOL             *This,
    IN EFI_KMS_CLIENT_INFO          *Client,
    IN OUT UINTN                    *ClientDataSize, OPTIONAL
    IN OUT VOID                     **ClientData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_KMS_CREATE_KEY) (
    IN EFI_KMS_PROTOCOL             *This,
    IN EFI_KMS_CLIENT_INFO          *Client,
    IN OUT UINT16                   *KeyDescriptorCount,
    IN OUT EFI_KMS_KEY_DESCRIPTOR   *KeyDescriptors,
    IN OUT UINTN                    *ClientDataSize, OPTIONAL
    IN OUT VOID                     **ClientData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_KMS_GET_KEY) (
    IN EFI_KMS_PROTOCOL             *This,
    IN EFI_KMS_CLIENT_INFO          *Client,
    IN OUT UINT16                   *KeyDescriptorCount,
    IN OUT EFI_KMS_KEY_DESCRIPTOR   *KeyDescriptors,
    IN OUT UINTN                    *ClientDataSize, OPTIONAL
    IN OUT VOID                     **ClientData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_KMS_ADD_KEY) (
    IN EFI_KMS_PROTOCOL             *This,
    IN EFI_KMS_CLIENT_INFO          *Client,
    IN OUT UINT16                   *KeyDescriptorCount,
    IN OUT EFI_KMS_KEY_DESCRIPTOR   *KeyDescriptors,
    IN OUT UINTN                    *ClientDataSize, OPTIONAL
    IN OUT VOID                     **ClientData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_KMS_DELETE_KEY) (
    IN EFI_KMS_PROTOCOL             *This,
    IN EFI_KMS_CLIENT_INFO          *Client,
    IN OUT UINT16                   *KeyDescriptorCount,
    IN OUT EFI_KMS_KEY_DESCRIPTOR   *KeyDescriptors,
    IN OUT UINTN                    *ClientDataSize, OPTIONAL
    IN OUT VOID                     **ClientData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_KMS_GET_KEY_ATTRIBUTES) (
    IN EFI_KMS_PROTOCOL             *This,
    IN EFI_KMS_CLIENT_INFO          *Client,
    IN UINT8                        *KeyIdentifierSize,
    IN CONST VOID                   *KeyIdentifier,
    IN OUT UINT16                   *KeyAttributesCount,
    IN OUT EFI_KMS_KEY_ATTRIBUTE    *KeyAttributes,
    IN OUT UINTN                    *ClientDataSize, OPTIONAL
    IN OUT VOID                     **ClientData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_KMS_ADD_KEY_ATTRIBUTES) (
    IN EFI_KMS_PROTOCOL             *This,
    IN EFI_KMS_CLIENT_INFO          *Client,
    IN UINT8                        *KeyIdentifierSize,
    IN CONST VOID                   *KeyIdentifier,
    IN OUT UINT16                   *KeyAttributesCount,
    IN OUT EFI_KMS_KEY_ATTRIBUTE    *KeyAttributes,
    IN OUT UINTN                    *ClientDataSize, OPTIONAL
    IN OUT VOID                     **ClientData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_KMS_DELETE_KEY_ATTRIBUTES) (
    IN EFI_KMS_PROTOCOL             *This,
    IN EFI_KMS_CLIENT_INFO          *Client,
    IN UINT8                        *KeyIdentifierSize,
    IN CONST VOID                   *KeyIdentifier,
    IN OUT UINT16                   *KeyAttributesCount,
    IN OUT EFI_KMS_KEY_ATTRIBUTE    *KeyAttributes,
    IN OUT UINTN                    *ClientDataSize, OPTIONAL
    IN OUT VOID                     **ClientData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_KMS_GET_KEY_BY_ATTRIBUTES) (
    IN EFI_KMS_PROTOCOL             *This,
    IN EFI_KMS_CLIENT_INFO          *Client,
    IN OUT UINTN                    *KeyAttributesCount,
    IN OUT EFI_KMS_KEY_ATTRIBUTE    *KeyAttributes,
    IN OUT UINTN                    *KeyDescriptorCount,
    IN OUT EFI_KMS_KEY_DESCRIPTOR   *KeyDescriptors,
    IN OUT UINTN                    *ClientDataSize, OPTIONAL
    IN OUT VOID                     **ClientData OPTIONAL
);

struct _EFI_KMS_SERVICE_PROTOCOL {
    EFI_KMS_GET_SERVICE_STATUS      GetServiceStatus;
    EFI_KMS_REGISTER_CLIENT         RegisterCilent;
    EFI_KMS_CREATE_KEY              CreateKey;
    EFI_KMS_GET_KEY                 GetKey;
    EFI_KMS_ADD_KEY                 AddKey;
    EFI_KMS_DELETE_KEY              DeleteKey;
    EFI_KMS_GET_KEY_ATTRIBUTES      GetKeyAttributes;
    EFI_KMS_ADD_KEY_ATTRIBUTES      AddKeyAttributes;
    EFI_KMS_DELETE_KEY_ATTRIBUTES   DeleteKeyAttributes;
    EFI_KMS_GET_KEY_BY_ATTRIBUTES   GetKeyByAttributes;
    UINT32                          ProtocolVersion;
    EFI_GUID                        ServiceId;
    CHAR16                          *ServiceName;
    UINT32                          ServiceVersion;
    BOOLEAN                         ServiceAvailable;
    BOOLEAN                         ClientIdSupported;
    BOOLEAN                         ClientIdRequired;
    UINT16                          ClientIdMaxSize;
    UINT8                           ClientNameStringTypes;
    BOOLEAN                         ClientNameRequired;
    UINT16                          ClientNameMaxCount;
    BOOLEAN                         ClientDataSupported;
    UINTN                           ClientDataMaxSize;
    BOOLEAN                         KeyIdVariableLenSupported;
    UINTN                           KeyIdMaxSize;
    UINTN                           KeyFormatsCount;
    EFI_GUID                        *KeyFormats;
    BOOLEAN                         KeyAttributesSupported;
    UINT8                           KeyAttributeIdStringTypes;
    UINT16                          KeyAttributeIdMaxCount;
    UINTN                           KeyAttributesCount;
    EFI_KMS_KEY_ATTRIBUTE           *KeyAttributes;
};

#endif // EFI_PROTOCOL_SECURE_KMS_H
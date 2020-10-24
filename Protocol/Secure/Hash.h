#ifndef EFI_PROTOCOL_SECURE_HASH_H
#define EFI_PROTOCOL_SECURE_HASH_H

#include <EFI/Types.h>

#define EFI_HASH_SERVICE_BINDING_PROTOCOL_GUID \
    { 0x42881C98, 0xA4F3, 0x44B0, { 0xA3, 0x9D, 0xDF, 0xA1, 0x86, 0x67, 0xD8, 0xCD } }

#define EFI_HASH_PROTOCOL_GUID \
    { 0xC5184932, 0xDBA5, 0x46DB, { 0xA5, 0xBA, 0xCC, 0x0B, 0xDA, 0x9C, 0x14, 0x35 } }

typedef struct _EFI_HASH_PROTOCOL EFI_HASH_PROTOCOL;

typedef UINT8 EFI_MD5_HASH[16];
typedef UINT8 EFI_SHA1_HASH[20];
typedef UINT8 EFI_SHA224_HASH[28];
typedef UINT8 EFI_SHA256_HASH[32];
typedef UINT8 EFI_SHA384_HASH[48];
typedef UINT8 EFI_SHA512_HASH[64];

//
// EFI_HASH_OUTPUT
//
typedef union {
    EFI_MD5_HASH        *Md5Hash;
    EFI_SHA1_HASH       *Sha1Hash;
    EFI_SHA224_HASH     *Sha224Hash;
    EFI_SHA256_HASH     *Sha256Hash;
    EFI_SHA384_HASH     *Sha384Hash;
    EFI_SHA512_HASH     *Sha512Hash;
} EFI_HASH_OUTPUT;

//
// DEPRECATED ALGORITHMS
//
#define EFI_HASH_ALGORITHM_SHA1_GUID \
    { 0x2AE9D80F, 0x3FB2, 0x4095, { 0xB7, 0xB1, 0xE9, 0x31, 0x57, 0xB9, 0x46, 0xB6 } }

#define EFI_HASH_ALGORITHM_SHA224_GUID \
    { 0x8DF01A06, 0x9BD5, 0x4BF7, { 0xB0, 0x21, 0xDB, 0x4F, 0xD9, 0xCC, 0xF4, 0x5B } }

#define EFI_HASH_ALGORITHM_SHA256_GUID \
    { 0x51AA59DE, 0xFDF2, 0x4EA3, { 0xBC, 0x63, 0x87, 0x5F, 0xB7, 0x84, 0x2E, 0xE9 } }

#define EFI_HASH_ALGORITHM_SHA384_GUID \
    { 0xEFA96432, 0xDE33, 0x4DD2, { 0xAE, 0xE6, 0x32, 0x8C, 0x33, 0xDF, 0x77, 0x7A } }

#define EFI_HASH_ALGORITHM_SHA512_GUID \
    { 0xCAA4381E, 0x750C, 0x4770, { 0xB8, 0x70, 0x7A, 0x23, 0xB4, 0xE4, 0x21, 0x30 } }

#define EFI_HASH_ALGORITHM_MD5_GUID \
    { 0xAF7C79C, 0x65B5, 0x4319, { 0xB0, 0xAE, 0x44, 0xEC, 0x48, 0x4E, 0x4A, 0xD7 } }
// END DEPRECATED ALGORITHMS

#define EFI_HASH_ALGORITHM_SHA1_NOPAD_GUID \
    { 0x24C5DC2F, 0x53E2, 0x40CA, { 0x9E, 0xD6, 0xA5, 0xD9, 0xA4, 0x9F, 0x46, 0x3B } }

#define EFI_HASH_ALGORITHM_SHA256_NOPAD_GUID \
    { 0x8628752A, 0x6CB7, 0x4814, { 0x96, 0xFC, 0x24, 0xA8, 0x15, 0xAC, 0x22, 0x26 } }

typedef
EFI_STATUS
(EFIAPI *EFI_HASH_GET_HASH_SIZE) (
    IN CONST EFI_HASH_PROTOCOL  *This,
    IN CONST EFI_GUID           *HashAlgorithm,
    OUT UINTN                   *HashSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_HASH_HASH) (
    IN CONST EFI_HASH_PROTOCOL  *This,
    IN CONST EFI_GUID           *HashAlgorithm,
    IN BOOLEAN                  Extend,
    IN CONST CHAR8              *Message,
    IN UINT64                   MessageSize,
    IN OUT EFI_HASH_OUTPUT      *HashSize
);

struct _EFI_HASH_PROTOCOL {
    EFI_HASH_GET_HASH_SIZE      GetHashSize;
    EFI_HASH_HASH               Hash;
};

#endif // EFI_PROTOCOL_SECURE_HASH_H
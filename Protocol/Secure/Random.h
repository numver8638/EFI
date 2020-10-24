#ifndef EFI_PROTOCOL_SECURE_RANDOM_H
#define EFI_PROTOCOL_SECURE_RANDOM_H

#include <EFI/Types.h>

#define EFI_RNG_PROTOCOL_GUID \
    { 0x3152BCA5, 0xEADE, 0x433D, { 0x86, 0x2E, 0xC0, 0x1C, 0xDC, 0x29, 0x1F, 0x44 } }

typedef struct _EFI_RNG_PROTOCOL EFI_RNG_PROTOCOL;

typedef EFI_GUID EFI_RNG_ALGORITHM;

#define EFI_RNG_ALGORITHM_SP800_90_HASH_256_GUID \
    { 0xA7AF67CB, 0x603B, 0x4D42, { 0xBA, 0x21, 0x70, 0xBF, 0xB6, 0x29, 0x3F, 0x96 } }

#define EFI_RNG_ALGORITHM_SP800_90_HMAC_256_GUID \
    { 0xC5149B43, 0xAE85, 0x4F53, { 0x99, 0x82, 0xB9, 0x43, 0x35, 0xD3, 0xA9, 0xE7 } }

#define EFI_RNG_ALGORITHM_SP800_90_CTR_256_GUID \
    { 0x44F0DE6E, 0x4D8C, 0x4045, { 0xA8, 0xC7, 0x4D, 0xD1, 0x68, 0x85, 0x6B, 0x9E } }

#define EFI_RNG_ALGORITHM_X9_31_3DES_GUID \
    { 0x63C4785A, 0xCA34, 0x4012, { 0xA3, 0xC8, 0x0B, 0x6A, 0x32, 0x4F, 0x55, 0x46 } }

#define EFI_RNG_ALGORITHM_X9_31_AES_GUID \
    { 0xACD03321, 0x777E, 0x4D3D, { 0xB1, 0xC8, 0x20, 0xCF, 0xD8, 0x88, 0x20, 0xC9 } }

#define EFI_RNG_ALGORITHM_RAW \
    { 0xE43176D7, 0xB6E8, 0x4827, { 0xB7, 0x84, 0x7F, 0xFD, 0xC4, 0xB6, 0x85, 0x61 } }

typedef
EFI_STATUS
(EFIAPI *EFI_RNG_GET_INFO) (
    IN EFI_RNG_PROTOCOL     *This,
    IN OUT UINTN            *RNGAlgorithmListSize,
    OUT EFI_RNG_ALGORITHM   *RNGAlgorithmList
);

typedef
EFI_STATUS
(EFIAPI *EFI_RNG_GET_RNG) (
    IN EFI_RNG_PROTOCOL     *This,
    IN EFI_RNG_ALGORITHM    *RNGAlgorithm, OPTIONAL
    IN UINTN                RNGValueLength,
    OUT UINT8               *RNGValue
);

struct _EFI_RNG_PROTOCOL {
    EFI_RNG_GET_INFO    GetInfo;
    EFI_RNG_GET_RNG     GetRNG;
};

#endif // EFI_PROTOCOL_SECURE_RANDOM_H
#ifndef EFI_PROTOCOL_SECUREBOOT_CERTIFICATE_H
#define EFI_PROTOCOL_SECUREBOOT_CERTIFICATE_H

#include <EFI/Types.h>
#include <EFI/Protocol/Secure/Hash.h>

//
// WIN_CERTIFICATE
//
typedef struct _WIN_CERTIFICATE {
    UINT32      dwLength;
    UINT16      wRevision;
    UINT16      wCertificateType;
    // UINT8    bCertificate[ANYSIZE_ARRAY];
} WIN_CERTIFICATE;

#define WIN_CERT_TYPE_PKCS_SIGNED_DATA  (0x0002)
#define WIN_CERT_TYPE_EFI_PKCS115       (0x0EF0)
#define WIN_CERT_TYPE_EFI_GUID          (0x0EF1)

#define EFI_CERT_TYPE_RSA2048_SHA256_GUID \
    { 0xA7717414, 0xC616, 0x4977, { 0x94, 0x20, 0x84, 0x47, 0x12, 0xA7, 0x35, 0xBF } }

#define EFI_CERT_TYPE_PKCS7_GUID \
    { 0x4AAFD29D, 0x68DF, 0x49EE, { 0x8A, 0xA9, 0x34, 0x7D, 0x37, 0x56, 0x65, 0xA7 } }

//
// WIN_CERTIFICATE_EFI_PKCS1_15
//
typedef struct _WIN_CERTIFICATE_EFI_PKCS1_15 {
    WIN_CERTIFICATE     Hdr;
    EFI_GUID            HashAlgorithm;
    // UINT8            Signature[ANYSIZE_ARRAY];
} WIN_CERTIFICATE_EFI_PKCS1_15;

//
// WIN_CERTIFICATE_UEFI_GUID
//
typedef struct _WIN_CERTIFICATE_UEFI_GUID {
    WIN_CERTIFICATE     Hdr;
    EFI_GUID            CertType;
    // UINT8            CertData[ANYSIZE_ARRAY];
} WIN_CERTIFICATE_UEFI_GUID;

//
// EFI_CERT_BLOCK_RSA_2048_SHA256
//
typedef struct _EFI_CERT_BLOCK_RSA_2048_SHA256 {
    EFI_GUID        HashType;
    UINT8           PublicKey[256];
    UINT8           Signature[256];
} EFI_CERT_BLOCK_RSA_2048_SHA256;

#pragma pack(1)
//
// EFI_SIGNATURE_DATA
//
typedef struct _EFI_SIGNATURE_DATA {
    EFI_GUID        SignatureOwner;
    // UINT8        SignatureData[ANYSIZE_ARRAY];
} EFI_SIGNATURE_DATA;

//
// EFI_SIGNATURE_LIST
//
typedef struct _EFI_SIGNATURE_LIST {
    EFI_GUID                SignatureType;
    UINT32                  SignatureListSize;
    UINT32                  SignatureHeaderSize;
    UINT32                  SignatureSize;
    // UINT8                SignatureHeader[SignatureHeaderSize];
    // EFI_SIGNATURE_DATA   Signatures[ANYSIZE_ARRAY][SignatureSize]
} EFI_SIGNATURE_LIST;
#pragma pack()

#define EFI_CERT_SHA256_GUID \
    { 0xC1C41626, 0x504C, 0x4092, { 0xAC, 0xA9, 0x41, 0xF9, 0x36, 0x93, 0x43, 0x28 } }

#define EFI_CERT_RSA2048_GUID \
    { 0x3C5766E8, 0x269C, 0x4E34, { 0xAA, 0x14, 0xED, 0x77, 0x6E, 0x85, 0xB3, 0xB6 } }

#define EFI_CERT_RSA2048_SHA256_GUID \
    { 0xE2B36190, 0x879B, 0x4A3D, { 0xAD, 0x8D, 0xF2, 0xE7, 0xBB, 0xA3, 0x27, 0x84 } }

#define EFI_CERT_SHA1_GUID \
    { 0x826CA512, 0xCF10, 0x4AC9, { 0xB1, 0x87, 0xBE, 0x01, 0x49, 0x66, 0x31, 0xBD } }

#define EFI_CERT_RSA2048_SHA1_GUID \
    { 0x67F8444F, 0x8743, 0x48F1, { 0xA3, 0x28, 0x1E, 0xAA, 0xB8, 0x73, 0x60, 0x80 } }

#define EFI_CERT_X509_GUID \
    { 0xA5C059A1, 0x94E4, 0x4AA7, { 0x87, 0xB5, 0xAB, 0x15, 0x5C, 0x2B, 0xF0, 0x72 } }

#define EFI_CERT_SHA224_GUID \
    { 0x0B6E5233, 0xA65C, 0x44C9, { 0x94, 0x07, 0xD9, 0xAB, 0x83, 0xBF, 0xC8, 0xBD } }

#define EFI_CERT_SHA384_GUID \
    { 0xFF3E5307, 0x9FD0, 0x48C9, { 0x85, 0xF1, 0x8A, 0xD5, 0x6C, 0x70, 0x1E, 0x01 } }

#define EFI_CERT_SHA512_GUID \
    { 0x093E0FAE, 0xA6C4, 0x4F50, { 0x9F, 0x1B, 0xD4, 0x1E, 0x2B, 0x89, 0xC1, 0x9A } }

#define EFI_CERT_X509_SHA256_GUID \
    { 0x3BD2A492, 0x96C0, 0x4079, { 0xB4, 0x20, 0xFC, 0xF9, 0x8E, 0xF1, 0x03, 0xED } }

//
// EFI_CERT_X509_SHA256
//
#pragma pack(1)
typedef struct _EFI_CERT_X509_SHA256 {
    EFI_SHA256_HASH     ToBeSignedHash;
    EFI_TIME            TimeOfRevocation;
} EFI_CERT_X509_SHA256;
#pragma pack()

#define EFI_CERT_X509_SHA384_GUID \
    { 0x7076876E, 0x80C2, 0x4EE6, { 0xAA, 0xD2, 0x28, 0xB3, 0x49, 0xA6, 0x86, 0x5B } }

//
// EFI_CERT_X509_SHA384
//
#pragma pack(1)
typedef struct _EFI_CERT_X509_SHA384 {
    EFI_SHA384_HASH     ToBeSignedHash;
    EFI_TIME            TimeOfRevocation;
} EFI_CERT_X509_SHA384;
#pragma pack()

#define EFI_CERT_X509_SHA512_GUID \
    { 0x446DBF63, 0x2502, 0x4CDA, { 0xBC, 0xFA, 0x24, 0x65, 0xD2, 0xB0, 0xFE, 0x9D } }

//
// EFI_CERT_X509_SHA512
//
#pragma pack(1)
typedef struct _EFI_CERT_X509_SHA512 {
    EFI_SHA512_HASH     ToBeSignedHash;
    EFI_TIME            TimeOfRevocation;
} EFI_CERT_X509_SHA512;
#pragma pack()

#endif // EFI_PROTOCOL_SECUREBOOT_CERTIFICATE_H
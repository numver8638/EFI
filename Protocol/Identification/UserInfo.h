#ifndef EFI_PROTOCOL_IDENTIFICATION_USERINFO_H
#define EFI_PROTOCOL_IDENTIFICATION_USERINFO_H

#include <EFI/Types.h>

typedef EFI_HANDLE EFI_USER_PROFILE_HANDLE;
typedef EFI_HANDLE EFI_USER_INFO_HANDLE;

#define EFI_EVENT_GROUP_USER_PROFILE_CHANGED \
    { 0xBAF1E6DE, 0x209E, 0x4ADB, { 0x8D, 0x96, 0xFD, 0x8B, 0x71, 0xF3, 0xF6, 0x83 } }

typedef UINT16 EFI_USER_INFO_ATTRIBS;

#define EFI_USER_INFO_STORAGE               (0x000F)
#define EFI_USER_INFO_STORAGE_VOLATILE      (0x0000)
#define EFI_USER_INFO_STORAGE_CREDENTIAL_NV (0x0001)
#define EFI_USER_INFO_STORAGE_PLATFORM_NV   (0x0002)

#define EFI_USER_INFO_ACCESS                (0x0070)
#define EFI_USER_INFO_PUBLIC                (0x0010)
#define EFI_USER_INFO_PRIVATE               (0x0020)
#define EFI_USER_INFO_PROTECTED             (0x0030)
#define EFI_USER_INFO_EXCLUSIVE             (0x0080)

//
// EFI_USER_INFO
//
typedef struct {
    EFI_GUID                Credential;
    UINT8                   InfoType;
    UINT8                   Reserved1;
    EFI_USER_INFO_ATTRIBS   InfoAttribs;
    UINT32                  InfoSize;
} EFI_USER_INFO;

//
// EFI_USER_INFO.InfoType
//
#define EFI_USER_INFO_EMPTY_RECORD                      (0x00)
#define EFI_USER_INFO_NAME_RECORD                       (0x01)
#define EFI_USER_INFO_CREATE_DATE_RECORD                (0x02)
#define EFI_USER_INFO_USAGE_DATE_RECORD                 (0x03)
#define EFI_USER_INFO_USAGE_COUNT_RECORD                (0x04)
#define EFI_USER_INFO_IDENTIFIER_RECORD                 (0x05)
#define EFI_USER_INFO_CREDENTIAL_TYPE_RECORD            (0x06)
#define EFI_USER_INFO_CREDENTIAL_TYPE_NAME_RECORD       (0x07)
#define EFI_USER_INFO_CREDENTIAL_PROVIDER_RECORD        (0x08)
#define EFI_USER_INFO_CREDENTIAL_PROVIDER_NAME_RECORD   (0x09)
#define EFI_USER_INFO_PKCS11_RECORD                     (0x0A)
#define EFI_USER_INFO_CBEFF_RECORD                      (0x0B)
#define EFI_USER_INFO_FAR_RECORD                        (0x0C)
#define EFI_USER_INFO_RETRY_RECORD                      (0x0D)
#define EFI_USER_INFO_ACCESS_POLICY_RECORD              (0x0E)
#define EFI_USER_INFO_IDENTITY_POLICY_RECORD            (0x0F)
#define EFI_USER_INFO_GUID_RECORD                       (0xFF)

typedef struct {
    UINT32      Type;
    UINT32      Size;
} EFI_USER_INFO_ACCESS_CONTROL, EFI_USER_INFO_ACCESS_POLICY;

//
// EFI_USER_INFO_ACCESS_CONTROL.Type or EFI_USER_INFO_ACCESS_POLICY.Type
//
#define EFI_USER_INFO_ACCESS_FORBID_LOAD        (0x00000001)
#define EFI_USER_INFO_ACCESS_PERMIT_LOAD        (0x00000002)
#define EFI_USER_INFO_ACCESS_ENROLL_SELF        (0x00000003)
#define EFI_USER_INFO_ACCESS_ENROLL_OTHERS      (0x00000004)
#define EFI_USER_INFO_ACCESS_MANAGE             (0x00000005)
#define EFI_USER_INFO_ACCESS_SETUP              (0x00000006)
#define EFI_USER_INFO_ACCESS_FORBID_CONNECT     (0x00000007)
#define EFI_USER_INFO_ACCESS_PERMIT_CONNECT     (0x00000008)
#define EFI_USER_INFO_ACCESS_BOOT_ORDER         (0x00000009)

#define EFI_USER_INFO_ACCESS_SETUP_ADMIN_GUID \
    { 0x85B75607, 0xF7CE, 0x471E, { 0xB7, 0xE4, 0x2A, 0xEA, 0x5F, 0x72, 0x32, 0xEE } }

#define EFI_USER_INFO_ACCESS_SETUP_NORMAL_GUID \
    { 0x1DB29AE0, 0x9DCB, 0x43BC, { 0x8D, 0x87, 0x5D, 0xA1, 0x49, 0x64, 0xDD, 0xE2 } }

#define EFI_USER_INFO_ACCESS_SETUP_RESTRICTED_GUID \
    { 0xBDB38125, 0x4D63, 0x49F4, { 0x82, 0x12, 0x61, 0xCF, 0x5A, 0x19, 0x0A, 0xF8 } }

typedef UINT32 EFI_USER_INFO_ACCESS_BOOT_ORDER_HDR;

//
// Flags for EFI_USER_INFO_ACCESS_BOOT_ORDER_HDR
//
#define EFI_USER_INFO_ACCESS_BOOT_ORDER_MASK        (0x0000000F)
#define EFI_USER_INFO_ACCESS_BOOT_ORDER_INSERT      (0x00000000)
#define EFI_USER_INFO_ACCESS_BOOT_ORDER_APPEND      (0x00000001)
#define EFI_USER_INFO_ACCESS_BOOT_ORDER_REPLACE     (0x00000002)
#define EFI_USER_INFO_ACCESS_BOOT_ORDER_NONDEFAULT  (0x00000010)

typedef VOID* EFI_USER_INFO_CBEFF;
typedef EFI_TIME EFI_USER_INFO_CREATE_TIME;
typedef EFI_GUID EFI_USER_INFO_CREDENTIAL_PROVIDER;
typedef CHAR16* EFI_USER_INFO_CREDENTIAL_PROVIDER_NAME;
typedef EFI_GUID EFI_USER_INFO_CREDENTIAL_TYPE;
typedef CHAR16* EFI_USER_INFO_CREDENTIAL_TYPE_NAME;
typedef EFI_GUID EFI_USER_INFO_GUID;
typedef UINT8 EFI_USER_INFO_FAR;
typedef UINT8 EFI_USER_INFO_IDENTIFIER[16];

//
// EFI_USER_INFO_IDENTITY_POLICY
//
typedef struct {
    UINT32      Type;
    UINT32      Length;
} EFI_USER_INFO_IDENTITY_POLICY;

//
// EFI_USER_INFO_IDENTITY_POLICY.Type
//
#define EFI_USER_INFO_IDENTITY_FALSE                (0x00)
#define EFI_USER_INFO_IDENTITY_TRUE                 (0x01)
#define EFI_USER_INFO_IDENTITY_CREDENTIAL_TYPE      (0x02)
#define EFI_USER_INFO_IDENTITY_CREDENTIAL_PROVIDER  (0x03)
#define EFI_USER_INFO_IDENTITY_NOT                  (0x10)
#define EFI_USER_INFO_IDENTITY_AND                  (0x11)
#define EFI_USER_INFO_IDENTITY_OR                   (0x12)

typedef CHAR16* EFI_USER_INFO_NAME;
typedef UINT8 EFI_USER_INFO_RETRY;
typedef EFI_TIME EFI_USER_INFO_USAGE_DATE;
typedef UINT64 EFI_USER_INFO_USAGE_COUNT;

//
// EFI_USER_INFO_TABLE
//
typedef struct {
    UINT64      Size;
} EFI_USER_INFO_TABLE;

#endif // EFI_PROTOCOL_IDENTIFICATION_USERINFO_H
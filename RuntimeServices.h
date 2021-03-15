#ifndef EFI_RUNTIMESERVICES_H
#define EFI_RUNTIMESERVICES_H

#include <EFI/TableHeader.h>
#include <EFI/Protocol/SecureBoot/Certificate.h>

#define EFI_RUNTIME_SERVICES_SIGNATURE ((UINT64)0x56524553544E5552)
#define EFI_RUNTIME_SERVICES_REVISION  EFI_SPECIFICATION_VERSION

//
// Variable Services
//

// Variable Attributes
#define EFI_VARIABLE_NON_VOLATILE                           ((UINT32)0x00000001)
#define EFI_VARIABLE_BOOTSERVICE_ACCESS                     ((UINT32)0x00000002)
#define EFI_VARIABLE_RUNTIME_ACCESS                         ((UINT32)0x00000004)
#define EFI_VARIABLE_HARDWARE_ERROR_RECORD                  ((UINT32)0x00000008)
#define EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS             ((UINT32)0x00000010)
#define EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS  ((UINT32)0x00000020)
#define EFI_VARIABLE_APPEND_WRITE                           ((UINT32)0x00000040)

// EFI_VARIABLE_AUTHENTICATION
typedef struct {
    UINT64 MonotonicCount;
    WIN_CERTIFICATE_UEFI_GUID AuthInfo;
} EFI_VARIABLE_AUTHENTICATION;

// EFI_VARIABLE_AUTHENTICATION_2
typedef struct {
    EFI_TIME TimeStamp;
    WIN_CERTIFICATE_UEFI_GUID AuthInfo;
} EFI_VARIABLE_AUTHENTICATION_2;

#define EFI_HARDWARE_ERROR_VARIABLE \
    { 0x414E6BDD, 0xE47B, 0x47CC, { 0xB2, 0x44, 0xBB, 0x61, 0x02, 0x0C, 0xF5, 0x16 } }

typedef
EFI_STATUS
(EFIAPI *EFI_GET_VARIABLE) (
    IN CHAR16    *VariableName,
    IN EFI_GUID  *VendorGuid,
    OUT UINT32   *Attributes OPTIONAL,
    IN OUT UINTN *DataSize,
    OUT VOID     *Data
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_NEXT_VARIABLE_NAME) (
    IN OUT UINTN    *VariableNameSize,
    IN OUT CHAR16   *VariableName,
    IN OUT EFI_GUID *VendorGuid
);

typedef
EFI_STATUS
(EFIAPI *EFI_SET_VARIABLE) (
    IN CHAR16   *VariableName,
    IN EFI_GUID *VendorGuid,
    IN UINT32   Attributes,
    IN UINTN    DataSize,
    IN VOID     *Data
);

typedef
EFI_STATUS
(EFIAPI *EFI_QUERY_VARIABLE_INFO) (
    IN UINT32  Attributes,
    OUT UINT64 *MaximumVariableStorageSize,
    OUT UINT64 *RemainingVariableStorageSize,
    OUT UINT64 *MaximumVariableSize
);

//
// Time Services
//

//
// EFI_TIME_CAPABILITIES
//
typedef struct {
    UINT32 Resolution;
    UINT32 Accuracy;
    BOOLEAN SetToZero;
} EFI_TIME_CAPABILITIES;

typedef
EFI_STATUS
(EFIAPI *EFI_GET_TIME) (
    OUT EFI_TIME              *Time,
    OUT EFI_TIME_CAPABILITIES *Capabilities OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_SET_TIME) (
    IN EFI_TIME *Time
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_WAKEUP_TIME) (
    OUT BOOLEAN  *Enabled,
    OUT BOOLEAN  *Pending,
    OUT EFI_TIME *Time
);

typedef
EFI_STATUS
(EFIAPI *EFI_SET_WAKEUP_TIME) (
    IN BOOLEAN  Enable,
    IN EFI_TIME *Time OPTIONAL
);

//
// Virtual Memory Services
//

// EFI_OPTIONAL_PTR
#define EFI_OPTIONAL_PTR  ((VOID*)0x00000001)

typedef
EFI_STATUS
(EFIAPI *EFI_SET_VIRTUAL_ADDRESS_MAP) (
    IN UINTN                 MemoryMapSize,
    IN UINTN                 DescriptorSize,
    IN UINT32                DescriptorVersion,
    IN EFI_MEMORY_DESCRIPTOR *VirtualMap
);

typedef
EFI_STATUS
(EFIAPI *EFI_CONVERT_POINTER) (
    IN UINTN DebugDescription,
    IN VOID  **Address
);

//
// Miscellaneous Services
//
typedef enum {
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific
} EFI_RESET_TYPE;

typedef struct {
    UINT64 Length;
    union {
        EFI_PHYSICAL_ADDRESS DataBlock;
        EFI_PHYSICAL_ADDRESS ContinuationPointer;
    } Union;
} EFI_CAPSULE_BLOCK_DESCRIPTOR;

typedef struct {
    EFI_GUID CapsuleGuid;
    UINT32 HeaderSize;
    UINT32 Flags;
    UINT32 CapsuleImageSize;
} EFI_CAPSULE_HEADER;

#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET   ((UINT32)0x00010000)
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE  ((UINT32)0x00020000)
#define CAPSULE_FLAGS_INITIATE_RESET         ((UINT32)0x00040000)

#define EFI_OS_INDICATIONS_BOOT_TO_FW_UI                       ((UINT64)0x0000000000000001)
#define EFI_OS_INDICATIONS_TIMESTAMP_REVOCATION                ((UINT64)0x0000000000000002)
#define EFI_OS_INDICATIONS_FILE_CAPSULE_DELIVERY_SUPPROTED     ((UINT64)0x0000000000000004)
#define EFI_OS_INDICATIONS_FMP_CAPSULE_SUPPROTED               ((UINT64)0x0000000000000008)
#define EFI_OS_INDICATIONS_CAPSULE_RESET_RESULT_VAR_SUPPORTED  ((UINT64)0x0000000000000010)

#define EFI_CAPSULE_REPORT_GUID \
    { 0x39B68C46, 0xF7FB, 0x441B, { 0xB6, 0xEC, 0x16, 0xB0, 0xF6, 0x98, 0x21, 0xF3 } }

typedef struct {
    UINT32 VariableTotalSize;
    UINT32 Reserved; // for alignment
    EFI_GUID CapsuleGuid;
    EFI_TIME CapsuleProcessed;
    EFI_STATUS CapsuleStatus;
} EFI_CAPSULE_RESULT_VARIABLE_HEADER;

typedef struct {
    UINT16 Version;
    UINT8 PayloadIndex;
    UINT8 UpdateImageIndex;

    EFI_GUID UpdateImageTypeId;
    // CHAR16 CapsuleFileName[];
    // CHAR16 CapsuleTarget[];
} EFI_CAPSULE_RESULT_VARIABLE_MAP;

typedef
VOID
(EFIAPI *EFI_RESET_SYSTEM) (
    IN EFI_RESET_TYPE ResetType,
    IN EFI_STATUS     ResetStatus,
    IN UINTN          DataSize,
    IN VOID           *ResetData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_NEXT_HIGH_MONO_COUNT) (
    OUT UINT32 *HighCount
);

typedef
EFI_STATUS
(EFIAPI *EFI_UPDATE_CAPSULE) (
    IN EFI_CAPSULE_HEADER   **CapsuleHeaderArray,
    IN UINTN                CapsupeCount,
    IN EFI_PHYSICAL_ADDRESS ScatterGatherList OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_QUERY_CAPSULE_CAPABILITIES) (
    IN EFI_CAPSULE_HEADER **CapsuleHeaderArray,
    IN UINTN              CapsuleCount,
    OUT UINT64            *MaximumCapsuleSize,
    OUT EFI_RESET_TYPE    *ResetType
);

typedef struct {
    EFI_TABLE_HEADER               Hdr;

    //
    // Time Services
    //
    EFI_GET_TIME                   GetTime;
    EFI_SET_TIME                   SetTime;
    EFI_GET_WAKEUP_TIME            GetWakeupTime;
    EFI_SET_WAKEUP_TIME            SetWakeupTime;

    //
    // Virtual Memory Services
    //
    EFI_SET_VIRTUAL_ADDRESS_MAP    SetVirtualAddressMap;
    EFI_CONVERT_POINTER            ConvertPointer;

    //
    // Variable Services
    //
    EFI_GET_VARIABLE               GetVariable;
    EFI_GET_NEXT_VARIABLE_NAME     GetNextVariableName;
    EFI_SET_VARIABLE               SerVariable;

    //
    // Miscellaneous Services
    //
    EFI_GET_NEXT_HIGH_MONO_COUNT   GetNextHighMonotonicCount;
    EFI_RESET_SYSTEM               ResetSystem;

    //
    // UEFI 2.0 Capsupe Services
    //
    EFI_UPDATE_CAPSULE             UpdateCapsule;
    EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;

    //
    // Miscellaneous UEFI 2.0 Services
    //
    EFI_QUERY_VARIABLE_INFO        QueryVariableInfo;
} EFI_RUNTIME_SERVICES;

#endif // EFI_RUNTIMESERVICES_H
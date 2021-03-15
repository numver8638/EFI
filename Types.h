#ifndef EFI_TYPES_H
#define EFI_TYPES_H

#if defined(_X86_) || defined(__i386__) || defined(_M_IX86)
    #include <EFI/Arch/IA32/Types.h>
#elif defined(__x86_64__) || defined(__amd64__) || defined(_M_AMD64) || defined(_M_X64)
    #include <EFI/Arch/x64/Types.h>
#elif (defined(__arm__) && !defined(__thumb__)) || defined(_M_ARM)
    #include <EFI/Arch/AArch32/Types.h>
#elif defined(__aarch64__) || defined(_M_ARM64)
    #include <EFI/Arch/AArch64/Types.h>
#elif defined(__ia64__) || defined(__IA64__) || defined(_M_IA64)
    #include <EFI/Arch/IA64/Types.h>
#else
    #error Unknown/Unsupported architecture.
#endif

typedef UINT8  BOOLEAN;
#define TRUE   ((BOOLEAN)1)
#define FALSE  ((BOOLEAN)0)

typedef UINT8  CHAR8;
typedef UINT16 CHAR16;
typedef void   VOID;

typedef UINTN  EFI_STATUS;
typedef VOID*  EFI_HANDLE;
typedef VOID*  EFI_EVENT;
typedef UINT64 EFI_LBA;
typedef UINTN  EFI_TPL;
typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;

typedef CHAR16* EFI_STRING;

typedef struct {
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8  Data4[8];
} EFI_GUID;

#define IN
#define OUT
#define OPTIONAL
#define CONST     const
#define NULL      ((VOID*)0)

typedef struct {
    UINT8 Addr[32];
} EFI_MAC_ADDRESS;

typedef struct {
    UINT8 Addr[4];
} EFI_IPv4_ADDRESS;

typedef struct {
    UINT8 Addr[16];
} EFI_IPv6_ADDRESS;

typedef union {
    UINT32 Addr[4];
    EFI_IPv4_ADDRESS v4;
    EFI_IPv6_ADDRESS v6;
} EFI_IP_ADDRESS;

//
// Time Services
//

typedef struct {
    UINT16 Year;
    UINT8 Month;
    UINT8 Day;
    UINT8 Hour;
    UINT8 Minute;
    UINT8 Second;
    UINT8 Pad1;
    UINT32 Nanosecond;
    INT16 TimeZone;
    UINT8 Daylight;
    UINT8 Pad2;
} EFI_TIME;

#define EFI_TIME_ADJUST_DAYLIGHT ((UINT8)0x01)
#define EFI_TIME_IN_DAYLIGHT     ((UINT8)0x02)

#define EFI_UNSPECIFIED_TIMEZONE ((INT16)0x07FF)

//
// Memory Services
//

// EFI_ALLOCATE_TYPE
typedef enum {
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType
} EFI_ALLOCATE_TYPE;

// EFI_MEMORY_TYPE
typedef enum {
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventialMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiMaxMemoryType
} EFI_MEMORY_TYPE;

// EFI_MEMORY_DESCRIPTOR
typedef struct {
    UINT32 Type;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

#define EFI_MEMORY_DESCRIPTOR_VERSION ((UINT32)1)

// Memory Attribute Definitions
#define EFI_MEMORY_UC       ((UINT64)0x0000000000000001)
#define EFI_MEMORY_WC       ((UINT64)0x0000000000000002)
#define EFI_MEMORY_WT       ((UINT64)0x0000000000000004)
#define EFI_MEMORY_WB       ((UINT64)0x0000000000000008)
#define EFI_MEMORY_UCE      ((UINT64)0x0000000000000010)
#define EFI_MEMORY_WP       ((UINT64)0x0000000000001000)
#define EFI_MEMORY_RP       ((UINT64)0x0000000000002000)
#define EFI_MEMORY_XP       ((UINT64)0x0000000000004000)
#define EFI_MEMORY_RUNTIME  ((UINT64)0x8000000000000000)

#endif // EFI_TYPES_H
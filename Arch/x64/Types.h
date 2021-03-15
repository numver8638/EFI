#ifndef EFI_ARCH_X64_TYPE_H
#define EFI_ARCH_X64_TYPE_H

#if   defined(_MSC_VER)
typedef signed   char      INT8;
typedef signed   short     INT16;
typedef signed   int       INT32;
typedef signed   __int64   INT64;
typedef unsigned char      UINT8;
typedef unsigned short     UINT16;
typedef unsigned int       UINT32;
typedef unsigned __int64   UINT64;
#elif defined(__LP64__) || defined(_LP64)
typedef signed   char      INT8;
typedef signed   short     INT16;
typedef signed   int       INT32;
typedef signed   long      INT64;
typedef unsigned char      UINT8;
typedef unsigned short     UINT16;
typedef unsigned int       UINT32;
typedef unsigned long      UINT64;
#else
// Assumes following data model is LLP64.
typedef signed   char      INT8;
typedef signed   short     INT16;
typedef signed   int       INT32;
typedef signed   long long INT64;
typedef unsigned char      UINT8;
typedef unsigned short     UINT16;
typedef unsigned int       UINT32;
typedef unsigned long long UINT64;
#endif // _MSC_VER

typedef INT64             INTN;
typedef UINT64            UINTN;

#define HIGH_BIT ((UINT64)0x8000000000000000)
#define PAGE_SIZE (4096)

#if   defined(_MSC_VER)
    #define EFIAPI
#elif defined(__clang__) || defined(__gcc__)
    #define EFIAPI __attribute__((ms_abi))
#else
    #define EFIAPI
#endif //

#endif // EFI_ARCH_X64_TYPE_H
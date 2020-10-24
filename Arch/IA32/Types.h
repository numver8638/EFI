#ifndef EFI_ARCH_IA32_TYPE_H
#define EFI_ARCH_IA32_TYPE_H

#ifdef _MSC_VER
typedef signed   char      INT8;
typedef signed   short     INT16;
typedef signed   int       INT32;
typedef signed   __int64   INT64;
typedef unsigned char      UINT8;
typedef unsigned short     UINT16;
typedef unsigned int       UINT32;
typedef unsigned __int64   UINT64;
#else
// Assumes following data model is ILP32.
typedef signed   char      INT8;
typedef signed   short     INT16;
typedef signed   int       INT32;
typedef signed   long long INT64;
typedef unsigned char      UINT8;
typedef unsigned short     UINT16;
typedef unsigned int       UINT32;
typedef unsigned long long UINT64;
#endif // _MSC_VER

typedef INT32              INTN;
typedef UINT32             UINTN;

#define HIGH_BIT ((UINT32)0x80000000)
#define PAGE_SIZE (4096)

#if   defined(_MSC_VER)
    #define EFIAPI __cdecl
#elif defined(__clang__) || defined(__gcc__)
    #define EFIAPI __attribute__((cdecl))
#else
    #define EFIAPI
#endif //

#endif // EFI_ARCH_IA32_TYPE_H
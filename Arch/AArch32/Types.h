#ifndef EFI_ARCH_AARCH32_TYPE_H
#define EFI_ARCH_AARCH32_TYPE_H

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

#define EFIAPI

#endif // EFI_ARCH_AARCH32_TYPE_H
#ifndef EFI_PROTOCOL_MEDIA_UNICODECOLLATION_H
#define EFI_PROTOCOL_MEDIA_UNICODECOLLATION_H

#include <EFI/Types.h>

#define EFI_UNICODE_COLLATION_PROTOCOL2_GUID \
    { 0xA4C751FC, 0x23AE, 0x4C3E, { 0x92, 0xE9, 0x49, 0x64, 0xCF, 0x63, 0xF3, 0x49 } }

typedef struct _EFI_UNICODE_COLLATION_PROTOCOL EFI_UNICODE_COLLATION_PROTOCOL;

typedef
INTN
(EFIAPI *EFI_UNICODE_COLLATION_STRICOLL) (
    IN EFI_UNICODE_COLLATION_PROTOCOL   *This,
    IN CHAR16                           *s1,
    IN CHAR16                           *s2
);

typedef
BOOLEAN
(EFIAPI *EFI_UNICODE_COLLATION_METAIMATCH) (
    IN EFI_UNICODE_COLLATION_PROTOCOL   *This,
    IN CHAR16                           *String,
    IN CHAR16                           *Pattern
);

typedef
VOID
(EFIAPI *EFI_UNICODE_COLLATION_STRLWR) (
    IN EFI_UNICODE_COLLATION_PROTOCOL   *This,
    IN OUT CHAR16                       *String
);

typedef
VOID
(EFIAPI *EFI_UNICODE_COLLATION_STRUPR) (
    IN EFI_UNICODE_COLLATION_PROTOCOL   *This,
    IN OUT CHAR16                       *String
);

typedef
VOID
(EFIAPI *EFI_UNICODE_COLLATION_FATTOSTR) (
    IN EFI_UNICODE_COLLATION_PROTOCOL   *This,
    IN UINTN                            FatSize,
    IN CHAR8                            *Fat,
    OUT CHAR16                          *String
);

typedef
VOID
(EFIAPI *EFI_UNICODE_COLLATION_STRTOFAT) (
    IN EFI_UNICODE_COLLATION_PROTOCOL   *This,
    IN CHAR16                           *String,
    IN UINTN                            FatSize,
    OUT CHAR8                           *Fat
);

struct _EFI_UNICODE_COLLATION_PROTOCOL {
    EFI_UNICODE_COLLATION_STRICOLL      StriColl;
    EFI_UNICODE_COLLATION_METAIMATCH    MetaiMatch;
    EFI_UNICODE_COLLATION_STRLWR        StrLwr;
    EFI_UNICODE_COLLATION_STRUPR        StrUpr;
    EFI_UNICODE_COLLATION_FATTOSTR      FatToStr;
    EFI_UNICODE_COLLATION_STRTOFAT      StrToFat;
    CHAR8                               *SupportedLanguages;
};

#endif // EFI_PROTOCOL_MEDIA_UNICODECOLLATION_H
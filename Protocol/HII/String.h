#ifndef EFI_PROTOCOL_HII_STRING_H
#define EFI_PROTOCOL_HII_STRING_H

#include <EFI/Protocol/HII/Types.h>

#define EFI_HII_STRING_PROTOCOL_GUID \
    { 0x0FD96974, 0x23AA, 0x4CDC, {0xB9, 0xCB, 0x98, 0xD1, 0x77, 0x50, 0x32, 0x2A } }

typedef struct _EFI_HII_STRING_PROTOCOL EFI_HII_STRING_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_HII_NEW_STRING) (
    IN CONST EFI_HII_STRING_PROTOCOL    *This,
    IN EFI_HII_HANDLE                   PackageList,
    OUT EFI_STRING_ID                   *StringId,
    IN CONST CHAR8                      *Language,
    IN CONST CHAR16                     *LanguageName, OPTIONAL
    IN CONST EFI_STRING                 String,
    IN CONST EFI_FONT_INFO              *StringFontInfo
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_GET_STRING) (
    IN CONST EFI_HII_STRING_PROTOCOL    *This,
    IN CONST CHAR8                      *Language,
    IN EFI_HII_HANDLE                   PackageList,
    IN EFI_STRING_ID                    StringId,
    OUT EFI_STRING                      String,
    IN OUT UINTN                        *StringSize,
    OUT EFI_FONT_INFO                   **StringFontInfo OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_SET_STRING) (
    IN CONST EFI_HII_STRING_PROTOCOL    *This,
    IN EFI_HII_HANDLE                   PackageList,
    IN EFI_STRING_ID                    StringId,
    IN CONST CHAR8                      *Language,
    IN EFI_STRING                       String,
    IN EFI_FONT_INFO                    *StringFontInfo OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_GET_LANGUAGES) (
    IN CONST EFI_HII_STRING_PROTOCOL    *This,
    IN EFI_HII_HANDLE                   PackageList,
    IN OUT CHAR8                        *Languages,
    IN OUT UINTN                        *LanguagesSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_GET_2ND_LANGUAGES) (
    IN CONST EFI_HII_STRING_PROTOCOL    *This,
    IN EFI_HII_HANDLE                   PackageList,
    IN CONST CHAR8                      *PrimaryLanguage,
    IN OUT CHAR8                        *SecondaryLanguages,
    IN OUT UINTN                        *SecondaryLanguagesSize
);

struct _EFI_HII_STRING_PROTOCOL {
    EFI_HII_NEW_STRING              NewString;
    EFI_HII_GET_STRING              GetString;
    EFI_HII_SET_STRING              SetString;
    EFI_HII_GET_LANGUAGES           GetLanguages;
    EFI_HII_GET_2ND_LANGUAGES       GetSecondaryLanguages;
};

#endif // EFI_PROTOCOL_HII_STRING_H
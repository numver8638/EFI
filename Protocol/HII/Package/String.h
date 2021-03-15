#ifndef EFI_PROTOCOL_HII_PACKAGE_STRING_H
#define EFI_PROTOCOL_HII_PACKAGE_STRING_H

#include <EFI/Protocol/HII/Types.h>

//
// EFI_HII_STRING_PACKAGE_HDR
//
typedef struct {
    EFI_HII_PACKAGE_HDR     Header;
    UINT32                  HdrSize;
    UINT32                  StringInfoOffset;
    CHAR16                  LanguageWindow[16];
    EFI_STRING_ID           LanguageName;
    CHAR8                   Language[1];
} EFI_HII_STRING_PACKAGE_HDR;

#define UEFI_CONFIG_LANG    "x-UEFI"
#define UEFI_CONFIG_LANG_2  "x-i-UEFI"

//
// EFI_HII_STRING_BLOCK
//
typedef struct {
    UINT8       BlockType;
    // UINT8    BlockBody[];
} EFI_HII_STRING_BLOCK;

#define EFI_HII_SIBT_END                (0x00)
#define EFI_HII_SIBT_STRING_SCSU        (0x10)
#define EFI_HII_SIBT_STRING_SCSU_FONT   (0x11)
#define EFI_HII_SIBT_STRINGS_SCSU       (0x12)
#define EFI_HII_SIBT_STRINGS_SCSU_FONT  (0x13)
#define EFI_HII_SIBT_STRING_UCS2        (0x14)
#define EFI_HII_SIBT_STRING_UCS2_FONT   (0x15)
#define EFI_HII_SIBT_STRINGS_UCS2       (0x16)
#define EFI_HII_SIBT_STRINGS_UCS2_FONT  (0x17)
#define EFI_HII_SIBT_DUPLICATE          (0x20)
#define EFI_HII_SIBT_SKIP2              (0x21)
#define EFI_HII_SIBT_SKIP1              (0x22)
#define EFI_HII_SIBT_EXT1               (0x30)
#define EFI_HII_SIBT_EXT2               (0x31)
#define EFI_HII_SIBT_EXT4               (0x32)
#define EFI_HII_SIBT_FONT               (0x40)

//
// EFI_HII_SIBT_DUPLICATE_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    EFI_STRING_ID           StringId;
} EFI_HII_SIBT_DUPLICATE_BLOCK;

//
// EFI_HII_SIBT_END_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
} EFI_HII_SIBT_END_BLOCK;

//
// EFI_HII_SIBT_EXT1_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    UINT8                   BlockType2;
    UINT8                   Length;
} EFI_HII_SIBT_EXT1_BLOCK;

//
// EFI_HII_SIBT_EXT2_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    UINT8                   BlockType2;
    UINT16                  Length;
} EFI_HII_SIBT_EXT2_BLOCK;

//
// EFI_HII_SIBT_EXT4_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    UINT8                   BlockType2;
    UINT32                  Length;
} EFI_HII_SIBT_EXT4_BLOCK;

//
// EFI_HII_SIBT_FONT_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    UINT8                   FontId;
    UINT16                  FontSize;
    EFI_HII_FONT_STYLE      FontStyle;
    CHAR16                  FontName[];
} EFI_HII_SIBT_FONT_BLOCK;

//
// EFI_HII_SIBT_SKIP1_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    UINT8                   SkipCount;
} EFI_HII_SIBT_SKIP1_BLOCK;

//
// EFI_HII_SIBT_SKIP2_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    UINT16                  SkipCount;
} EFI_HII_SIBT_SKIP2_BLOCK;

//
// EFI_HII_SIBT_STRING_SCSU_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    UINT8                   StringText[];
} EFI_HII_SIBT_STRING_SCSU_BLOCK;

//
// EFI_HII_SIBT_STRING_SCSU_FONT_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    UINT8                   FontIdentifier;
    UINT8                   StringText[];
} EFI_HII_SIBT_STRING_SCSU_FONT_BLOCK;

//
// EFI_HII_SIBT_STRINGS_SCSU_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    UINT16                  StringCount;
    UINT8                   StringText[];
} EFI_HII_SIBT_STRINGS_SCSU_BLOCK;

//
// EFI_HII_SIBT_STRINGS_SCSU_FONT_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    UINT8                   FontIdentifier;
    UINT16                  StringCount;
    UINT8                   StringText[];
} EFI_HII_SIBT_STRINGS_SCSU_FONT_BLOCK;

//
// EFI_HII_SIBT_STRING_UCS2_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    CHAR16                  StringText[];
} EFI_HII_SIBT_STRING_UCS2_BLOCK;

//
// EFI_HII_SIBT_STRING_UCS2_FONT_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    UINT8                   FontIdentifier;
    CHAR16                  StringText[];
} EFI_HII_SIBT_STRING_UCS2_FONT_BLOCK;

//
// EFI_HII_SIBT_STRINGS_UCS2_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    UINT16                  StringCount;
    CHAR16                  StringText[];
} EFI_HII_SIBT_STRINGS_UCS2_BLOCK;

//
// EFI_HII_SIBT_STRINGS_UCS2_FONT_BLOCK
//
typedef struct {
    EFI_HII_STRING_BLOCK    Header;
    UINT8                   FontIdentifier;
    UINT16                  StringCount;
    CHAR16                  StringText[];
} EFI_HII_SIBT_STRINGS_UCS2_FONT_BLOCK;

#endif // EFI_PROTOCOL_HII_PACKAGE_STRING_H
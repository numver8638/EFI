#ifndef EFI_PROTOCOL_HII_PACKAGE_FONT_H
#define EFI_PROTOCOL_HII_PACKAGE_FONT_H

#include <EFI/Protocol/HII/Types.h>

//
// EFI_HII_GLYPH_INFO
//
typedef struct {
    UINT16  Width;
    UINT16  Height;
    INT16   OffsetX;
    INT16   OffsetY;
    INT16   AdvanceX;
} EFI_HII_GLYPH_INFO;

//
// EFI_HII_FONT_PACKAGE_HDR
//
typedef struct {
    EFI_HII_PACKAGE_HDR     Header;
    UINT32                  HdrSize;
    UINT32                  GlyphBlockOffset;
    EFI_HII_GLYPH_INFO      Cell;
    EFI_HII_FONT_STYLE      FontStyle;
    CHAR16                  FontFamily[];
} EFI_HII_FONT_PACKAGE_HDR;

#define EFI_HII_GIBD_END                (0x00)
#define EFI_HII_GIBD_GLYPH              (0x10)
#define EFI_HII_GIBD_GLYPHS             (0x11)
#define EFI_HII_GIBD_GLYPH_DEFAULT      (0x12)
#define EFI_HII_GIBD_GLYPHS_DEFAULT     (0x13)
#define EFI_HII_GIBD_DUPLICATE          (0x20)
#define EFI_HII_GIBD_SKIP2              (0x21)
#define EFI_HII_GIBD_SKIP1              (0x22)
#define EFI_HII_GIBD_DEFAULTS           (0x23)
#define EFI_HII_GIBD_EXT1               (0x30)
#define EFI_HII_GIBD_EXT2               (0x31)
#define EFI_HII_GIBD_EXT4               (0x32)

//
// EFI_HII_GLYPH_BLOCK
//
typedef struct {
    UINT8       BlockType;
    // UINT8    BlockBody[];
} EFI_HII_GLYPH_BLOCK;

//
// EFI_HII_GIBT_DEFAULTS_BLOCK
//
typedef struct {
    EFI_HII_GLYPH_BLOCK     Header;
    EFI_HII_GLYPH_INFO      Cell;
} EFI_HII_GIBT_DEFAULTS_BLOCK;

//
// EFI_HII_GIBT_DUPLICATE_BLOCK
//
typedef struct {
    EFI_HII_GLYPH_BLOCK     Header;
    CHAR16                  CharValue;
} EFI_HII_GIBT_DUPLICATE_BLOCK;

//
// EFI_GLYPH_GIBT_END_BLOCK
//
typedef struct {
    EFI_HII_GLYPH_BLOCK     Header;
} EFI_GLYPH_GIBT_END_BLOCK;

//
// EFI_HII_GIBT_EXT1_BLOCK
//
typedef struct {
    EFI_HII_GLYPH_BLOCK     Header;
    UINT8                   BlockType2;
    UINT8                   Length;
} EFI_HII_GIBT_EXT1_BLOCK;

//
// EFI_HII_GIBT_EXT2_BLOCK
//
typedef struct {
    EFI_HII_GLYPH_BLOCK     Header;
    UINT8                   BlockType2;
    UINT16                  Length;
} EFI_HII_GIBT_EXT2_BLOCK;

//
// EFI_HII_GIBT_EXT4_BLOCK
//
typedef struct {
    EFI_HII_GLYPH_BLOCK     Header;
    UINT8                   BlockType2;
    UINT32                  Length;
} EFI_HII_GIBT_EXT4_BLOCK;

//
// EFI_HII_GIBT_GLYPH_BLOCK
//
typedef struct {
    EFI_HII_GLYPH_BLOCK     Header;
    EFI_HII_GLYPH_INFO      Cell;
    UINT8                   BitmapData[1];
} EFI_HII_GIBT_GLYPH_BLOCK;

//
// EFI_HII_GIBT_GLYPHS_BLOCK
//
typedef struct {
    EFI_HII_GLYPH_BLOCK     Header;
    EFI_HII_GLYPH_INFO      Cell;
    UINT16                  Count;
    UINT8                   BitmapData[1];
} EFI_HII_GIBT_GLYPHS_BLOCK;

//
// EFI_HII_GIBT_GLYPH_DEFAULT_BLOCK
//
typedef struct {
    EFI_HII_GLYPH_BLOCK     Header;
    UINT8                   BitmapData[1];
} EFI_HII_GIBT_GLYPH_DEFAULT_BLOCK;

//
// EFI_HII_GIBT_GLYPHS_DEFAULT_BLOCK
//
typedef struct {
    EFI_HII_GLYPH_BLOCK     Header;
    UINT16                  Count;
    UINT8                   BitmapData[1];
} EFI_HII_GIBT_GLYPHS_DEFAULT_BLOCK;

//
// EFI_HII_GIBT_SKIP1_BLOCK
//
typedef struct {
    EFI_HII_GLYPH_BLOCK     Header;
    UINT8                   SkipCount;
} EFI_HII_GIBT_GLYPH_SKIP1_BLOCK;

//
// EFI_HII_GIBT_GLYPH_SKIP2_BLOCK
//
typedef struct {
    EFI_HII_GLYPH_BLOCK     Header;
    UINT16                  SkipCount;
} EFI_HII_GIBT_GLYPH_SKIP2_BLOCK;

#endif // EFI_PROTOCOL_HII_PACKAGE_FONT_H
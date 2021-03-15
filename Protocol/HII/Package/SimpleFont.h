#ifndef EFI_PROTOCOL_HII_PACKAGE_SIMPLEFONT_H
#define EFI_PROTOCOL_HII_PACKAGE_SIMPLEFONT_H

#include <EFI/Protocol/HII/Types.h>

//
// EFI_HII_SIMPLE_FONT_PACKAGE_HDR
//
typedef struct {
    EFI_HII_PACKAGE_HDR         Header;
    UINT16                      NumberOfNarrowGlyphs;
    UINT16                      NumberOfWideGlyphs;
    // EFI_NARROW_GLYPH         NarrowGlyphs[];
    // EFI_WIDE_GLYPH           WideGlyphs[];
} EFI_HII_SIMPLE_FONT_PACKAGE_HDR;

#define EFI_GLYPH_NON_SPACING   (0x01)
#define EFI_GLYPH_WIDE          (0x02)
#define EFI_GLYPH_HEIGHT        (19)
#define EFI_GLYPH_WIDTH         (8)

//
// EFI_NARROW_GLYPH
//
typedef struct {
    CHAR16  UnicodeWeight;
    UINT8   Attributes;
    UINT8   GlyphColl[EFI_GLYPH_HEIGHT];
} EFI_NARROW_GLYPH;

//
// EFI_WIDE_GLYPH
//
typedef struct {
    CHAR16  UnicodeWeight;
    UINT8   Attributes;
    UINT8   GlyphColl1[EFI_GLYPH_HEIGHT];
    UINT8   GlyphColl2[EFI_GLYPH_HEIGHT];
} EFI_WIDE_GLYPH;

#endif // EFI_PROTOCOL_HII_PACKAGE_SIMPLEFONT_H
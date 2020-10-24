#ifndef EFI_PROTOCOL_HII_PACKAGE_IMAGE_H
#define EFI_PROTOCOL_HII_PACKAGE_IMAGE_H

#include <EFI/Protocol/HII/Types.h>

//
// EFI_HII_IMAGE_PACKAGE_HDR
//
typedef struct {
    EFI_HII_PACKAGE_HDR     Header;
    UINT32                  ImageInfoOffset;
    UINT32                  PaletteInfoOffet;
} EFI_HII_IMAGE_PACKAGE_HDR;

#define EFI_HII_IIBT_END                (0x00)
#define EFI_HII_IIBT_IMAGE_1BIT         (0x10)
#define EFI_HII_IIBT_IMAGE_1BIT_TRANS   (0x11)
#define EFI_HII_IIBT_IMAGE_4BIT         (0x12)
#define EFI_HII_IIBT_IMAGE_4BIT_TRANS   (0x13)
#define EFI_HII_IIBT_IMAGE_8BIT         (0x14)
#define EFI_HII_IIBT_IMAGE_8BIT_TRANS   (0x15)
#define EFI_HII_IIBT_IMAGE_24BIT        (0x16)
#define EFI_HII_IIBT_IMAGE_24BIT_TRANS  (0x17)
#define EFI_HII_IIBT_IMAGE_JPEG         (0x18)
#define EFI_HII_IIBT_DUPLICATE          (0x20)
#define EFI_HII_IIBT_SKIP2              (0x21)
#define EFI_HII_IIBT_SKIP1              (0x22)
#define EFI_HII_IIBT_EXT1               (0x30)
#define EFI_HII_IIBT_EXT2               (0x31)
#define EFI_HII_IIBT_EXT4               (0x32)

//
// EFI_HII_IMAGE_BLOCK
//
typedef struct {
    UINT8       BlockType;
    // UINT8    BlockBody[];
} EFI_HII_IMAGE_BLOCK;

//
// EFI_HII_IIBT_END_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK     Header;
} EFI_HII_IIBT_END_BLOCK;

//
// EFI_HII_IIBT_EXT1_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK     Header;
    UINT8                   BlockType2;
    UINT8                   Length;
} EFI_HII_IIBT_EXT1_BLOCK;

//
// EFI_HII_IIBT_EXT2_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK     Header;
    UINT8                   BlockType2;
    UINT16                  Length;
} EFI_HII_IIBT_EXT2_BLOCK;

//
// EFI_HII_IIBT_EXT4_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK     Header;
    UINT8                   BlockType2;
    UINT32                  Length;
} EFI_HII_IIBT_EXT4_BLOCK;

//
// EFI_HII_IIBT_IMAGE_1BIT_BASE
//
typedef struct {
    UINT16      Width;
    UINT16      Height;
    UINT8       Data[1];
} EFI_HII_IIBT_IMAGE_1BIT_BASE;

//
// EFI_HII_IIBT_IMAGE_1BIT_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK             Header;
    UINT8                           PaletteIndex;
    EFI_HII_IIBT_IMAGE_1BIT_BASE    Bitmap;
} EFI_HII_IIBT_IMAGE_1BIT_BLOCK;

//
// EFI_HII_IIBT_IMAGE_1BIT_TRANS_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK             Header;
    UINT8                           PaletteIndex;
    EFI_HII_IIBT_IMAGE_1BIT_BASE    Bitmap;
} EFI_HII_IIBT_IMAGE_1BIT_TRANS_BLOCK;

//
// EFI_HII_IIBT_IMAGE_24BIT_BASE
//
typedef struct {
    UINT16                  Width;
    UINT16                  Height;
    EFI_HII_RGB_PIXEL       Data[1];
} EFI_HII_IIBT_IMAGE_24BIT_BASE;

//
// EFI_HII_IIBT_IMAGE_24BIT_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK             Header;
    EFI_HII_IIBT_IMAGE_24BIT_BASE   Bitmap;
} EFI_HII_IIBT_IMAGE_24BIT_BLOCK;

//
// EFI_HII_IIBT_IMAGE_24BIT_TRANS_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK             Header;
    EFI_HII_IIBT_IMAGE_24BIT_BASE   Bitmap;
} EFI_HII_IIBT_IMAGE_24BIT_TRANS_BLOCK;

//
// EFI_HII_IIBT_IMAGE_4BIT_BASE
//
typedef struct {
    UINT16      Width;
    UINT16      Height;
    UINT8       Data[1];
} EFI_HII_IIBT_IMAGE_4BIT_BASE;

//
// EFI_HII_IIBT_IMAGE_4BIT_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK             Header;
    UINT8                           PaletteIndex;
    EFI_HII_IIBT_IMAGE_4BIT_BASE    Bitmap;
} EFI_HII_IIBT_IMAGE_4BIT_BLOCK;

//
// EFI_HII_IIBT_IMAGE_4BIT_TRANS_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK             Header;
    UINT8                           PaletteIndex;
    EFI_HII_IIBT_IMAGE_4BIT_BASE    Bitmap;
} EFI_HII_IIBT_IMAGE_4BIT_TRANS_BLOCK;

//
// EFI_HII_IIBT_IMAGE_8BIT_BASE
//
typedef struct {
    UINT16      Width;
    UINT16      Height;
    UINT8       Data[1];
} EFI_HII_IIBT_IMAGE_8BIT_BASE;

//
// EFI_HII_IIBT_IMAGE_8BIT_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK             Header;
    UINT8                           PaletteIndex;
    EFI_HII_IIBT_IMAGE_8BIT_BASE    Bitmap;
} EFI_HII_IIBT_IMAGE_8BIT_BLOCK;

//
// EFI_HII_IIBT_IMAGE_8BIT_TRANS_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK             Header;
    UINT8                           PaletteIndex;
    EFI_HII_IIBT_IMAGE_8BIT_BASE    Bitmap;
} EFI_HII_IIBT_IMAGE_8BIT_TRANS_BLOCK;

//
// EFI_HII_IIBT_DUPLICATE_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK     Header;
    EFI_IMAGE_ID            ImageId;
} EFI_HII_IIBT_DUPLICATE_BLOCK;

//
// EFI_HII_IIBT_JPEG_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK     Header;
    UINT32                  Size;
    UINT8                   Data[1];
} EFI_HII_IIBT_JPEG_BLOCK;

//
// EFI_HII_IIBT_SKIP1_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK     Header;
    UINT8                   SkipCount;
} EFI_HII_IIBT_SKIP1_BLOCK;

//
// EFI_HII_IIBT_SKIP2_BLOCK
//
typedef struct {
    EFI_HII_IMAGE_BLOCK     Header;
    UINT16                  SkipCount;
} EFI_HII_IIBT_SKIP2_BLOCK;

//
// EFI_HII_IMAGE_PALETTE_INFO_HEADER
//
typedef struct {
    UINT16  PaletteCount;
} EFI_HII_IMAGE_PALETTE_INFO_HEADER;

//
// EFI_HII_IMAGE_PALETTE_INFO
//
typedef struct {
    UINT16                  PaletteSize;
    EFI_HII_RGB_PIXEL       PaletteValue[1];
} EFI_HII_IMAGE_PALETTE_INFO;

#endif // EFI_PROTOCOL_HII_PACKAGE_IMAGE_H
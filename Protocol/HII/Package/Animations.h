#ifndef EFI_PROTOCOL_HII_PACKAGE_ANIMATIONS_H
#define EFI_PROTOCOL_HII_PACKAGE_ANIMATIONS_H

#include <EFI/Protocol/HII/Types.h>

//
// EFI_HII_ANIMATION_PACKAGE_HDR
//
typedef struct {
    EFI_HII_PACKAGE_HDR         Header;
    UINT32                      AnimationInfoOffset;
} EFI_HII_ANIMATION_PACKAGE_HDR;

//
// EFI_HII_ANIMATION_BLOCK
//
typedef struct {
    UINT8       BlockType;
    // UINT8    BlockBody[];
} EFI_HII_ANIMATION_BLOCK;

#define EFI_HII_AIBT_END                    (0x00)
#define EFI_HII_AIBT_OVERLAY_IMAGES         (0x10)
#define EFI_HII_AIBT_CLEAR_IMAGES           (0x11)
#define EFI_HII_AIBT_RESTORE_SCAN           (0x12)
#define EFI_HII_AIBT_OVERLAY_IMAGES_LOOP    (0x18)
#define EFI_HII_AIBT_CLEAR_IMAGES_LOOP      (0x19)
#define EFI_HII_AIBT_RESTORE_SCAN_LOOP      (0x1A)
#define EFI_HII_AIBT_DUPLICATE              (0x20)
#define EFI_HII_AIBT_SKIP2                  (0x21)
#define EFI_HII_AIBT_SKIP1                  (0x22)
#define EFI_HII_AIBT_EXT1                   (0x30)
#define EFI_HII_AIBT_EXT2                   (0x31)
#define EFI_HII_AIBT_EXT4                   (0x32)

//
// EFI_HII_ANIMATION_CELL
//
typedef struct {
    UINT16          OffsetX;
    UINT16          OffsetY;
    EFI_IMAGE_ID    ImageId;
    UINT16          Delay;
} EFI_HII_ANIMATION_CELL;

//
// EFI_HII_AIBT_END_BLOCK
//
typedef struct {
    EFI_HII_ANIMATION_BLOCK     Header;
} EFI_HII_AIBT_END_BLOCK;

//
// EFI_HII_AIBT_EXT1_BLOCK
//
typedef struct {
    EFI_HII_ANIMATION_BLOCK     Header;
    UINT8                       BlockType2;
    UINT8                       Length;
} EFI_HII_AIBT_EXT1_BLOCK;

//
// EFI_HII_AIBT_EXT2_BLOCK
//
typedef struct {
    EFI_HII_ANIMATION_BLOCK     Header;
    UINT8                       BlockType2;
    UINT16                      Length;
} EFI_HII_AIBT_EXT2_BLOCK;

//
// EFI_HII_AIBT_EXT4_BLOCK
//
typedef struct {
    EFI_HII_ANIMATION_BLOCK     Header;
    UINT8                       BlockType2;
    UINT32                      Length;
} EFI_HII_AIBT_EXT4_BLOCK;

//
// EFI_HII_AIBT_OVERLAY_IMAGES_BLOCK
//
typedef struct {
    EFI_IMAGE_ID            DftImageId;
    UINT16                  Width;
    UINT16                  Height;
    UINT16                  CellCount;
    EFI_HII_ANIMATION_CELL  AnimationCell[1];
} EFI_HII_AIBT_OVERLAY_IMAGES_BLOCK;

//
// EFI_HII_AIBT_CLEAR_IMAGES_BLOCK
//
typedef struct {
    EFI_IMAGE_ID            DftImageId;
    UINT16                  Width;
    UINT16                  Height;
    UINT16                  CellCount;
    EFI_HII_RGB_PIXEL       BackgroundColor;
    EFI_HII_ANIMATION_CELL  AnimationCell[1];
} EFI_HII_AIBT_CLEAR_IMAGES_BLOCK;

//
// EFI_HII_AIBT_RESTORE_SCAN_BLOCK
//
typedef struct {
    EFI_IMAGE_ID            DftImageId;
    UINT16                  Width;
    UINT16                  Height;
    UINT16                  CellCount;
    EFI_HII_ANIMATION_CELL  AnimationCell[1];
} EFI_HII_AIBT_RESTORE_SCAN_BLOCK;

//
// EFI_HII_AIBT_OVERLAY_IMAGES_LOOP_BLOCK
//
typedef struct {
    EFI_IMAGE_ID            DftImageId;
    UINT16                  Width;
    UINT16                  Height;
    UINT16                  CellCount;
    EFI_HII_ANIMATION_CELL  AnimationCell[1];
} EFI_HII_AIBT_OVERLAY_IMAGES_LOOP_BLOCK;

//
// EFI_HII_AIBT_CLEAR_IMAGES_LOOP_BLOCK
//
typedef struct {
    EFI_IMAGE_ID            DftImageId;
    UINT16                  Width;
    UINT16                  Height;
    UINT16                  CellCount;
    EFI_HII_RGB_PIXEL       BackgroundColor;
    EFI_HII_ANIMATION_CELL  AnimationCell[1];
} EFI_HII_AIBT_CLEAR_IMAGES_LOOP_BLOCK;

//
// EFI_HII_AIBT_RESTORE_SCAN_LOOP_BLOCK
//
typedef struct {
    EFI_IMAGE_ID            DftImageId;
    UINT16                  Width;
    UINT16                  Height;
    UINT16                  CellCount;
    EFI_HII_ANIMATION_CELL  AnimationCell[1];
} EFI_HII_AIBT_RESTORE_SCAN_LOOP_BLOCK;

//
// EFI_HII_AIBT_DUPLICATE_BLOCK
//
typedef struct {
    EFI_ANIMATION_ID            AnimationId;
} EFI_HII_AIBT_DUPLICATE_BLOCK;

//
// EFI_HII_AIBT_SKIP1_BLOCK
//
typedef struct {
    UINT8                       SkipCount;
} EFI_HII_AIBT_SKIP1_BLOCK;

//
// EFI_HII_AIBT_SKIP2_BLOCK
//
typedef struct {
    UINT16                      SkipCount;
} EFI_HII_AIBT_SKIP2_BLOCK;

#endif // EFI_PROTOCOL_HII_PACKAGE_ANIMATIONS_H
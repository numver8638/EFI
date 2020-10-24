#ifndef EFI_PROTOCOL_HII_IMAGE_H
#define EFI_PROTOCOL_HII_IMAGE_H

#include <EFI/Protocol/Console/GraphicsOutput.h>
#include <EFI/Protocol/HII/Types.h>

#define EFI_HII_IMAGE_PROTOCOL_GUID \
    { 0x31A6406A, 0x6BDF, 0x4E46, { 0xB2, 0xA2, 0xEB, 0xAA, 0x89, 0xC4, 0x09, 0x20 } }

typedef struct _EFI_HII_IMAGE_PROTOCOL EFI_HII_IMAGE_PROTOCOL;

//
// EFI_IMAGE_INPUT
//
typedef struct {
    UINT32                          Flags;
    UINT16                          Width;
    UINT16                          Height;
    EFI_GRAPHICS_OUTPUT_BLT_PIXEL   *Bitmap;
} EFI_IMAGE_INPUT;

#define EFI_IMAGE_TRANSPARENT       (0x00000001)\

typedef UINT32 EFI_HII_DRAW_FLAGS;

#define EFI_HII_DRAW_FLAG_CLIP          (0x00000001)
#define EFI_HII_DRAW_FLAG_TRANSPARENT   (0x00000030)
#define EFI_HII_DRAW_FLAG_DEFAULT       (0x00000000)
#define EFI_HII_DRAW_FLAG_FORCE_TRANS   (0x00000010)
#define EFI_HII_DRAW_FLAG_FORCE_OPAQUE  (0x00000020)
#define EFI_HII_DIRECT_TO_SCREEN        (0x00000080)

typedef
EFI_STATUS
(EFIAPI *EFI_HII_NEW_IMAGE) (
    IN CONST EFI_HII_IMAGE_PROTOCOL *This,
    IN EFI_HII_HANDLE               PackageList,
    OUT EFI_IMAGE_ID                *ImageId,
    IN CONST EFI_IMAGE_INPUT        *Image
);

typedef 
EFI_STATUS
(EFIAPI *EFI_HII_GET_IMAGE) (
    IN CONST EFI_HII_IMAGE_PROTOCOL *This,
    IN EFI_HII_HANDLE               PackageList,
    IN EFI_IMAGE_ID                 ImageId,
    OUT EFI_IMAGE_INPUT             *Image
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_SET_IMAGE) (
    IN CONST EFI_HII_IMAGE_PROTOCOL *This,
    IN EFI_HII_HANDLE               PackageList,
    IN EFI_IMAGE_ID                 ImageId,
    IN CONST EFI_IMAGE_INPUT        *Image
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_DRAW_IMAGE) (
    IN CONST EFI_HII_IMAGE_PROTOCOL *This,
    IN EFI_HII_DRAW_FLAGS           Flags,
    IN CONST EFI_IMAGE_INPUT        *Image,
    IN OUT EFI_IMAGE_INPUT          **Blt,
    IN UINTN                        BltX,
    IN UINTN                        BltY
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_DRAW_IMAGE_ID) (
    IN CONST EFI_HII_IMAGE_PROTOCOL *This,
    IN EFI_HII_DRAW_FLAGS           Flags,
    IN EFI_HII_HANDLE               PackageList,
    IN EFI_IMAGE_ID                 ImageId,
    IN OUT EFI_IMAGE_INPUT          **Blt,
    IN UINTN                        BltX,
    IN UINTN                        BltY
);

struct _EFI_HII_IMAGE_PROTOCOL {
    EFI_HII_NEW_IMAGE       NewImage;
    EFI_HII_GET_IMAGE       GetImage;
    EFI_HII_SET_IMAGE       SetImage;
    EFI_HII_DRAW_IMAGE      DrawImage;
    EFI_HII_DRAW_IMAGE_ID   DrawImageId;
};

#endif // EFI_PROTOCOL_HII_IMAGE_H
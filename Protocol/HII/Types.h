#ifndef EFI_PROTOCOL_HII_TYPES
#define EFI_PROTOCOL_HII_TYPES

#include <EFI/Types.h>

typedef EFI_HANDLE EFI_HII_HANDLE;
typedef UINT16 EFI_QUESTION_ID;
typedef UINT16 EFI_IMAGE_ID;
typedef UINT16 EFI_STRING_ID;
typedef UINT16 EFI_FORM_ID;
typedef UINT16 EFI_VARSTORE_ID;
typedef UINT16 EFI_ANIMATION_ID;
typedef UINT16 EFI_DEFAULT_ID;

//
// EFI_HII_PACKAGE_HDR
//
typedef struct {
    UINT32      Length:24;
    UINT32      Type:8;
    // UINT8    Data[...];
} EFI_HII_PACKAGE_HDR;

#define EFI_HII_PACKAGE_TYPE_ALL            (0x00)
#define EFI_HII_PACKAGE_TYPE_GUID           (0x01)
#define EFI_HII_PACKAGE_FORMS               (0x02)
#define EFI_HII_PACKAGE_STRINGS             (0x03)
#define EFI_HII_PACKAGE_FONTS               (0x04)
#define EFI_HII_PACKAGE_IMAGES              (0x05)
#define EFI_HII_PACKAGE_SIMPLE_FONTS        (0x06)
#define EFI_HII_PACKAGE_DEVICE_PATH         (0x07)
#define EFI_HII_PACKAGE_KEYBOARD_LAYOUT     (0x08)
#define EFI_HII_PACKAGE_ANIMATIONS          (0x09)
#define EFI_HII_PACKAGE_END                 (0x0A)
#define EFI_HII_PACKAGE_TYPE_SYSTEM_BEGIN   (0xE0)
#define EFI_HII_PACKAGE_TYPE_SYSTEM_END     (0xFF)

//
// EFI_HII_PACKAGE_LIST_HEADER
//
typedef struct {
    EFI_GUID    PackageListGuid;
    UINT32      PackageLength;
} EFI_HII_PACKAGE_LIST_HEADER;

// Shared between Package/Font.h and Package/String.h
typedef UINT32 EFI_HII_FONT_STYLE;

#define EFI_HII_FONT_STYLE_NORMAL       (0x00000000)
#define EFI_HII_FONT_STYLE_BOLD         (0x00000001)
#define EFI_HII_FONT_STYLE_ITALIC       (0x00000002)
#define EFI_HII_FONT_STYLE_EMBOSS       (0x00010000)
#define EFI_HII_FONT_STYLE_OUTLINE      (0x00020000)
#define EFI_HII_FONT_STYLE_SHADOW       (0x00040000)
#define EFI_HII_FONT_STYLE_UNDERLINE    (0x00080000)
#define EFI_HII_FONT_STYLE_DBL_UNDER    (0x00100000)

//
// EFI_HII_RGB_PIXEL
// Shared between Package/Image.h and Package/Animations.h
//
typedef struct {
    UINT8   b;
    UINT8   g;
    UINT8   r;
} EFI_HII_RGB_PIXEL;

//
// EFI_FONT_INFO
// Shared between String.h and Font.h
//
typedef struct {
    EFI_HII_FONT_STYLE  FontStyle;
    UINT16              FontSize;
    CHAR16              FontName[1];
} EFI_FONT_INFO;

#endif // EFI_PROTOCOL_HII_TYPES
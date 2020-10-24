#ifndef EFI_PROTOCOL_CONSOLE_GRAPHICSOUTPUT_H
#define EFI_PROTOCOL_CONSOLE_GRAPHICSOUTPUT_H

#include <EFI/Types.h>

#define EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID \
    { 0x9042A9DE, 0x23DC, 0x4F38, { 0x96, 0xFB, 0x7A, 0xDE, 0xD0, 0x80, 0x51, 0x6A } }

typedef struct _EFI_GRAPHICS_OUTPUT_PROTOCOL EFI_GRAPHICS_OUTPUT_PROTOCOL;

typedef struct {
    UINT32      RedMask;
    UINT32      GreenMask;
    UINT32      BlueMask;
    UINT32      ReservedMask;
} EFI_PIXEL_BITMASK;

typedef enum {
    PixelRedGreenBlueReserved8BitPerColor,
    PixelBlueGreenRedReserved8BitPerColor,
    PixelBitMask,
    PixelBltOnly,
    PixelFormatMax
} EFI_GRAPHICS_PIXEL_FORMAT;

typedef struct {
    UINT32                      Version;
    UINT32                      HorizontalResolution;
    UINT32                      VerticalResolution;
    EFI_GRAPHICS_PIXEL_FORMAT   PixelFormat;
    EFI_PIXEL_BITMASK           PixelInformation;
    UINT32                      PixelsPerScanLine;
} EFI_GRAPHICS_OUTPUT_MODE_INFORMATION;

typedef struct {
    UINT32                                  MaxMode;
    UINT32                                  Mode;
    EFI_GRAPHICS_OUTPUT_MODE_INFORMATION    *Info;
    UINTN                                   SizeOfInfo;
    EFI_PHYSICAL_ADDRESS                    FrameBufferBase;
    UINTN                                   FrameBufferSize;
} EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE;

typedef struct {
    UINT8   Blue;
    UINT8   Green;
    UINT8   Red;
    UINT8   Reserved;
} EFI_GRAPHICS_OUTPUT_BLT_PIXEL;

typedef enum {
    EfiBltVideoFill,
    EfiBltVideoToBltBuffer,
    EfiBltBufferToVideo,
    EfiBltVideoToVideo,
    EfiGraphicsOutputBltOperationMax
} EFI_GRAPHICS_OUTPUT_BLT_OPERATION;

typedef
EFI_STATUS
(EFIAPI *EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE) (
    IN EFI_GRAPHICS_OUTPUT_PROTOCOL             *This,
    IN UINT32                                   ModeNumber,
    OUT UINTN                                   *SizeOfInfo,
    OUT EFI_GRAPHICS_OUTPUT_MODE_INFORMATION    **Info
);

typedef
EFI_STATUS
(EFIAPI *EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE) (
    IN EFI_GRAPHICS_OUTPUT_PROTOCOL     *This,
    IN UINT32                           ModeNumber
);

typedef
EFI_STATUS
(EFIAPI *EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT) (
    IN EFI_GRAPHICS_OUTPUT_PROTOCOL         *This,
    IN OUT EFI_GRAPHICS_OUTPUT_BLT_PIXEL    *BltBuffer, OPTIONAL
    IN EFI_GRAPHICS_OUTPUT_BLT_OPERATION    BltOperation,
    IN UINTN                                SourceX,
    IN UINTN                                SourceY,
    IN UINTN                                DestinationX,
    IN UINTN                                DestinationY,
    IN UINTN                                Width,
    IN UINTN                                Height,
    IN UINTN                                Delta OPTIONAL
);

struct _EFI_GRAPHICS_OUTPUT_PROTOCOL {
    EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE QueryMode;
    EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE   SetMode;
    EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT        Blt;
    EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE       *Mode;
};

#define EFI_EDID_DISCOVERED_PROTOCOL_GUID \
    { 0x1C0C34F6, 0xD380, 0x41FA, { 0xA0, 0x49, 0x8A, 0xD0, 0x6C, 0x1A, 0x55, 0xAA } }

#define EFI_EDID_ACTIVE_PROTOCOL_GUID \
    { 0xDB8C1056, 0x9F36, 0x44EC, { 0x92, 0xA8, 0xA6, 0x33, 0x7F, 0x81, 0x79, 0x86 } }

#define EFI_EDID_OVERRIDE_PROTOCOL_GUID \
    { 0x48ECB431, 0xFB72, 0x45C0, { 0xA9, 0x22, 0xF4, 0x58, 0xFE, 0x04, 0x0B, 0xD5 } }

#define EFI_EDID_OVERRIDE_DONT_OVERRIDE     (0x01)
#define EFI_EDID_OVERRIDE_ENABLE_HOT_PLUG   (0x02)

typedef struct {
    UINT32  SizeOfEdid;
    UINT8   *Edid;
} EFI_EDID_DISCOVERED_PROTOCOL;

typedef struct {
    UINT32  SizeOfEdid;
    UINT8   *Edid;
} EFI_EDID_ACTIVE_PROTOCOL;

typedef struct _EFI_EDID_OVERRIDE_PROTOCOL EFI_EDID_OVERRIDE_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_EDID_OVERRIDE_PROTOCOL_GET_EDID) (
    IN EFI_EDID_OVERRIDE_PROTOCOL       *This,
    IN EFI_HANDLE                       *ChildHandle,
    OUT UINT32                          *Attributes,
    IN OUT UINTN                        *EdidSize,
    IN OUT UINT8                        **Edid
);

struct _EFI_EDID_OVERRIDE_PROTOCOL {
    EFI_EDID_OVERRIDE_PROTOCOL_GET_EDID GetEdid;
};

#endif // EFI_PROTOCOL_CONSOLE_GRAPHICSOUTPUT_H
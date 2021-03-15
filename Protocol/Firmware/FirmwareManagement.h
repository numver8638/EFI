#ifndef EFI_PROTOCOL_FIRMWARE_FIRMWAREMANAGEMENT_H
#define EFI_PROTOCOL_FIRMWARE_FIRMWAREMANAGEMENT_H

#include <EFI/Types.h>
#include <EFI/Protocol/SecureBoot/Certificate.h>

#define EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GUID \
    { 0x86C77A67, 0x0B67, 0x4633, { 0xA1, 0x87, 0x49, 0x10, 0x4D, 0x06, 0x85, 0xC7 } }

#define EFI_FIRMWARE_MANAGEMENT_CAPSULE_ID_GUID \
    { 0x6DCBD5ED, 0xE82D, 0x4C44, { 0xDB, 0xA1, 0x71, 0x94, 0x19, 0x9A, 0xD9, 0x2A } }

typedef struct _EFI_FIRMWARE_MANAGEMENT_PROTOCOL EFI_FIRMWARE_MANAGEMENT_PROTOCOL;

//
// Image Attribute Definitions
//
#define IMAGE_ATTRIBUTE_IMAGE_UPDATABLE             (0x0000000000000001)
#define IMAGE_ATTRIBUTE_RESET_REQUIRED              (0x0000000000000002)
#define IMAGE_ATTRIBUTE_AUTHENTICATION_REQUIRED     (0x0000000000000004)
#define IMAGE_ATTRIBUTE_IN_USE                      (0x0000000000000008)
#define IMAGE_ATTRIBUTE_UEFI_IMAGE                  (0x0000000000000010)

//
// Image Compatibility Definitions
//
#define IMAGE_COMPATIBILITY_CHECK_SUPPORTED         (0x0000000000000001)

//
// Descriptor Version exposed by GetImageInfo() function
//
#define EFI_FIRMWARE_IMAGE_DESCRIPTOR_VERSION       (2)

//
// Image Attribute - Authentication Required
//
typedef struct {
    UINT64                      MonotonicCount;
    WIN_CERTIFICATE_UEFI_GUID   AuthInfo;
} EFI_FIRMWARE_IMAGE_AUTHENTICATION;

//
// EFI_FIRMWARE_IMAGE_DESCRIPTOR
//
typedef struct {
    UINT8       ImageIndex;
    EFI_GUID    ImageTypeId;
    UINT64      ImageId;
    CHAR16      *ImageIdName;
    UINT32      Version;
    CHAR16      *VersionName;
    UINTN       Size;
    UINT64      AttributesSupported;
    UINT64      AttributesSetting;
    UINT64      Compatibilities;
    UINT32      LowestSupportedImageInfo;   // Introduced with DescriptorVersion 2+
} EFI_FIRMWARE_IMAGE_DESCRIPTOR;

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_UPDATE_IMAGE_PROGRESS) (
    IN UINTN    Completion
);

//
// ImageUpdatable Definition
//
#define IMAGE_UPDATABLE_VALID           (0x00000001)
#define IMAGE_UPDATABLE_INVALID         (0x00000002)
#define IMAGE_UPDATABLE_INVALID_TYPE    (0x00000004)
#define IMAGE_UPDATABLE_INVALID_OLD     (0x00000008)

//
// Package Attribute Definitions
//
#define PACKAGE_ATTRIBUTE_VERSION_UPDATABLE         (0x0000000000000001)
#define PACKAGE_ATTRIBUTE_RESET_REQUIRED            (0x0000000000000002)
#define PACKAGE_ATTRIBUTE_AUTHENTICATION_REQUIRED   (0x0000000000000004)

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_IMAGE_INFO) (
    IN EFI_FIRMWARE_MANAGEMENT_PROTOCOL     *This,
    IN OUT UINTN                            *ImageInfoSize,
    IN OUT EFI_FIRMWARE_IMAGE_DESCRIPTOR    *ImageInfo,
    OUT UINT32                              *DescriptorVersion,
    OUT UINT8                               *DescriptorCount,
    OUT UINTN                               *DescriptorSize,
    OUT UINT32                              *PackageVersion,
    OUT CHAR16                              **PackageVersionName
);

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_IMAGE) (
    IN EFI_FIRMWARE_MANAGEMENT_PROTOCOL     *This,
    IN UINT8                                ImageIndex,
    IN OUT VOID                             *Image,
    IN OUT UINTN                            *ImageSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_PROTOCOL_SET_IMAGE) (
    IN EFI_FIRMWARE_MANAGEMENT_PROTOCOL                 *This,
    IN UINT8                                            ImageIndex,
    IN CONST VOID                                       *Image,
    IN UINTN                                            ImageSize,
    IN CONST VOID                                       *VendorCode,
    IN EFI_FIRMWARE_MANAGEMENT_UPDATE_IMAGE_PROGRESS    Progress,
    OUT CHAR16                                          **AbortReason
);

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_PROTOCOL_CHECK_IMAGE) (
    IN EFI_FIRMWARE_MANAGEMENT_PROTOCOL     *This,
    IN UINT8                                ImageIndex,
    IN CONST VOID                           *Image,
    IN UINTN                                ImageSize,
    OUT UINT32                              *ImageUpdatable
);

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_PACKAGE_INFO) (
    IN EFI_FIRMWARE_MANAGEMENT_PROTOCOL     *This,
    OUT UINT32                              *PackageVersion,
    OUT CHAR16                              **PackageVersionName,
    OUT UINT32                              *PackageVersionNameMaxLen,
    OUT UINT64                              *AttributesSupported,
    OUT UINT64                              *AttributesSetting
);

typedef
EFI_STATUS
(EFIAPI *EFI_FIRMWARE_MANAGEMENT_PROTOCOL_SET_PACKAGE_INFO) (
    IN EFI_FIRMWARE_MANAGEMENT_PROTOCOL     *This,
    IN CONST VOID                           *Image,
    IN UINTN                                ImageSize,
    IN CONST VOID                           *VendorCode,
    IN UINT32                               PackageVersion,
    IN CONST CHAR16                         *PackageVersionName
);

struct _EFI_FIRMWARE_MANAGEMENT_PROTOCOL {
    EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_IMAGE_INFO     GetImageInfo;
    EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_IMAGE          GetImage;
    EFI_FIRMWARE_MANAGEMENT_PROTOCOL_SET_IMAGE          SetImage;
    EFI_FIRMWARE_MANAGEMENT_PROTOCOL_CHECK_IMAGE        CheckImage;
    EFI_FIRMWARE_MANAGEMENT_PROTOCOL_GET_PACKAGE_INFO   GetPackageInfo;
    EFI_FIRMWARE_MANAGEMENT_PROTOCOL_SET_PACKAGE_INFO   SetPackageInfo;
};

#endif // EFI_PROTOCOL_FIRMWARE_FIRMWAREMANAGEMENT_H
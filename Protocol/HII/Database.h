#ifndef EFI_PROTOCOL_HII_DATABASE_H
#define EFI_PROTOCOL_HII_DATABASE_H

#include <EFI/Protocol/HII/Types.h>

#define EFI_HII_DATABASE_PROTOCOL_GUID \
    { 0xEF9FC172, 0xA1B2, 0x4693, { 0xB3, 0x27, 0x6D, 0x32, 0xFC, 0x41, 0x60, 0x42 } }

typedef struct _EFI_HII_DATABASE_PROTOCOL EFI_HII_DATABASE_PROTOCOL;

//
// EFI_KEY_DESCRIPTOR
//
typedef struct {
    EFI_KEY     Key;
    CHAR16      Unicode;
    CHAR16      ShiftedUnicode;
    CHAR16      AltGrUnicode;
    CHAR16      ShiftedAltGrUnicode;
    UINT16      Modifier;
    UINT16      AffectedAttribute;
} EFI_KEY_DESCRIPTOR;

// A key which is affected by all the standard shift modifiers.
// Most keys would be expected to have this bit active.
#define EFI_AFFECTED_BY_STANDARD_SHIFT      (0x0001)

// This key is affected by the caps lock so that if a keyboard
// driver would need to disambigate between a key which had a
// "1" defined versus a "a" character. Having ths bit turned on
// would tell the keyboard driver to use the appropriate shifted
// state or not.
#define EFI_AFFECTED_BY_CAPS_LOCK           (0x0002)

// Similar to the case of CAPS lock, tf this bit is active, the
// key is affected by the num lock being turned on.
#define EFI_AFFECTED_BY_NUM_LOCK            (0x0004)

//
// EFI_KEY
//
typedef enum {
    EfiKeyLCtrl,
    EfiKeyKeyA0,
    EfiKeyLAlt,
    EfiKeyKeySpaceBar,
    EfiKeyA2,
    EfiKeyA3,
    EfiKeyA4,
    EfiKeyRCtrl,
    EfiKeyLeftArrow,
    EfiKeyDownArrow,
    EfiKeyRightArrow,
    EfiKeyZero,
    EfiKeyPeriod,
    EfiKeyEnter,
    EfiKeyLShift,
    EfiKeyB0,
    EfiKeyB1,
    EfiKeyB2,
    EfiKeyB3,
    EfiKeyB4,
    EfiKeyB5,
    EfiKeyB6,
    EfiKeyB7,
    EfiKeyB8,
    EfiKeyB9,
    EfiKeyB10,
    EfiKeyRShift,
    EfiKeyUpArrow,
    EfiKeyOne,
    EfiKeyTwo,
    EfiKeyThree,
    EfiKeyCapsLock,
    EfiKeyC1,
    EfiKeyC2,
    EfiKeyC3,
    EfiKeyC4,
    EfiKeyC5,
    EfiKeyC6,
    EfiKeyC7,
    EfiKeyC8,
    EfiKeyC9,
    EfiKeyC10,
    EfiKeyC11,
    EfiKeyC12,
    EfiKeyFour,
    EfiKeyFive,
    EfiKeySix,
    EfiKeyPlus,
    EfiKeyTab,
    EfiKeyD1,
    EfiKeyD2,
    EfiKeyD3,
    EfiKeyD4,
    EfiKeyD5,
    EfiKeyD6,
    EfiKeyD7,
    EfiKeyD8,
    EfiKeyD9,
    EfiKeyD10,
    EfiKeyD11,
    EfiKeyD12,
    EfiKeyD13,
    EfiKeyDel,
    EfiKeyEnd,
    EfiKeyPgDn,
    EfiKeySeven,
    EfiKeyEight,
    EfiKeyNine,
    EfiKeyE0,
    EfiKeyE1,
    EfiKeyE2,
    EfiKeyE3,
    EfiKeyE4,
    EfiKeyE5,
    EfiKeyE6,
    EfiKeyE7,
    EfiKeyE8,
    EfiKeyE9,
    EfiKeyE10,
    EfiKeyE11,
    EfiKeyE12,
    EfiKeyBackSpace,
    EfiKeyIns,
    EfiKeyHome,
    EfiKeyPgUp,
    EfiKeyNLock,
    EfiKeySlash,
    EfiKeyAsterisk,
    EfiKeyMinus,
    EfiKeyEsc,
    EfiKeyF1,
    EfiKeyF2,
    EfiKeyF3,
    EfiKeyF4,
    EfiKeyF5,
    EfiKeyF6,
    EfiKeyF7,
    EfiKeyF8,
    EfiKeyF9,
    EfiKeyF10,
    EfiKeyF11,
    EfiKeyF12,
    EfiKeyPrint,
    EfiKeySLock,
    EfiKeyPause
} EFI_KEY;

//
// Modifier values
//
#define EFI_NULL_MODIFIER                   (0x0000)
#define EFI_LEFT_CONTROL_MODIFIER           (0x0001)
#define EFI_RIGHT_CONTROL_MODIFIER          (0x0002)
#define EFI_LEFT_ALT_MODIFIER               (0x0003)
#define EFI_RIGHT_ALT_MODIFIER              (0x0004)
#define EFI_ALT_GR_MODIFIER                 (0x0005)
#define EFI_INSERT_MODIFIER                 (0x0006)
#define EFI_DELETE_MODIFIER                 (0x0007)
#define EFI_PAGE_DOWN_MODIFIER              (0x0008)
#define EFI_PAGE_UP_MODIFIER                (0x0009)
#define EFI_HOME_MODIFIER                   (0x000A)
#define EFI_END_MODIFIER                    (0x000B)
#define EFI_LEFT_SHIFT_MODIFIER             (0x000C)
#define EFI_RIGHT_SHIFT_MODIFIER            (0x000D)
#define EFI_CAPS_LOCK_MODIFIER              (0x000E)
#define EFI_NUM_LOCK_MODIFIER               (0x000F)
#define EFI_LEFT_ARROW_MODIFIER             (0x0010)
#define EFI_RIGHT_ARROW_MODIFIER            (0x0011)
#define EFI_DOWN_ARROW_MODIFIER             (0x0012)
#define EFI_UP_ARROW_MODIFIER               (0x0013)
#define EFI_NS_KEY_MODIFIER                 (0x0014)
#define EFI_NS_KEY_DEPENDENCY_MODIFIER      (0x0015)
#define EFI_FUNCTION_KEY_ONE_MODIFIER       (0x0016)
#define EFI_FUNCTION_KEY_TWO_MODIFIER       (0x0017)
#define EFI_FUNCTION_KEY_THREE_MODIFIER     (0x0018)
#define EFI_FUNCTION_KEY_FOUR_MODIFIER      (0x0019)
#define EFI_FUNCTION_KEY_FIVE_MODIFIER      (0x001A)
#define EFI_FUNCTION_KEY_SIX_MODIFIER       (0x001B)
#define EFI_FUNCTION_KEY_SEVEN_MODIFIER     (0x001C)
#define EFI_FUNCTION_KEY_EIGHT_MODIFIER     (0x001D)
#define EFI_FUNCTION_KEY_NINE_MODIFIER      (0x001E)
#define EFI_FUNCTION_KEY_TEN_MODIFIER       (0x001F)
#define EFI_FUNCTION_KEY_ELEVEN_MODIFIER    (0x0020)
#define EFI_FUNCTION_KEY_TWELVE_MODIFIER    (0x0021)
//
// Keys that have multiple control functions based on modifier
// settings are handled in the keyboard driver implementation.
// For instant PRINT_KEY might have a modifier held down and
// is still a nonprinting character, but might have an alternate
// control function like SYSREQUEST
//
#define EFI_PRINT_MODIFIER                  (0x0022)
#define EFI_SYS_REQUEST_MODIFIER            (0x0023)
#define EFI_SCROLL_LOCK_MODIFIER            (0x0024)

//
// EFI_HII_KEYBOARD_LAYOUT
//
typedef struct {
    UINT16              LayoutLength;
    EFI_GUID            Guid;
    UINT32              LayoutDescriptorStringOffset;
    UINT8               DescriptorCount;
    EFI_KEY_DESCRIPTOR  Descriptors[1];
} EFI_HII_KEYBOARD_LAYOUT;

#define EFI_HII_SET_KEYBOARD_LAYOUT_EVENT_GUID \
    { 0x14982A4F, 0xB0ED, 0x45B8, { 0xA8, 0x11, 0x5A, 0x7A, 0x9B, 0xC2, 0x32, 0xDF } }

typedef UINTN EFI_HII_DATABASE_NOTIFY_TYPE;

#define EFI_HII_DATABASE_NOTIFY_NEW_PACK        (0x00000001)
#define EFI_HII_DATABASE_NOTIFY_REMOTE_PACK     (0x00000002)
#define EFI_HII_DATABASE_NOTIFY_EXPORT_PACK     (0x00000004)
#define EFI_HII_DATABASE_NOTIFY_ADD_PACK        (0x00000008)

typedef
EFI_STATUS
(EFIAPI *EFI_HII_DATABASE_NOTIFY) (
    IN UINT8                                PackageType,
    IN CONST EFI_GUID                       *PackageGuid,
    IN CONST EFI_HII_PACKAGE_HDR            *Package,
    IN EFI_HII_HANDLE                       Handle,
    IN EFI_HII_DATABASE_NOTIFY_TYPE         NotifyType
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_DATABASE_NEW_PACK) (
    IN CONST EFI_HII_DATABASE_PROTOCOL      *This,
    IN CONST EFI_HII_PACKAGE_LIST_HEADER    *PackageList,
    IN CONST EFI_HANDLE                     DriverHandle, OPTIONAL
    OUT EFI_HII_HANDLE                      *Handle
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_DATABASE_REMOTE_PACK) (
    IN CONST EFI_HII_DATABASE_PROTOCOL      *This,
    IN EFI_HII_HANDLE                       Handle
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_DATABASE_UPDATE_PACK) (
    IN CONST EFI_HII_DATABASE_PROTOCOL      *This,
    IN EFI_HII_HANDLE                       Handle,
    IN CONST EFI_HII_PACKAGE_LIST_HEADER    *PackageList
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_DATABASE_LIST_PACKS) (
    IN CONST EFI_HII_DATABASE_PROTOCOL      *This,
    IN UINT8                                PackageType,
    IN CONST EFI_GUID                       *PackageGuid,
    IN OUT UINTN                            *HandleBufferLength,
    OUT EFI_HII_HANDLE                      *Handle
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_DATABASE_EXPORT_PACKS) (
    IN CONST EFI_HII_DATABASE_PROTOCOL      *This,
    IN EFI_HII_HANDLE                       Handle,
    IN OUT UINTN                            *BufferSize,
    OUT EFI_HII_PACKAGE_LIST_HEADER         *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_DATABASE_REGISTER_NOTIFY) (
    IN CONST EFI_HII_DATABASE_PROTOCOL      *This,
    IN UINT8                                PackageType,
    IN CONST EFI_GUID                       *PackageGuid,
    IN CONST EFI_HII_DATABASE_NOTIFY        PackageNotfyFn,
    IN EFI_HII_DATABASE_NOTIFY_TYPE         NotifyType,
    OUT EFI_HANDLE                          *NotifyHandle
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_DATABASE_UNREGISTER_NOTIFY) (
    IN CONST EFI_HII_DATABASE_PROTOCOL      *This,
    IN EFI_HANDLE                           NotificationHandle
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_FIND_KEYBOARD_LAYOUTS) (
    IN CONST EFI_HII_DATABASE_PROTOCOL      *This,
    IN OUT UINT16                           *KeyGuidBufferLength,
    OUT EFI_GUID                            *KeyGuidBuffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_GET_KEYBOARD_LAYOUT) (
    IN CONST EFI_HII_DATABASE_PROTOCOL      *This,
    IN EFI_GUID                             *KeyGuid,
    IN OUT UINT16                           *KeyboardLayoutLength,
    OUT EFI_HII_KEYBOARD_LAYOUT             *KeyboardLayout
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_SET_KEYBOARD_LAYOUT) (
    IN CONST EFI_HII_DATABASE_PROTOCOL      *This,
    IN EFI_GUID                             *KeyGuid
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_DATABASE_GET_PACK_HANDLE) (
    IN CONST EFI_HII_DATABASE_PROTOCOL      *This,
    IN EFI_HII_HANDLE                       PackageListHandle,
    OUT EFI_HANDLE                          *DriverHandle
);

struct _EFI_HII_DATABASE_PROTOCOL {
    EFI_HII_DATABASE_NEW_PACK           NewPackageList;
    EFI_HII_DATABASE_REMOTE_PACK        RemovePackageList;
    EFI_HII_DATABASE_UPDATE_PACK        UpdatePackageList;
    EFI_HII_DATABASE_LIST_PACKS         ListPackageLists;
    EFI_HII_DATABASE_EXPORT_PACKS       ExportPackageLists;
    EFI_HII_DATABASE_REGISTER_NOTIFY    RegisterPackageNotify;
    EFI_HII_DATABASE_UNREGISTER_NOTIFY  UnregisterPackageNotify;
    EFI_HII_FIND_KEYBOARD_LAYOUTS       FindKeyboardLayouts;
    EFI_HII_GET_KEYBOARD_LAYOUT         GetKeyboardLayout;
    EFI_HII_SET_KEYBOARD_LAYOUT         SetKeyboardLayout;
    EFI_HII_DATABASE_GET_PACK_HANDLE    GetPackageListHandle;
};

#endif // EFI_PROTOCOL_HII_DATABASE_H
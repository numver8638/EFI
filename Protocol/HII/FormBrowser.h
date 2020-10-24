#ifndef EFI_PROTOCOL_HII_FORMBROWSER_H
#define EFI_PROTOCOL_HII_FORMBROWSER_H

#include <EFI/Protocol/HII/Types.h>
#include <EFI/Protocol/HII/ConfigurationAccess.h>

#define EFI_FORM_BROWSER2_PROTOCOL_GUID \
    { 0xB9D4C360, 0xBFCB, 0x4F9B, { 0x92, 0x98, 0x53, 0xC1, 0x36, 0x98, 0x22, 0x58 } }

typedef struct _EFI_FORM_BROWSER2_PROTOCOL EFI_FORM_BROWSER2_PROTOCOL;

//
// EFI_SCREEN_DESCRIPTOR
//
typedef struct {
    UINTN       LeftColumn;
    UINTN       RightColumn;
    UINTN       TopRow;
    UINTN       BottomRow;
} EFI_SCREEN_DESCRIPTOR;

#define EFI_HII_PLATFORM_SETUP_FORMSET_GUID \
    { 0x93039971, 0x8545, 0x4B04, { 0xB4, 0x5E, 0x32, 0xEB, 0x83, 0x26, 0x04, 0x0E } }

#define EFI_HII_DRIVER_HEALTH_FORMSET_GUID \
    { 0xF22FC20C, 0x8CF4, 0x45EB, { 0x8E, 0x06, 0xAD, 0x4E, 0x50, 0xB9, 0x5D, 0xD3 } }

#define EFI_HII_USER_CREDENTIAL_FORMSET_GUID \
    { 0x337F4407, 0x5AEE, 0x4B83, { 0xB2, 0xA7, 0x4E, 0xAD, 0xCA, 0x30, 0x88, 0xCD } }

typedef
EFI_STATUS
(EFIAPI *EFI_SEND_FORM2) (
    IN CONST EFI_FORM_BROWSER2_PROTOCOL *This,
    IN EFI_HII_HANDLE                   *Handles,
    IN UINTN                            HandleCount,
    IN CONST EFI_GUID                   *FormsetGuid, OPTIONAL
    IN EFI_FORM_ID                      FormId, OPTIONAL
    IN CONST EFI_SCREEN_DESCRIPTOR      *ScreenDimentions, OPTIONAL
    OUT EFI_BROWSER_ACTION_REQUEST      *ActionRequest OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_BROWSER_CALLBACK2) (
    IN CONST EFI_FORM_BROWSER2_PROTOCOL *This,
    IN OUT UINTN                        *ResultsDataSize,
    IN OUT EFI_STRING                   ResultData,
    IN BOOLEAN                          RetrieveData,
    IN CONST EFI_GUID                   *VariableGuid, OPTIONAL
    IN CONST CHAR16                     *VariableName OPTIONAL
);

struct _EFI_FORM_BROWSER2_PROTOCOL {
    EFI_SEND_FORM2          SendForm;
    EFI_BROWSER_CALLBACK2   BrowserCallback;
};

#endif // EFI_PROTOCOL_HII_FORMBROWSER_H
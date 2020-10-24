#ifndef EFI_PROTOCOL_HII_CONFIGURATIONACCESS_H
#define EFI_PROTOCOL_HII_CONFIGURATIONACCESS_H

#include <EFI/Types.h>
#include <EFI/Protocol/HII/Package/Forms.h>

#define EFI_HII_CONFIG_ACCESS_PROTOCOL_GUID \
    { 0x330D4706, 0xF2A0, 0x4E4F, { 0xA3, 0x69, 0xB6, 0x6F, 0xA8, 0xD5, 0x43, 0x85 } }

typedef struct _EFI_HII_CONFIG_ACCESS_PROTOCOL EFI_HII_CONFIG_ACCESS_PROTOCOL;

typedef UINTN EFI_BROWSER_ACTION;

#define EFI_BROWSER_ACTION_CHANGING                 (0)
#define EFI_BROWSER_ACTION_CHANGED                  (1)
#define EFI_BROWSER_ACTION_RETRIEVE                 (2)
#define EFI_BROWSER_ACTION_FORM_OPEN                (3)
#define EFI_BROWSER_ACTION_FORM_CLOSE               (4)
#define EFI_BROWSER_ACTION_DEFAULT_STANDARD         (0x1000)
#define EFI_BROWSER_ACTION_DEFAULT_MANUFACTURING    (0x1001)
#define EFI_BROWSER_ACTION_DEFAULT_SAFE             (0x1002)
#define EFI_BROWSER_ACTION_DEFAULT_PLATFORM         (0x2000)
#define EFI_BROWSER_ACTION_DEFAULT_HARDWARE         (0x3000)
#define EFI_BROWSER_ACTION_DEFAULT_FIRMWARE         (0x4000)

typedef UINTN EFI_BROWSER_ACTION_REQUEST;

#define EFI_BROWSER_ACTION_REQUEST_NONE                 (0)
#define EFI_BROWSER_ACTION_REQUEST_RESET                (1)
#define EFI_BROWSER_ACTION_REQUEST_SUBMIT               (2)
#define EFI_BROWSER_ACTION_REQUEST_EXIT                 (3)
#define EFI_BROWSER_ACTION_REQUEST_FORM_SUBMIT_EXIT     (4)
#define EFI_BROWSER_ACTION_REQUEST_FORM_DISCARD_EXIT    (5)
#define EFI_BROWSER_ACTION_REQUEST_FORM_APPLY           (6)
#define EFI_BROWSER_ACTION_REQUEST_FORM_DISCARD         (7)

typedef
EFI_STATUS
(EFIAPI *EFI_HII_ACCESS_EXTRACT_CONFIG) (
    IN CONST EFI_HII_CONFIG_ACCESS_PROTOCOL     *This,
    IN CONST EFI_STRING                         Request,
    OUT EFI_STRING                              *Progress,
    OUT EFI_STRING                              *Results
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_ACCESS_ROUTE_CONFIG) (
    IN CONST EFI_HII_CONFIG_ACCESS_PROTOCOL     *This,
    IN CONST EFI_STRING                         Configuration,
    OUT EFI_STRING                              *Progress
);

typedef
EFI_STATUS
(EFIAPI *EFI_HII_ACCESS_FORM_CALLBACK) (
    IN CONST EFI_HII_CONFIG_ACCESS_PROTOCOL     *This,
    IN EFI_BROWSER_ACTION                       Action,
    IN EFI_QUESTION_ID                          QuestionId,
    IN UINT8                                    Type,
    IN OUT EFI_IFR_TYPE_VALUE                   *Value,
    OUT EFI_BROWSER_ACTION_REQUEST              *ActionRequest
);

struct _EFI_HII_CONFIG_ACCESS_PROTOCOL {
    EFI_HII_ACCESS_EXTRACT_CONFIG   ExtractConfig;
    EFI_HII_ACCESS_ROUTE_CONFIG     RouteConfig;
    EFI_HII_ACCESS_FORM_CALLBACK    Callback;
};

#endif // EFI_PROTOCOL_HII_CONFIGURATIONACCESS_H
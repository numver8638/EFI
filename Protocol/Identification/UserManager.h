#ifndef EFI_PROTOCOL_IDENTIFICATION_USERMANAGER_H
#define EFI_PROTOCOL_IDENTIFICATION_USERMANAGER_H

#include <EFI/Types.h>
#include <EFI/Protocol/Identification/UserInfo.h>

#define EFI_USER_MANAGER_PROTOCOL_GUID \
    { 0x6FD5B00C, 0xD426, 0x4283, { 0x98, 0x87, 0x6C, 0xF5, 0xCF, 0x1C, 0xB1, 0xFE } }

typedef struct _EFI_USER_MANAGER_PROTOCOL EFI_USER_MANAGER_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_USER_PROFILE_CREATE) (
    IN CONST EFI_USER_MANAGER_PROTOCOL  *This,
    OUT EFI_USER_PROFILE_HANDLE         *User
);

typedef
EFI_STATUS
(EFIAPI *EFI_USER_PROFILE_DELETE) (
    IN CONST EFI_USER_MANAGER_PROTOCOL  *This,
    IN EFI_USER_PROFILE_HANDLE          User
);

typedef
EFI_STATUS
(EFIAPI *EFI_USER_PROFILE_GET_NEXT) (
    IN CONST EFI_USER_MANAGER_PROTOCOL  *This,
    IN OUT EFI_USER_PROFILE_HANDLE      *User
);

typedef
EFI_STATUS
(EFIAPI *EFI_USER_PROFILE_CURRENT) (
    IN CONST EFI_USER_MANAGER_PROTOCOL  *This,
    OUT EFI_USER_PROFILE_HANDLE         *CurrentUser
);

typedef
EFI_STATUS
(EFIAPI *EFI_USER_PROFILE_IDENTIFY) (
    IN CONST EFI_USER_MANAGER_PROTOCOL  *This,
    OUT EFI_USER_PROFILE_HANDLE         *User
);

typedef
EFI_STATUS
(EFIAPI *EFI_USER_PROFILE_FIND) (
    IN CONST EFI_USER_MANAGER_PROTOCOL  *This,
    IN OUT EFI_USER_PROFILE_HANDLE      *User,
    IN OUT EFI_USER_INFO_HANDLE         *UserInfo, OPTIONAL
    IN CONST EFI_USER_INFO              *Info,
    IN UINTN                            InfoSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_USER_PROFILE_NOTIFY) (
    IN CONST EFI_USER_MANAGER_PROTOCOL  *This,
    IN EFI_HANDLE                       Changed
);

typedef
EFI_STATUS
(EFIAPI *EFI_USER_PROFILE_GET_INFO) (
    IN CONST EFI_USER_MANAGER_PROTOCOL  *This,
    IN EFI_USER_PROFILE_HANDLE          User,
    IN EFI_USER_INFO_HANDLE             UserInfo,
    OUT EFI_USER_INFO                   *Info,
    IN OUT UINTN                        *InfoSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_USER_PROFILE_SET_INFO) (
    IN CONST EFI_USER_MANAGER_PROTOCOL  *This,
    IN EFI_USER_PROFILE_HANDLE          User,
    IN OUT EFI_USER_INFO_HANDLE         *UserInfo,
    IN CONST EFI_USER_INFO              *Info,
    IN UINTN                            InfoSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_USER_PROFILE_DELETE_INFO) (
    IN CONST EFI_USER_MANAGER_PROTOCOL  *This,
    IN EFI_USER_PROFILE_HANDLE          User,
    IN EFI_USER_INFO_HANDLE             UserInfo
);

typedef
EFI_STATUS
(EFIAPI *EFI_USER_PROFILE_GET_NEXT_INFO) (
    IN CONST EFI_USER_MANAGER_PROTOCOL  *This,
    IN EFI_USER_PROFILE_HANDLE          User,
    IN OUT EFI_USER_INFO_HANDLE         *UserInfo
);

struct _EFI_USER_MANAGER_PROTOCOL {
    EFI_USER_PROFILE_CREATE         Create;
    EFI_USER_PROFILE_DELETE         Delete;
    EFI_USER_PROFILE_GET_NEXT       GetNext;
    EFI_USER_PROFILE_CURRENT        Current;
    EFI_USER_PROFILE_IDENTIFY       Identify;
    EFI_USER_PROFILE_FIND           Find;
    EFI_USER_PROFILE_NOTIFY         Notify;
    EFI_USER_PROFILE_GET_INFO       GetInfo;
    EFI_USER_PROFILE_SET_INFO       SetInfo;
    EFI_USER_PROFILE_DELETE_INFO    DeleteInfo;
    EFI_USER_PROFILE_GET_NEXT_INFO  GetNextInfo;
};

#endif // EFI_PROTOCOL_IDENTIFICATION_USERMANAGER_H
#ifndef EFI_BOOTSERVICES_H
#define EFI_BOOTSERVICES_H

#include <EFI/Types.h>
#include <EFI/TableHeader.h>

#include <EFI/Protocol/Path/DevicePath.h>

#define EFI_BOOT_SERVICES_SIGNATURE ((UINT64)0x56524553544F4F42)
#define EFI_BOOT_SERVICES_REVISION  EFI_SPECIFICATION_VERSION

//
// Event, Timer and Task Priority Services
//

// Event Types
#define EVT_TIMER                         ((UINT32)0x80000000)
#define EVT_RUNTIME                       ((UINT32)0x40000000)
#define EVT_NOTIFY_WAIT                   ((UINT32)0x00000100)
#define EVT_NOTIFY_SIGNAL                 ((UINT32)0x00000200)
#define EVT_SIGNAL_EXIT_BOOT_SERVICES     ((UINT32)0x00000201)
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE ((UINT32)0x60000202)

// Event Groups
#define EFI_EVENT_GROUP_EXIT_BOOT_SERVICES \
    { 0x27ABF055, 0xB1B8, 0x4C26, { 0x80, 0x48, 0x74, 0x8F, 0x37, 0xBA, 0xA2, 0xDF }}
#define EFI_EVENT_GROUP_VIRTUAL_ADDRES_CHANGE \
    { 0x13FA7698, 0xC831, 0x49C7, { 0x87, 0xEA, 0x8F, 0x43, 0xFC, 0xC2, 0x51, 0x96 }}
#define EFI_EVENT_GROUP_MEMORY_MAP_CHANGE \
    { 0x78BEE926, 0x692F, 0x48FD, { 0x9E, 0xDB, 0x01, 0x42, 0x2E, 0xF0, 0xD7, 0xAB }}
#define EFI_EVENT_GROUP_READY_TO_BOOT \
    { 0x7CE88FB3, 0x4BD7, 0x4679, { 0x87, 0xA8, 0xA8, 0xD8, 0xDE, 0xE5, 0x0D, 0x2B }}

// EFI_EVENT_NOTIFY
typedef VOID (EFIAPI *EFI_EVENT_NOTIFY)(IN EFI_EVENT Event, IN VOID *Context);

// EFI_TIMER_DELAY
typedef enum {
    TimerCancel,
    TimerPeriodic,
    TimerRelative
} EFI_TIMER_DELAY;

// Tasi Priority Levels
#define TPL_APPLICATION ((EFI_TPL)4)
#define TPL_CALLBACK    ((EFI_TPL)8)
#define TPL_NOTIFY      ((EFI_TPL)16)
#define TPL_HIGH_LEVEL  ((EFI_TPL)31)

typedef
EFI_STATUS
(EFIAPI *EFI_CREATE_EVENT) (
    IN UINT32           Type,
    IN EFI_TPL          NotifyTpl,
    IN EFI_EVENT_NOTIFY NotifyFunction OPTIONAL,
    IN VOID             *NotifyContext OPTIONAL,
    OUT EFI_EVENT       *Event
);

typedef
EFI_STATUS
(EFIAPI *EFI_CREATE_EVENT_EX) (
    IN UINT32           Type,
    IN EFI_TPL          NotifyTpl,
    IN EFI_EVENT_NOTIFY NotifyFunction OPTIONAL,
    IN CONST VOID       *NotifyContext OPTIONAL,
    IN CONST EFI_GUID   *EventGroup OPTIONAL,
    OUT EFI_EVENT       *Event
);

typedef
EFI_STATUS
(EFIAPI *EFI_CLOSE_EVENT) (
    IN EFI_EVENT Event
);

typedef
EFI_STATUS
(EFIAPI *EFI_SIGNAL_EVENT) (
    IN EFI_EVENT Event
);

typedef
EFI_STATUS
(EFIAPI *EFI_WAIT_FOR_EVENT) (
    IN UINTN     NumberOfEvents,
    IN EFI_EVENT *Event,
    OUT UINTN    *Index
);

typedef
EFI_STATUS
(EFIAPI *EFI_CHECK_EVENT) (
    IN EFI_EVENT Event
);

typedef
EFI_STATUS
(EFIAPI *EFI_SET_TIMER) (
    IN EFI_EVENT       Event,
    IN EFI_TIMER_DELAY Type,
    IN UINT64          TriggerTime
);

typedef
EFI_TPL
(EFIAPI *EFI_RAISE_TPL) (
    IN EFI_TPL NewTpl
);

typedef
VOID
(EFIAPI *EFI_RESTORE_TPL) (
    IN EFI_TPL OldTpl
);

//
// Memory Services
//
typedef
EFI_STATUS
(EFIAPI *EFI_ALLOCATE_PAGES) (
    IN EFI_ALLOCATE_TYPE        Type,
    IN EFI_MEMORY_TYPE          MemoryType,
    IN UINTN                    Pages,
    IN OUT EFI_PHYSICAL_ADDRESS *Memory
);

typedef
EFI_STATUS
(EFIAPI *EFI_FREE_PAGES) (
    IN EFI_PHYSICAL_ADDRESS Memory,
    IN UINTN                Pages
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_MEMORY_MAP) (
    IN OUT UINTN                 *MemoryMapSize,
    IN OUT EFI_MEMORY_DESCRIPTOR *MeoryMap,
    OUT UINTN                    *MapKey,
    OUT UINTN                    *DescriptorSize,
    OUT UINT32                   *DescriptorVersion
);

typedef
EFI_STATUS
(EFIAPI *EFI_ALLOCATE_POOL) (
    IN EFI_MEMORY_TYPE PoolType,
    IN UINTN           Size,
    OUT VOID           **Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_FREE_POOL) (
    IN VOID *Buffer
);

//
// Protocol Handler Services
//

// EFI_INTERFACE_TYPE
typedef enum {
    EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;

// EFI_LOCATE_SEARCH_TYPE
typedef enum {
    AllHandles,
    ByRegisterNotify,
    ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL   ((UINT32)0x00000001)
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL         ((UINT32)0x00000002)
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL        ((UINT32)0x00000004)
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER  ((UINT32)0x00000008)
#define EFI_OPEN_PROTOCOL_BY_DRIVER            ((UINT32)0x00000010)
#define EFI_OPEN_PROTOCOL_EXECLUSIVE           ((UINT32)0x00000020)

// EFI_OPEN_PROTOCOL_INFORMATION_ENTRY
typedef struct {
    EFI_HANDLE AgentHandle;
    EFI_HANDLE ControllerHandle;
    UINT32 Attributes;
    UINT32 OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

typedef
EFI_STATUS
(EFIAPI *EFI_INSTALL_PROTOCOL_INTERFACE) (
    IN OUT EFI_HANDLE     *Handle,
    IN EFI_GUID           *Protocol,
    IN EFI_INTERFACE_TYPE InterfaceType,
    IN VOID               *Interface
);

typedef
EFI_STATUS
(EFIAPI *EFI_UNINSTALL_PROTOCOL_INTERFACE) (
    IN EFI_HANDLE Handle,
    IN EFI_GUID   *Protocol,
    IN VOID       *Interface
);

typedef
EFI_STATUS
(EFIAPI *EFI_REINSTALL_PROTOCOL_INTERFACE) (
    IN EFI_HANDLE Handle,
    IN EFI_GUID   *Protocol,
    IN VOID       *OldInterface,
    IN VOID       *NewInterface
);

typedef
EFI_STATUS
(EFIAPI *EFI_REGISTER_PROTOCOL_NOTIFY) (
    IN EFI_GUID  *Protocol,
    IN EFI_EVENT Event,
    OUT VOID     **Registration
);

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_HANDLE) (
    IN EFI_LOCATE_SEARCH_TYPE SearchType,
    IN EFI_GUID               *Protocol OPTIONAL,
    IN VOID                   *SearchKey OPTIONAL,
    IN OUT UINTN              *BufferSize,
    OUT EFI_HANDLE            *Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_HANDLE_PROTOCOL) (
    IN EFI_HANDLE Handle,
    IN EFI_GUID   *Protocol,
    OUT VOID      **Interface
);

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_DEVICE_PATH) (
    IN EFI_GUID                     *Protocol,
    IN OUT EFI_DEVICE_PATH_PROTOCOL **DevicePath,
    OUT EFI_HANDLE                  *Device
);
typedef
EFI_STATUS
(EFIAPI *EFI_OPEN_PROTOCOL) (
    IN EFI_HANDLE Handle,
    IN EFI_GUID   *Protocol,
    OUT VOID      **Interface OPTIONAL,
    IN EFI_HANDLE AgentHandle,
    IN EFI_HANDLE ControllerHandle,
    IN UINT32     Attributes
);

typedef
EFI_STATUS
(EFIAPI *EFI_CLOSE_PROTOCOL) (
    IN EFI_HANDLE Handle,
    IN EFI_GUID   *Protocol,
    IN EFI_HANDLE AgentHandle,
    IN EFI_HANDLE ControllerHandle
);

typedef
EFI_STATUS
(EFIAPI *EFI_OPEN_PROTOCOL_INFORMATION) (
    IN EFI_HANDLE                           Handle,
    IN EFI_GUID                             *Protocol,
    OUT EFI_OPEN_PROTOCOL_INFORMATION_ENTRY **EntryBuffer,
    OUT UINTN                               *EntryCount
);

typedef
EFI_STATUS
(EFIAPI *EFI_CONNECT_CONTROLLER) (
    IN EFI_HANDLE               ControllerHandle,
    IN EFI_HANDLE               *DriverImageHandle OPTIONAL,
    IN EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL,
    IN BOOLEAN                  Recursive
);

typedef
EFI_STATUS
(EFIAPI *EFI_DISCONNECT_CONTROLLER) (
    IN EFI_HANDLE ControllerHandle,
    IN EFI_HANDLE DriverImageHandle OPTIONAL,
    IN EFI_HANDLE ChildHandle OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_PROTOCOL_PER_HANDLE) (
    IN EFI_HANDLE Handle,
    OUT EFI_GUID  ***ProtocolBuffer,
    OUT UINTN     *ProtocolBufferCount
);

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_HANDLE_BUFFER) (
    IN EFI_LOCATE_SEARCH_TYPE SearchType,
    IN EFI_GUID               *Protocol OPTIONAL,
    IN VOID                   *SearchKey OPTIONAL,
    IN OUT UINTN              *NoHandles,
    OUT EFI_HANDLE            **Buffer
);

typedef
EFI_STATUS
(EFIAPI *EFI_LOCATE_PROTOCOL) (
    IN EFI_GUID *Protocol,
    IN VOID     *Registration OPTIONAL,
    OUT VOID    **Interface
);

typedef
EFI_STATUS
(EFIAPI *EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES) (
    IN OUT EFI_HANDLE *Handle,
    ...
);

typedef
EFI_STATUS
(EFIAPI *EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES) (
    IN EFI_HANDLE Handle,
    ...
);

//
// Image Services
//

#define EFI_HII_PACKAGE_LIST_PROTOCOL_GUID \
    { 0x6A1EE763, 0xD47A, 0x43Ba, { 0xAA, 0xBE, 0xEF, 0x1D, 0xE2, 0xAB, 0x56, 0xFC } }

typedef struct EFI_HII_PACKAGE_LIST_HEADER *EFI_HII_PACKAGE_LIST_PROTOCOL;
typedef struct EFI_SYSTEM_TABLE EFI_SYSTEM_TABLE;

// EFI_IMAGE_ENTRY_POINT
typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_ENTRY_POINT) (
    IN EFI_HANDLE,
    IN EFI_SYSTEM_TABLE*
);

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_LOAD) (
    IN BOOLEAN                  BootPolicy,
    IN EFI_HANDLE               ParentImageHandle,
    IN EFI_DEVICE_PATH_PROTOCOL *DevicePath,
    IN VOID                     *SourceBuffer OPTIONAL,
    IN UINTN                    SourceSize,
    OUT EFI_HANDLE              *ImageHandle
);

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_START) (
    IN EFI_HANDLE ImageHandle,
    OUT UINTN     *ExitDataSize,
    OUT CHAR16    **ExitData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_IMAGE_UNLOAD) (
    IN EFI_HANDLE ImageHandle
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXIT) (
    IN EFI_HANDLE ImageHandle,
    IN EFI_STATUS ExitStatus,
    IN UINTN      ExitDataSize,
    IN CHAR16     *ExitData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXIT_BOOT_SERVICES) (
    IN EFI_HANDLE ImageHandle,
    IN UINTN      MapKey
);

//
// Miscellaneous Services
//
typedef
EFI_STATUS
(EFIAPI *EFI_SET_WATCHDOG_TIMER) (
    IN UINTN  Timeout,
    IN UINT64 WatchdogCode,
    IN UINTN  DataSize,
    IN CHAR16 *WatchdogData OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_STALL) (
    IN UINTN Microseconds
);

typedef
VOID
(EFIAPI *EFI_COPY_MEM) (
    IN VOID  *Destination,
    IN VOID  *Source,
    IN UINTN Length
);

typedef
VOID
(EFIAPI *EFI_SET_MEM) (
    IN VOID  *Buffer,
    IN UINTN Size,
    IN UINT8 Value
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_NEXT_MONOTONIC_COUNT) (
    OUT UINT64 *Count
);

typedef
EFI_STATUS
(EFIAPI *EFI_INSTALL_CONFIGURATION_TABLE) (
    IN EFI_GUID *Guid,
    IN VOID     *Table
);

typedef
EFI_STATUS
(EFIAPI *EFI_CALCULATE_CRC32) (
    IN VOID    *Data,
    IN UINTN   DataSize,
    OUT UINT32 *Crc32
);



typedef struct {
    EFI_TABLE_HEADER                           Hdr;

    //
    // Task Priority Services
    //
    EFI_RAISE_TPL                              RaiseTPL;
    EFI_RESTORE_TPL                            RestoreTPL;


    //
    // Memory Services
    //
    EFI_ALLOCATE_PAGES                         AllocatePages;
    EFI_FREE_PAGES                             FreePages;
    EFI_GET_MEMORY_MAP                         GetMemoryMap;
    EFI_ALLOCATE_POOL                          AllocatePool;
    EFI_FREE_POOL                              FreePool;

    //
    // Event & Timer Services
    //
    EFI_CREATE_EVENT                           CreateEvent;
    EFI_SET_TIMER                              SetTimer;
    EFI_WAIT_FOR_EVENT                         WaitForEvent;
    EFI_SIGNAL_EVENT                           SignalEvent;
    EFI_CLOSE_EVENT                            CloseEvent;
    EFI_CHECK_EVENT                            CheckEvent;

    //
    // Protocol Handler Services
    //
    EFI_INSTALL_PROTOCOL_INTERFACE             InstallProtocolInterface;
    EFI_REINSTALL_PROTOCOL_INTERFACE           ReinstallProtocolInterface;
    EFI_UNINSTALL_PROTOCOL_INTERFACE           UninstallProtocolInterface;
    EFI_HANDLE_PROTOCOL                        HandleProtocol;
    VOID*                                      Reserved;
    EFI_REGISTER_PROTOCOL_NOTIFY               RegisterProtocolNotify;
    EFI_LOCATE_HANDLE                          LocateHandle;
    EFI_LOCATE_DEVICE_PATH                     LocateDevicePath;
    EFI_INSTALL_CONFIGURATION_TABLE            InstallConfigurationTable;

    //
    // Image Services
    //
    EFI_IMAGE_LOAD                             LoadImage;
    EFI_IMAGE_START                            StartImage;
    EFI_EXIT                                   Exit;
    EFI_IMAGE_UNLOAD                           UnloadImage;
    EFI_EXIT_BOOT_SERVICES                     ExitBootServices;

    //
    // Miscellaneous Services
    //
    EFI_GET_NEXT_MONOTONIC_COUNT               GetNextMonotonicCount;
    EFI_STALL                                  Stall;
    EFI_SET_WATCHDOG_TIMER                     SetWatchdogTimer;

    //
    // Driver Support Services
    //
    EFI_CONNECT_CONTROLLER                     ConnectController;
    EFI_DISCONNECT_CONTROLLER                  DisconnectController;

    //
    // Open and Close Protocol Services
    //
    EFI_OPEN_PROTOCOL                          OpenProtocol;
    EFI_CLOSE_PROTOCOL                         CloseProtocol;
    EFI_OPEN_PROTOCOL_INFORMATION              OpenProtocolInformation;

    //
    // Library Services
    //
    EFI_PROTOCOL_PER_HANDLE                   ProtocolsPerHandle;
    EFI_LOCATE_HANDLE_BUFFER                   LocateHandleBuffer;
    EFI_LOCATE_PROTOCOL                        LocateProtocol;
    EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES   InstallMultipleProtocolInterfaces;
    EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES UninstallMultipleProtocolInterfaces;

    //
    // 32-bit CRC Services
    //
    EFI_CALCULATE_CRC32                        CalculateCrc32;

    //
    // Miscellaneous Services
    //
    EFI_COPY_MEM                               CopyMem;
    EFI_SET_MEM                                SetMem;
    EFI_CREATE_EVENT_EX                        CreateEventEx;
} EFI_BOOT_SERVICES;

#endif // EFI_BOOTSERVICES_H
#ifndef EFI_PROTOCOL_EBC_INTERPRETER_H
#define EFI_PROTOCOL_EBC_INTERPRETER_H

#include <EFI/Types.h>

#define EFI_EBC_PROTOCOL_GUID \
    { 0x13AC6DD1, 0x73D0, 0x11D4, { 0xB0, 0x6B, 0x00, 0xAA, 0x00, 0xBD, 0x6D, 0xE7 } }

typedef struct _EFI_EBC_PROTOCOL EFI_EBC_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EBC_ICACHE_FLUSH) (
    IN EFI_PHYSICAL_ADDRESS Start,
    IN UINT64               Length
);

typedef
EFI_STATUS
(EFIAPI *EFI_EBC_CREATE_THUNK) (
    IN EFI_EBC_PROTOCOL *This,
    IN EFI_HANDLE       ImageHandle,
    IN VOID             *EbcEntryPoint,
    OUT VOID            **Thunk
);

typedef
EFI_STATUS
(EFIAPI *EFI_EBC_UNLOAD_IMAGE) (
    IN EFI_EBC_PROTOCOL *This,
    IN EFI_HANDLE       ImageHandle
);

typedef
EFI_STATUS
(EFIAPI *EFI_EBC_REGISTER_ICACHE_FLUSH) (
    IN EFI_EBC_PROTOCOL *This,
    IN EBC_ICACHE_FLUSH *Flush
);

typedef
EFI_STATUS
(EFIAPI *EFI_EBC_GET_VERSION) (
    IN EFI_EBC_PROTOCOL *This,
    OUT UINT64          *Version
);

struct _EFI_EBC_PROTOCOL {
    EFI_EBC_CREATE_THUNK            CreateThunk;
    EFI_EBC_UNLOAD_IMAGE            UnloadImage;
    EFI_EBC_REGISTER_ICACHE_FLUSH   RegisterICacheFlush;
    EFI_EBC_GET_VERSION             GetVersion;
};

#endif // EFI_PROTOCOL_EBC_INTERPRETER_H
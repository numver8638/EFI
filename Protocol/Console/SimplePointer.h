#ifndef EFI_PROTOCOL_CONSOLE_SIMPLEPOINTER_H
#define EFI_PROTOCOL_CONSOLE_SIMPLEPOINTER_H

#include <EFI/Types.h>

#define EFI_SIMPLE_POINTER_PROTOCOL_GUID \
    { 0x31878C87, 0x0B75, 0x11D5, { 0x9A, 0x4F, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } }

typedef struct _EFI_SIMPLE_POINTER_PROTOCOL EFI_SIMPLE_POINTER_PROTOCOL;

//
// EFI_SIMPLE_POINTER_MODE
//
typedef struct {
    UINT64          ResolutionX;
    UINT64          ResolutionY;
    UINT64          ResolutionZ;
    BOOLEAN         LeftButton;
    BOOLEAN         RightButton;
} EFI_SIMPLE_POINTER_MODE;

//
// EFI_SIMPLE_POINTER_STATE
//
typedef struct {
    INT32       RelativeMovementX;
    INT32       RelativeMovementY;
    INT32       RelativeMovementZ;
    BOOLEAN     LeftButton;
    BOOLEAN     RightButton;
} EFI_SIMPLE_POINTER_STATE;

typedef
EFI_STATUS
(EFIAPI *EFI_SIMPLE_POINTER_RESET) (
    IN EFI_SIMPLE_POINTER_PROTOCOL  *This,
    IN BOOLEAN                      ExtendedVerification
);

typedef
EFI_STATUS
(EFIAPI *EFI_SIMPLE_POINTER_GET_STATE) (
    IN EFI_SIMPLE_POINTER_PROTOCOL      *This,
    IN OUT EFI_SIMPLE_POINTER_STATE     *State
);

struct _EFI_SIMPLE_POINTER_PROTOCOL {
    EFI_SIMPLE_POINTER_RESET        Reset;
    EFI_SIMPLE_POINTER_GET_STATE    GetState;
    EFI_EVENT                       WaitForInput;
    EFI_SIMPLE_POINTER_MODE         *Mode;
};

#endif // EFI_PROTOCOL_CONSOLE_SIMPLEPOINTER_H
#ifndef EFI_PROTOCOL_MEDIA_STORAGESECURITYCOMMAND_H
#define EFI_PROTOCOL_MEDIA_STORAGESECURITYCOMMAND_H

#include <EFI/Types.h>

#define EFI_STORAGE_SECURITY_COMMAND_PROTOCOL_GUID \
    { 0xC88B0B6D, 0x0DFC, 0x49A7, { 0x9C, 0xB4, 0x49, 0x07, 0x4B, 0x4C, 0x3A, 0x78 } }

typedef struct _EFI_STORAGE_SECURITY_PROTOCOL EFI_STORAGE_SECURITY_COMMAND_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_STORAGE_SECURITY_RECEIVE_DATA) (
    IN EFI_STORAGE_SECURITY_COMMAND_PROTOCOL    *This,
    IN UINT32                                   MediaId,
    IN UINT64                                   Timeout,
    IN UINT8                                    SecurityProtocol,
    IN UINT16                                   SecurityProtocolSpecificData,
    IN UINTN                                    PayloadBufferSize,
    OUT VOID                                    *PayloadBuffer,
    OUT UINTN                                   *PayloadTransferSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_STORAGE_SECURITY_SEND_DATA) (
    IN EFI_STORAGE_SECURITY_COMMAND_PROTOCOL    *This,
    IN UINT32                                   MediaId,
    IN UINT64                                   Timeout,
    IN UINT8                                    SecurityProtocol,
    IN UINT16                                   SecurityProtocolSpecificData,
    IN UINTN                                    PayloadBufferSize,
    IN VOID                                     *PayloadBuffer
);

struct _EFI_STORAGE_SECURITY_PROTOCOL {
    EFI_STORAGE_SECURITY_RECEIVE_DATA   ReceiveData;
    EFI_STORAGE_SECURITY_SEND_DATA      SendData;
};

#endif // EFI_PROTOCOL_MEDIA_STORAGESECURITYCOMMAND_H
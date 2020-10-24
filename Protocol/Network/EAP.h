#ifndef EFI_PROTOCOL_NETWORK_EAP_H
#define EFI_PROTOCOL_NETWORK_EAP_H

#include <EFI/Types.h>

#define EFI_EAP_PROTOCOL_GUID \
    { 0x5D9F96DB, 0xE731, 0x4CAA, { 0xA0, 0x0D, 0x72, 0xE1, 0x87, 0xCD, 0x77, 0x62 } }

typedef struct _EFI_EAP_PROTOCOL EFI_EAP_PROTOCOL;

//
// Type for the identification number assigned to the Port
// by the system in which the Port resides.
//
typedef VOID* EFI_PORT_HANDLE;

//
// EAP Authentication Method Type (RFC 3748)
//
#define EFI_EAP_TYPE_TLS    (13)    // REQUIRED - RFC 5126

typedef
EFI_STATUS
(EFIAPI *EFI_EAP_BUILD_RESPONSE_PACKET) (
    IN EFI_PORT_HANDLE      PortNumber,
    IN UINT8                *RequestBuffer,
    IN UINTN                RequestSize,
    IN UINT8                *Buffer,
    IN OUT UINTN            *BufferSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_EAP_SET_DESIRED_AUTHENTICATION_METHOD) (
    IN EFI_EAP_PROTOCOL     *This,
    IN UINT8                EapAuthType
);

typedef
EFI_STATUS
(EFIAPI *EFI_EAP_REGISTER_AUTHENTICATION_METHOD) (
    IN EFI_EAP_PROTOCOL                 *This,
    IN UINT8                            EapAuthType,
    IN EFI_EAP_BUILD_RESPONSE_PACKET    Handler
);

struct _EFI_EAP_PROTOCOL {
    EFI_EAP_SET_DESIRED_AUTHENTICATION_METHOD   SetDesiredAuthMethod;
    EFI_EAP_REGISTER_AUTHENTICATION_METHOD      RegisterAuthMethod;
};

#endif // EFI_PROTOCOL_NETWORK_EAP_H
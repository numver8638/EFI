#ifndef EFI_PROTOCOL_NETWORK_EAPMANAGEMENT_H
#define EFI_PROTOCOL_NETWORK_EAPMANAGEMENT_H

#include <EFI/Types.h>

#define EFI_EAP_MANAGEMENT_PROTOCOL_GUID \
    { 0xBB62E663, 0x625D, 0x40B2, { 0xA0, 0x88, 0xBB, 0xE8, 0x36, 0x23, 0xA2, 0x45 } }

typedef struct _EFI_EAP_MANAGEMENT_PROTOCOL EFI_EAP_MANAGEMENT_PROTOCOL;

//
// Type for the identification number assigned to the Port
// by the system in which the Port resides.
//
typedef VOID* EFI_PORT_HANDLE;

//
// PAE Capabilities
//
#define PAE_SUPPORT_AUTHENTICATOR       (0x01)
#define PAE_SUPPORT_SUPPLICANT          (0x02)

//
// EFI_EAPOL_PORT_INFO
//
typedef struct {
    EFI_PORT_HANDLE     PortNumber;
    UINT8               ProtocolVersion;
    UINT8               PaeCapabilities;
} EFI_EAPOL_PORT_INFO;

//
// Supplicant PAE state machine (IEEE Std 802.1X Section 8.5.10)
//
typedef enum {
    Logoff,
    Disconnected,
    Connecting,
    Acquired,
    Authenticating,
    Held,
    Authenticated,
    MaxSupplicantPaeState
} EFI_EAPOL_SUPPLICANT_PAE_STATE;

//
// Definitions for ValidFieldMask
//
#define AUTH_PERIOD_FIELD_VALID     (0x01)
#define HELD_PERIOD_FIELD_VALID     (0x02)
#define START_PERIOD_FIELD_VALID    (0x04)
#define MAX_START_FILED_VALID       (0x08)

//
// EFI_EAPOL_SUPPLICANT_PAE_CONFIGURATION
//
typedef struct {
    UINT8       ValidFieldMask;
    UINTN       AuthPeriod;
    UINTN       HeldPeriod;
    UINTN       StartPeriod;
    UINTN       MaxStart;
} EFI_EAPOL_SUPPLICANT_PAE_CONFIGURATION;

//
// Supplicant Statistics (IEEE Std 802.1X Section 9.5.2)
//
typedef struct {
    UINTN       EapolFramesReceived;
    UINTN       EapolFramesTransmitted;
    UINTN       EapolStartFramesTransmitted;
    UINTN       EapolLogoffFramesTransmitted;
    UINTN       EapRespIdFramesTransmitted;
    UINTN       EapResponseFramesTransmitted;
    UINTN       EapReqIdFramesTransmitted;
    UINTN       EapRequestFramesTransmitted;
    UINTN       InvalidEapolFramesReceived;
    UINTN       EapLengthErrorFramesReceived;
    UINTN       LastEapolFrameVersion;
    UINTN       LastEapolFrameSource;
} EFI_EAPOL_SUPPLICANT_PAE_STATISTICS;

typedef
EFI_STATUS
(EFIAPI *EFI_EAP_GET_SYSTEM_CONFIGURATION) (
    IN EFI_EAP_MANAGEMENT_PROTOCOL      *This,
    OUT BOOLEAN                         *SystemAuthControl,
    OUT EFI_EAPOL_PORT_INFO             *PortInfo OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_EAP_SET_SYSTEM_CONFIGURATION) (
    IN EFI_EAP_MANAGEMENT_PROTOCOL      *This,
    IN BOOLEAN                          SystemAuthControl
);

typedef
EFI_STATUS
(EFIAPI *EFI_EAP_INITIALIZE_PORT) (
    IN EFI_EAP_MANAGEMENT_PROTOCOL      *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_EAP_USER_LOGON) (
    IN EFI_EAP_MANAGEMENT_PROTOCOL      *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_EAP_USER_LOGOFF) (
    IN EFI_EAP_MANAGEMENT_PROTOCOL      *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_EAP_GET_SUPPLICANT_STATUS) (
    IN EFI_EAP_MANAGEMENT_PROTOCOL                  *This,
    OUT EFI_EAPOL_SUPPLICANT_PAE_STATE              *CurrentState,
    IN OUT EFI_EAPOL_SUPPLICANT_PAE_CONFIGURATION   *Configuration OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_EAP_SET_SUPPLICANT_STATUS) (
    IN EFI_EAP_MANAGEMENT_PROTOCOL                  *This,
    IN EFI_EAPOL_SUPPLICANT_PAE_CONFIGURATION       *Configuration OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_EAP_SET_SYSTEM_CONFIGURATION) (
    IN EFI_EAP_MANAGEMENT_PROTOCOL              *This,
    IN EFI_EAPOL_SUPPLICANT_PAE_CONFIGURATION   *Configuration
);

typedef
EFI_STATUS
(EFIAPI *EFI_EAP_GET_SUPPLICANT_STATISTICS) (
    IN EFI_EAP_MANAGEMENT_PROTOCOL              *This,
    OUT EFI_EAPOL_SUPPLICANT_PAE_STATISTICS     *Statistics
);

struct _EFI_EAP_MANAGEMENT_PROTOCOL {
    EFI_EAP_GET_SYSTEM_CONFIGURATION        GetSystemConfiguration;
    EFI_EAP_SET_SYSTEM_CONFIGURATION        SetSystemConfiguration;
    EFI_EAP_INITIALIZE_PORT                 InitializePort;
    EFI_EAP_USER_LOGON                      UserLogon;
    EFI_EAP_USER_LOGOFF                     UserLogoff;
    EFI_EAP_GET_SUPPLICANT_STATUS           GetSupplicantStatus;
    EFI_EAP_SET_SUPPLICANT_STATUS           SetSupplicantStatus;
    EFI_EAP_GET_SUPPLICANT_STATISTICS       GetSupplicantStatistics;
};

#endif // EFI_PROTOCOL_NETWORK_EAPMANAGEMENT_H
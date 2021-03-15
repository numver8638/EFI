#ifndef EFI_PROTOCOL_SCSI_SCSIPASSTHRU_H
#define EFI_PROTOCOL_SCSI_SCSIPASSTHRU_H

#include <EFI/Types.h>
#include <EFI/Protocol/Path/DevicePath.h>

#define EFI_EXT_SCSI_PASS_THRU_PROTOCOL_GUID \
    { 0x143B7632, 0xB81B, 0x4CB7, { 0xAB, 0xD3, 0xB6, 0x25, 0xA5, 0xB9, 0xBF, 0xFE } }

typedef struct _EFI_EXT_SCSI_PASS_THRU_PROTOCOL EFI_EXT_SCSI_PASS_THRU_PROTOCOL;

//
// EFI_EXT_SCSI_PASS_THRU_MODE
//
typedef struct {
    UINT32  AdapterId;
    UINT32  Attributes;
    UINT32  IoAlign;
} EFI_EXT_SCSI_PASS_THRU_MODE;

#define TARGET_MAX_BYTES    (0x10)

#define EFI_EXT_SCSI_PASS_THRU_ATTRIBUTES_PHYSICAL      (0x0001)
#define EFI_EXT_SCSI_PASS_THRU_ATTRIBUTES_LOGICAL       (0x0002)
#define EFI_EXT_SCSI_PASS_THRU_ATTRIBUTES_NONBLOCKIO    (0x0004)

//
// EFI_EXT_SCSI_PASS_THRU_SCSI_REQUEST_PACKET
//
typedef struct {
    UINT64      Timeout;
    VOID        *InDataBuffer;
    VOID        *OutDataBuffer;
    VOID        *SenseData;
    VOID        *Cdb;
    UINT32      InTransferLength;
    UINT32      OutTransferLength;
    UINT8       CdbLength;
    UINT8       DataDirection;
    UINT8       HostAdapterStatus;
    UINT8       TargetStatus;
    UINT8       SenseDataLength;
} EFI_EXT_SCSI_PASS_THRU_SCSI_REQUEST_PACKET;

//
// DataDirection
//
#define EFI_EXT_SCSI_DATA_DIRECTION_READ             (0)
#define EFI_EXT_SCSI_DATA_DIRECTION_WRITE            (1)
#define EFI_EXT_SCSI_DATA_DIRECTION_BIDIRECTIONAL    (2)

//
// HostAdapterStatus
//
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_OK                      (0x00)
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_TIMEOUT_COMMAND         (0x09) 
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_TIMEOUT                 (0x0B) 
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_MESSAGE_REJECT          (0x0D) 
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_BUS_RESET               (0x0E)
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_PARITY_ERROR            (0x0F)
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_REQUEST_SENSE_FAILED    (0x10)
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_SELECTION_TIMEOUT       (0x11)
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_DATA_OVERRUN_UNDERRUN   (0x12)
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_BUS_FREE                (0x13)
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_PHASE_ERROR             (0x14)
#define EFI_EXT_SCSI_STATUS_HOST_ADAPTER_OTHER                   (0x7F)

//
// TargetStatus
//
#define EFI_EXT_SCSI_STATUS_TARGET_GOOD                          (0x00)
#define EFI_EXT_SCSI_STATUS_TARGET_CHECK_CONDITION               (0x02)
#define EFI_EXT_SCSI_STATUS_TARGET_CONDITION_MET                 (0x04)
#define EFI_EXT_SCSI_STATUS_TARGET_BUSY                          (0x08)
#define EFI_EXT_SCSI_STATUS_TARGET_INTERMEDIATE                  (0x10)
#define EFI_EXT_SCSI_STATUS_TARGET_INTERMEDIATE_CONDITION_MET    (0x14)
#define EFI_EXT_SCSI_STATUS_TARGET_RESERVATION_CONFLICT          (0x18)
#define EFI_EXT_SCSI_STATUS_TARGET_TASK_SET_FULL                 (0x28)
#define EFI_EXT_SCSI_STATUS_TARGET_ACA_ACTIVE                    (0x30)
#define EFI_EXT_SCSI_STATUS_TARGET_TASK_ABORTED                  (0x40)

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_PASSTHRU) (
    IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL                  *This,
    IN UINT8                                            *Target,
    IN UINT64                                           Lun,
    IN OUT EFI_EXT_SCSI_PASS_THRU_SCSI_REQUEST_PACKET   *Packet,
    IN EFI_EVENT                                        Event OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_GET_NEXT_TARGET_LUN) (
    IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL  *This,
    IN OUT UINT8                        **Target,
    IN OUT UINT64                       *Lun
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_BUILD_DEVICE_PATH) (
    IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL      *This,
    IN UINT8                                *Target,
    IN UINT64                               Lun,
    IN OUT EFI_DEVICE_PATH_PROTOCOL         **DevicePath
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_GET_TARGET_LUN) (
    IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL      *This,
    IN EFI_DEVICE_PATH_PROTOCOL             **DevicePath,
    OUT UINT8                               **Target,
    OUT UINT64                              *Lun
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_RESET_CHANNEL) (
    IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL      *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_RESET_TARGET_LUN) (
    IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL      *This,
    IN UINT8                                *Target,
    IN UINT64                               Lun
);

typedef
EFI_STATUS
(EFIAPI *EFI_EXT_SCSI_PASS_THRU_GET_NEXT_TARGET) (
    IN EFI_EXT_SCSI_PASS_THRU_PROTOCOL      *This,
    IN OUT UINT8                            **Target
);

struct _EFI_EXT_SCSI_PASS_THRU_PROTOCOL {
    EFI_EXT_SCSI_PASS_THRU_MODE                 *Mode;
    EFI_EXT_SCSI_PASS_THRU_PASSTHRU             PassThru;
    EFI_EXT_SCSI_PASS_THRU_GET_NEXT_TARGET_LUN  GetNextTargetLun;
    EFI_EXT_SCSI_PASS_THRU_BUILD_DEVICE_PATH    BuildDevicePath;
    EFI_EXT_SCSI_PASS_THRU_GET_TARGET_LUN       GetTargetLun;
    EFI_EXT_SCSI_PASS_THRU_RESET_CHANNEL        ResetChannel;
    EFI_EXT_SCSI_PASS_THRU_RESET_TARGET_LUN     ResetTargetLun;
    EFI_EXT_SCSI_PASS_THRU_GET_NEXT_TARGET      GetNextTarget;
};

#endif // EFI_PROTOCOL_SCSI_SCSIPASSTHRU_H
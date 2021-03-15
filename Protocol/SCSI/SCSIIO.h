#ifndef EFI_PROTOCOL_SCSI_SCSIIO_H
#define EFI_PROTOCOL_SCSI_SCSIIO_H

#include <EFI/Types.h>

#define EFI_SCSI_IO_PROTOCOL_GUID \
    { 0x932F47E6, 0x2362, 0x4002, { 0x80, 0x3E, 0x3C, 0xD5, 0x4B, 0x13, 0x8F, 0x85 } }

typedef struct _EFI_SCSI_IO_PROTOCOL EFI_SCSI_IO_PROTOCOL;

//
// Device Types - Defined in the SCSI Primary Commands standard (e.g., SPC-4)
//
#define EFI_SCSI_IO_TYPE_DISK           (0x00) // Disk device
#define EFI_SCSI_IO_TYPE_TAPE           (0x01) // Tape device
#define EFI_SCSI_IO_TYPE_PRINTER        (0x02) // Printer
#define EFI_SCSI_IO_TYPE_PROCESSOR      (0x03) // Processor
#define EFI_SCSI_IO_TYPE_WORM           (0x04) // Write-once read-multiple
#define EFI_SCSI_IO_TYPE_CDROM          (0x05) // CD or DVD device
#define EFI_SCSI_IO_TYPE_SCANNER        (0x06) // Scanner device
#define EFI_SCSI_IO_TYPE_OPTICAL        (0x07) // Optical memory device
#define EFI_SCSI_IO_TYPE_MEDIUMCHANGER  (0x08) // Medium Changer device
#define EFI_SCSI_IO_TYPE_COMMUNICATION  (0x09) // Communications device
#define EFI_SCSI_IO_TYPE_A              (0x0A) // Obsolete
#define EFI_SCSI_IO_TYPE_B              (0x0B) // Obsolete
#define EFI_SCSI_IO_TYPE_RAID           (0x0C) // Storage array controller device (e.g., RAID)
#define EFI_SCSI_IO_TYPE_SES            (0x0D) // Enclosure services device
#define EFI_SCSI_IO_TYPE_RBC            (0x0E) // Simplified direct-access device (e.g., magnetic disk)
#define EFI_SCSI_IO_TYPE_OCRW           (0x0F) // Optical card reader/writer device
#define EFI_SCSI_IO_TYPE_BRIDGE         (0x10) // Bridge Controller Commands
#define EFI_SCSI_IO_TYPE_OSD            (0x11) // Object-based Storage device
#define EFI_SCSI_IO_TYPE_RESERVED_LOW   (0x12) // Reserved (low)
#define EFI_SCSI_IO_TYPE_RESERVED_HIGH  (0x1E) // Reserved (high)
#define EFI_SCSI_IO_TYPE_UNKNOWN        (0x1F) // Unknown no device type

// TODO: Is 'MFI' is typo of 'EFI' or correct?
#define MFI_SCSI_IO_TYPE_A              EFI_SCSI_IO_TYPE_A
#define MFI_SCSI_IO_TYPE_B              EFI_SCSI_IO_TYPE_B
#define MFI_SCSI_IO_TYPE_RAID           EFI_SCSI_IO_TYPE_RAID
#define MFI_SCSI_IO_TYPE_SES            EFI_SCSI_IO_TYPE_SES
#define MFI_SCSI_IO_TYPE_RBC            EFI_SCSI_IO_TYPE_RBC
#define MFI_SCSI_IO_TYPE_OCRW           EFI_SCSI_IO_TYPE_OCRW
#define MFI_SCSI_IO_TYPE_BRIDGE         EFI_SCSI_IO_TYPE_BRIDGE
#define MFI_SCSI_IO_TYPE_OSD            EFI_SCSI_IO_TYPE_OSD

//
// EFI_SCSI_IO_SCSI_REQUEST_PACKET
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
} EFI_SCSI_IO_SCSI_REQUEST_PACKET;

//
// DataDirection
//
#define EFI_SCSI_IO_DATA_DIRECTION_READ             (0)
#define EFI_SCSI_IO_DATA_DIRECTION_WRITE            (1)
#define EFI_SCSI_IO_DATA_DIRECTION_BIDIRECTIONAL    (2)

//
// HostAdapterStatus
//
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_OK                      (0x00)
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_TIMEOUT_COMMAND         (0x09) 
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_TIMEOUT                 (0x0B) 
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_MESSAGE_REJECT          (0x0D) 
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_BUS_RESET               (0x0E)
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_PARITY_ERROR            (0x0F)
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_REQUEST_SENSE_FAILED    (0x10)
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_SELECTION_TIMEOUT       (0x11)
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_DATA_OVERRUN_UNDERRUN   (0x12)
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_BUS_FREE                (0x13)
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_PHASE_ERROR             (0x14)
#define EFI_SCSI_IO_STATUS_HOST_ADAPTER_OTHER                   (0x7F)

//
// TargetStatus
//
#define EFI_SCSI_IO_STATUS_TARGET_GOOD                          (0x00)
#define EFI_SCSI_IO_STATUS_TARGET_CHECK_CONDITION               (0x02)
#define EFI_SCSI_IO_STATUS_TARGET_CONDITION_MET                 (0x04)
#define EFI_SCSI_IO_STATUS_TARGET_BUSY                          (0x08)
#define EFI_SCSI_IO_STATUS_TARGET_INTERMEDIATE                  (0x10)
#define EFI_SCSI_IO_STATUS_TARGET_INTERMEDIATE_CONDITION_MET    (0x14)
#define EFI_SCSI_IO_STATUS_TARGET_RESERVATION_CONFLICT          (0x18)
#define EFI_SCSI_IO_STATUS_TARGET_COMMAND_TERMINATED            (0x22)
#define EFI_SCSI_IO_STATUS_TARGET_QUEUE_FULL                    (0x28)

typedef
EFI_STATUS
(EFIAPI *EFI_SCSI_IO_PROTOCOL_GET_DEVICE_TYPE) (
    IN EFI_SCSI_IO_PROTOCOL     *This,
    OUT UINT8                   *DeviceType
);

typedef
EFI_STATUS
(EFIAPI *EFI_SCSI_IO_PROTOCOL_GET_DEVICE_LOCATION) (
    IN EFI_SCSI_IO_PROTOCOL     *This,
    IN OUT UINT8                **Target,
    OUT UINT64                  *Lun
);

typedef
EFI_STATUS
(EFIAPI *EFI_SCSI_IO_PROTOCOL_RESET_BUS) (
    IN EFI_SCSI_IO_PROTOCOL     *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_SCSI_IO_PROTOCOL_RESET_DEVICE) (
    IN EFI_SCSI_IO_PROTOCOL     *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_SCSI_IO_PROTOCOL_EXECUTE_SCSI_COMMAND) (
    IN EFI_SCSI_IO_PROTOCOL                 *This,
    IN OUT EFI_SCSI_IO_SCSI_REQUEST_PACKET  *Packet,
    IN EFI_EVENT                            Event OPTIONAL
);

struct _EFI_SCSI_IO_PROTOCOL {
    EFI_SCSI_IO_PROTOCOL_GET_DEVICE_TYPE        GetDeviceType;
    EFI_SCSI_IO_PROTOCOL_GET_DEVICE_LOCATION    GetDeviceLocation;
    EFI_SCSI_IO_PROTOCOL_RESET_BUS              ResetBus;
    EFI_SCSI_IO_PROTOCOL_RESET_DEVICE           ResetDevice;
    EFI_SCSI_IO_PROTOCOL_EXECUTE_SCSI_COMMAND   ExecuteScsiCommand;
    UINT32                                      IoAlign;
};

#endif // EFI_PROTOCOL_SCSI_SCSIIO_H
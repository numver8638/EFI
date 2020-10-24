#ifndef EFI_PROTOCOL_PCI_ROOTBRIDGEIO_H
#define EFI_PROTOCOL_PCI_ROOTBRIDGEIO_H

#include <EFI/Types.h>

#define EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GUID \
    { 0x2F707EBB, 0x4A1A, 0x11D4, { 0x9A, 0x38, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } }

typedef struct _EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL;

//
// EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH
//
typedef enum {
    EfiPciWidthUint8,
    EfiPciWidthUint16,
    EfiPciWidthUint32,
    EfiPciWidthUint64,
    EfiPciWidthFifoUint8,
    EfiPciWidthFifoUint16,
    EfiPciWidthFifoUint32,
    EfiPciWidthFifoUint64,
    EfiPciWidthFillUint8,
    EfiPciWidthFillUint16,
    EfiPciWidthFillUint32,
    EfiPciWidthFifoUint64,
    EfiPciWidthMaximum
} EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH;

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_IO_MEM) (
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL          *This,
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH    Width,
    IN UINT64                                   Address,
    IN UINTN                                    Count,
    IN OUT VOID                                 *Buffer
);

//
// EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS
//
typedef struct {
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_IO_MEM  Read;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_IO_MEM  Write;
} EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS;

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_POLL_IO_MEM) (
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL          *This,
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH    Width,
    IN UINT64                                   Address,
    IN UINT64                                   Mask,
    IN UINT64                                   Value,
    IN UINT64                                   Delay,
    OUT UINT64                                  *Result
);

//
// EFI PCI Root Bridge I/O Protocol Attribute bits
//
#define EFI_PCI_ATTRIBUTE_MOTHERBOARD_IO        (0x0001)
#define EFI_PCI_ATTRIBUTE_ISA_IO                (0x0002)
#define EFI_PCI_ATTRIBUTE_VGA_PALLATE_IO        (0x0004)
#define EFI_PCI_ATTRIBUTE_VGA_MEMORY            (0x0008)
#define EFI_PCI_ATTRIBUTE_VGA_IO                (0x0010)
#define EFI_PCI_ATTRIBUTE_IDE_PRIMARY_IO        (0x0020)
#define EFI_PCI_ATTRIBUTE_IDE_SECONDARY_IO      (0x0040)
#define EFI_PCI_ATTRIBUTE_MEMORY_WRITE_COMBINE  (0x0080)
#define EFI_PCI_ATTRIBUTE_MEMORY_CACHED         (0x0800)
#define EFI_PCI_ATTRIBUTE_MEMORY_DISABLE        (0x1000)
#define EFI_PCI_ATTRIBUTE_DUAL_ADDRESS_CYCLE    (0x8000)
#define EFI_PCI_ATTRIBUTE_ISA_IO_16             (0x10000)
#define EFI_PCI_ATTRIBUTE_VGA_PALLETE_IO_16     (0x20000)
#define EFI_PCI_ATTRIBUTE_VGA_IO_16             (0x40000)

//
// EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_OPERATION
//
typedef enum {
    EfiPciOperationBusMasterRead,
    EfiPciOperationBusMasterWrite,
    EfiPciOperationBusMasterCommonBuffer,
    EfiPciOperationBusMasterRead64,
    EfiPciOperationBusMasterWrite64,
    EfiPciOperationBusMasterCommonBuffer64,
    EfiPciOperationMaximum
} EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_OPERATION;

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_COPY_MEM) (
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL          *This,
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_WIDTH    Width,
    IN UINT64                                   DestAddress,
    IN UINT64                                   SrcAddress,
    IN UINTN                                    Count
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_MAP) (
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL              *This,
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_OPERATION    Operation,
    IN VOID                                         *HostAddress,
    IN OUT UINTN                                    *NumberOfBytes,
    OUT EFI_PHYSICAL_ADDRESS                        *DeviceAddress,
    OUT VOID                                        **Mapping
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_UNMAP) (
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL              *This,
    IN VOID                                         *Mapping
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ALLOCATE_BUFFER) (
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *This,
    IN EFI_ALLOCATE_TYPE                Type,
    IN EFI_MEMORY_TYPE                  MemoryType,
    IN UINTN                            Pages,
    OUT VOID                            **HostAddress,
    IN UINT64                           Attributes
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FREE_BUFFER) (
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *This,
    IN UINTN                            Pages,
    IN VOID                             *HostAddress
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FLUSH) (
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *This
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GET_ATTRIBUTES) (
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *This,
    OUT UINT64                          *Supports, OPTIONAL
    OUT UINT64                          *Attributes OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_SET_ATTRIBUTES) (
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *This,
    IN UINT64                           Attributes,
    IN OUT UINT64                       *ResourceBase, OPTIONAL
    IN OUT UINT64                       *ResourceLength OPTIONAL
);

typedef
EFI_STATUS
(EFIAPI *EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_CONFIGURATION) (
    IN EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL  *This,
    OUT VOID                            **Resources
);

struct _EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL {
    EFI_HANDLE                                      ParentHandle;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_POLL_IO_MEM     PollMem;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_POLL_IO_MEM     PollIo;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS          Mem;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS          Io;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ACCESS          Pci;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_COPY_MEM        CopyMem;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_MAP             Map;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_UNMAP           Unmap;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_ALLOCATE_BUFFER AllocateBuffer;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FREE_BUFFER     FreeBuffer;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_FLUSH           Flush;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GET_ATTRIBUTES  GetAttributes;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_SET_ATTRIBUTES  SetAttributes;
    EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_CONFIGURATION   Configuration;
    UINT32                                          SegmentNumber;
};

#endif // EFI_PROTOCOL_PCI_ROOTBRIDGEIO_H
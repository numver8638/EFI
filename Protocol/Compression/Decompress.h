#ifndef EFI_PROTOCOL_COMPRESSION_DECOMPRESS_H
#define EFI_PROTOCOL_COMPRESSION_DECOMPRESS_H

#include <EFI/Types.h>

#define EFI_DECOMPRESS_PROTOCOL_GUID \
    { 0xD8117CFE, 0x94A6, 0x11D4, { 0x9A, 0x3A, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } }

typedef struct _EFI_DECOMPRESS_PROTOCOL EFI_DECOMPRESS_PROTOCOL;

typedef
EFI_STATUS
(EFIAPI *EFI_DECOMPRESS_GET_INFO) (
    IN EFI_DECOMPRESS_PROTOCOL  *This,
    IN VOID                     *Source,
    IN UINT32                   SourceSize,
    OUT UINT32                  *DestinationSize,
    OUT UINT32                  *ScratchSize
);

typedef
EFI_STATUS
(EFIAPI *EFI_DECOMPRESS_DECOMPRESS) (
    IN EFI_DECOMPRESS_PROTOCOL  *This,
    IN VOID                     *Source,
    IN UINT32                   SourceSize,
    IN OUT VOID                 *Destination,
    IN UINT32                   DestinationSize,
    IN OUT VOID                 *Scratch,
    IN UINT32                   ScratchSize
);

struct _EFI_DECOMPRESS_PROTOCOL {
    EFI_DECOMPRESS_GET_INFO     GetInfo;
    EFI_DECOMPRESS_DECOMPRESS   Decompress;
};

#endif // EFI_PROTOCOL_COMPRESSION_DECOMPRESS_H
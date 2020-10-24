#ifndef EFI_PROTOCOL_DEBUG_DEBUGSUPPORT_H
#define EFI_PROTOCOL_DEBUG_DEBUGSUPPORT_H

#include <EFI/Types.h>

#define EFI_DEBUG_SUPPORT_PROTOCOL_GUID \
    { 0x2755590C, 0x6F3C, 0x42FA, { 0x9E, 0xA4, 0xA3, 0xBA, 0x54, 0x3C, 0xDA, 0x25 } }

typedef struct _EFI_DEBUG_SUPPORT_PROTOCOL EFI_DEBUG_SUPPORT_PROTOCOL;

//
// EFI_INSTRUCTION_SET_ARCHITECTURE
// Machine type definition
//
typedef enum {
    IsaIa32     = 0x014C,   // IMAGE_FILE_MACHINE_I386
    IsaX64      = 0x8664,   // IMAGE_FILE_MACHINE_X64
    IsaIpf      = 0x0200,   // IMAGE_FILE_MACHINE_IA64
    IsaEbc      = 0x0EBC,   // IMAGE_FILE_MACHINE_EBC
    IsaArm      = 0x01C2,   // IMAGE_FILE_MACHINE_ARMTHUMB_MIXED
    IsaAArch64  = 0xAA64,   // IMAGE_FILE_MACHINE_AARCH64
} EFI_INSTRUCTION_SET_ARCHITECTURE;

//
// EFI_SYSTEM_CONTEXT_EBC
// System context for virtual EBC processors
typedef struct {
    UINT64  R0, R1, R2, R3, R4, R5, R6, R7;
    UINT64  Flags;
    UINT64  ControlFlags;
    UINT64  Ip;
} EFI_SYSTEM_CONTEXT_EBC;

//
// EFI_FX_SAVE_STATE_IA32
// FXSAVE_STATE - FP / MMX / XMM registers
//
typedef struct {
    UINT16      Fcw;
    UINT16      Fsw;
    UINT16      Ftw;
    UINT16      Opcode;
    UINT32      Eip;
    UINT16      Cs;
    UINT16      Reserved1;
    UINT32      DataOffset;
    UINT16      Ds;
    UINT8       Reserved2[10];
    UINT8       St0Mm0[10], Reserved3[6];
    UINT8       St0Mm1[10], Reserved4[6];
    UINT8       St0Mm2[10], Reserved5[6];
    UINT8       St0Mm3[10], Reserved6[6];
    UINT8       St0Mm4[10], Reserved7[6];
    UINT8       St0Mm5[10], Reserved8[6];
    UINT8       St0Mm6[10], Reserved9[6];
    UINT8       St0Mm7[10], Reserved10[6];
    UINT8       Xmm0[16];
    UINT8       Xmm1[16];
    UINT8       Xmm2[16];
    UINT8       Xmm3[16];
    UINT8       Xmm4[16];
    UINT8       Xmm5[16];
    UINT8       Xmm6[16];
    UINT8       Xmm7[16];
    UINT8       Reserved11[14*16];
} EFI_FX_SAVE_STATE_IA32;

//
// EFI_SYSTEM_CONTEXT_IA32
// System context for IA-32 processors
//
typedef struct {
    UINT32                  ExceptionData;
    EFI_FX_SAVE_STATE_IA32  FxSaveState;
    UINT32                  Dr0, Dr1, Dr2, Dr3, Dr6, Dr7;
    UINT32                  Cr0, Cr1 /* RESERVED */, Cr2, Cr3, Cr4;
    UINT32                  Eflags;
    UINT32                  Ldtr, Tr;
    UINT32                  Gdtr[2], Idtr[2];
    UINT32                  Eip;
    UINT32                  Gs, Fs, Es, Ds, Cs, Ss;
    UINT32                  Edi, Esi, Ebp, Esp, Ebx, Edx, Ecx, Eax;
} EFI_SYSTEM_CONTEXT_IA32;

//
// EFI_FX_SAVE_STATE_X64
// FXSAVE_STATE - FP / MMX / XMM registers
//
typedef struct {
    UINT16      Fcw;
    UINT16      Fsw;
    UINT16      Ftw;
    UINT16      Opcode;
    UINT64      Rip;
    UINT64      DataOffset;
    UINT8       Reserved2[8];
    UINT8       St0Mm0[10], Reserved3[6];
    UINT8       St0Mm1[10], Reserved4[6];
    UINT8       St0Mm2[10], Reserved5[6];
    UINT8       St0Mm3[10], Reserved6[6];
    UINT8       St0Mm4[10], Reserved7[6];
    UINT8       St0Mm5[10], Reserved8[6];
    UINT8       St0Mm6[10], Reserved9[6];
    UINT8       St0Mm7[10], Reserved10[6];
    UINT8       Xmm0[16];
    UINT8       Xmm1[16];
    UINT8       Xmm2[16];
    UINT8       Xmm3[16];
    UINT8       Xmm4[16];
    UINT8       Xmm5[16];
    UINT8       Xmm6[16];
    UINT8       Xmm7[16];
    UINT8       Reserved11[14*16];
} EFI_FX_SAVE_STATE_X64;

//
// EFI_SYSTEM_CONTEXT_X64
// System context for x64 processors
//
typedef struct {
    UINT64                  ExceptionData;
    EFI_FX_SAVE_STATE_X64  FxSaveState;
    UINT64                  Dr0, Dr1, Dr2, Dr3, Dr6, Dr7;
    UINT64                  Cr0, Cr1 /* RESERVED */, Cr2, Cr3, Cr4, Cr8;
    UINT64                  Rflags;
    UINT64                  Ldtr, Tr;
    UINT64                  Gdtr[2], Idtr[2];
    UINT64                  Rip;
    UINT64                  Gs, Fs, Es, Ds, Cs, Ss;
    UINT64                  Rdi, Rsi, Rbp, Rsp, Rbx, Rdx, Rcx, Rax;
    UINT64                  R8, R9, R10, R11, R12, R13, R14, R15;
} EFI_SYSTEM_CONTEXT_X64;

//
// EFI_SYSTEM_CONTEXT_IPF
// System context for Itanium processor family
//
typedef struct {
    UINT64  Reserved;

    UINT64   R1,  R2,  R3,  R4,  R5,  R6,  R7,  R8,  R9, R10,
            R11, R12, R13, R14, R15, R16, R17, R18, R19, R20,
            R21, R22, R23, R24, R25, R26, R27, R28, R29, R30,
            R31;
    
    UINT64   F2[2],  F3[2],  F4[2],  F5[2],  F6[2],
             F7[2],  F8[2],  F9[2], F10[2], F11[2],
            F12[2], F13[2], F14[2], F15[2], F16[2],
            F17[2], F18[2], F19[2], F20[2], F21[2],
            F22[2], F23[2], F24[2], F25[2], F26[2],
            F27[2], F28[2], F29[2], F30[2], F31[2];

    UINT64  Pr;

    UINT64  B0, B1, B2, B3, B4, B5, B6, B7;

    // application registers
    UINT64  ArRsc, ArBsp, ArBspstore, ArRnat;
    UINT64  ArFcr;
    UINT64  ArEflag, ArCsd, ArSsd, ArCflg;
    UINT64  ArFsr, ArFir, ArFdr;
    UINT64  ArCcv;
    UINT64  ArUnat;
    UINT64  ArFpsr;
    UINT64  ArPfs, ArLc, ArEc;

    // control registers
    UINT64  CrDcr, CrItm, CrIva, CrPta, CrIpsr, CrIsr;
    UINT64  CrIip, CrIfa, CrItir, CrIipa, CrIfs, CrIim;
    UINT64  CrIha;

    // debug registers
    UINT64  Dbr0, Dbr1, Dbr2, Dbr3, Dbr4, Dbr5, Dbr6, Dbr7;
    UINT64  Ibr0, Ibr1, Ibr2, Ibr3, Ibr4, Ibr5, Ibr6, Ibr7;

    // virtual registers
    UINT64  IntNat; // nat bits for R1 ~ R31
} EFI_SYSTEM_CONTEXT_IPF;

//
// EFI_SYSTEM_CONTEXT_ARM
// ARM processor context definition
//
typedef struct {
    UINT32  R0,  R1,  R2,  R3,  R4,  R5, R6,  
            R7,  R8,  R9, R10, R11, R12;
    UINT32  SP;
    UINT32  LR;
    UINT32  PC;
    UINT32  CPSR;
    UINT32  DFSR;
    UINT32  DFAR;
    UINT32  IFSR;
} EFI_SYSTEM_CONTEXT_ARM;

//
// EFI_SYSTEM_CONTEXT_AARCH64
// AARCH64 processor context definition
//
typedef struct {
    // General Purpose Registers
    UINT64  X0,  X1,  X2,  X3,  X4,  X5,  X6,
            X7,  X8,  X9,  X10, X11, X12, X13,
            X14, X15, X16, X17, X18, X19, X20,
            X21, X22, X23, X24, X25, X26, X27, X28;
    UINT64  FP; // x29 - Frame Pointer
    UINT64  LR; // x30 - Link Register
    UINT64  SP; // x31 - Stack pointer

    // FP/SIMD Registers
    UINT64  V0[2],  V1[2],  V2[2],  V3[2],  V4[2],  V5[2],  V6[2],  V7[2],
            V8[2],  V9[2],  V10[2], V11[2], V12[2], V13[2], V14[2], V15[2],
            V16[2], V17[2], V18[2], V19[2], V20[2], V21[2], V22[2], V23[2],
            V24[2], V25[2], V26[2], V27[2], V28[2], V29[2], V30[2], V31[2];
    UINT64  ELR;  // Exception Link Register
    UINT64  SPSR; // Saved Processor Status Register
    UINT64  FPSR; // Floating Point Status Register
    UINT64  ESR;  // Exception Syndrome Register
    UINT64  FAR;  // Fault Address Register
} EFI_SYSTEM_CONTEXT_AARCH64;

//
// EFI_SYSTEM_CONTEXT
// Universal EFI_SYSTEM_CONTEXT definition
//
typedef union {
    EFI_SYSTEM_CONTEXT_EBC      *SystemContextEBC;
    EFI_SYSTEM_CONTEXT_IA32     *SystemContextIa32;
    EFI_SYSTEM_CONTEXT_X64      *SystemContextX64;
    EFI_SYSTEM_CONTEXT_IPF      *SystemContextIpf;
    EFI_SYSTEM_CONTEXT_ARM      *StstemContextArm;
    EFI_SYSTEM_CONTEXT_AARCH64  *SystemContextAArch64;
} EFI_SYSTEM_CONTEXT;

typedef INTN EFI_EXCEPTION_TYPE;

// EBC Exception types
#define EXCEPT_EBC_UNDEFINED            (0)
#define EXCEPT_EBC_DIVIDE_ERROR         (1)
#define EXCEPT_EBC_DEBUG                (2)
#define EXCEPT_EBC_BREAKPOINT           (3)
#define EXCEPT_EBC_OVERFLOW             (4)
#define EXCEPT_EBC_INVALID_OPCODE       (5)
#define EXCEPT_EBC_STACK_FAULT          (6)
#define EXCEPT_EBC_ALIGNMENT_CHECK      (7)
#define EXCEPT_EBC_INSTRUCTION_ENCODING (8)
#define EXCEPT_EBC_BAD_BREAK            (9)
#define EXCEPT_EBC_SINGLE_STEP          (10)

// IA-32 Exception types
#define EXCEPT_IA32_DIVIDE_ERROR    (0)
#define EXCEPT_IA32_DEBUG           (1)
#define EXCEPT_IA32_NMI             (2)
#define EXCEPT_IA32_BREAKPOINT      (3)
#define EXCEPT_IA32_OVERFLOW        (4)
#define EXCEPT_IA32_BOUND           (5)
#define EXCEPT_IA32_INVALID_OPCODE  (6)
#define EXCEPT_IA32_DOUBLE_FAULT    (8)
#define EXCEPT_IA32_INVALID_TSS     (10)
#define EXCEPT_IA32_SEG_NOT_PRESENT (11)
#define EXCEPT_IA32_STACK_FALUT     (12)
#define EXCEPT_IA32_GP_FAULT        (13)
#define EXCEPT_IA32_PAGE_FAULT      (14)
#define EXCEPT_IA32_FP_ERROR        (16)
#define EXCEPT_IA32_ALIGNMENT_CHECK (17)
#define EXCEPT_IA32_MACHINE_CHECK   (18)
#define EXCEPT_IA32_SIMD            (19)

// X64 Exception types
#define EXCEPT_X64_DIVIDE_ERROR    (0)
#define EXCEPT_X64_DEBUG           (1)
#define EXCEPT_X64_NMI             (2)
#define EXCEPT_X64_BREAKPOINT      (3)
#define EXCEPT_X64_OVERFLOW        (4)
#define EXCEPT_X64_BOUND           (5)
#define EXCEPT_X64_INVALID_OPCODE  (6)
#define EXCEPT_X64_DOUBLE_FAULT    (8)
#define EXCEPT_X64_INVALID_TSS     (10)
#define EXCEPT_X64_SEG_NOT_PRESENT (11)
#define EXCEPT_X64_STACK_FALUT     (12)
#define EXCEPT_X64_GP_FAULT        (13)
#define EXCEPT_X64_PAGE_FAULT      (14)
#define EXCEPT_X64_FP_ERROR        (16)
#define EXCEPT_X64_ALIGNMENT_CHECK (17)
#define EXCEPT_X64_MACHINE_CHECK   (18)
#define EXCEPT_X64_SIMD            (19)

// Itanium Processor Family Exception types
#define EXECPT_IPF_VHTP_TRANSLATION                 (0)
#define EXECPT_IPF_INSTRUCTION_TLB                  (1)
#define EXECPT_IPF_DATA_TLB                         (2)
#define EXECPT_IPF_ALT_INSTRUCTION_TLB              (3)
#define EXECPT_IPF_ALT_DATA_TLB                     (4)
#define EXCEPT_IPF_DATA_NESTED_TLB                  (5)
#define EXECPT_IPF_INSTRUCTION_KEY_MISSED           (6)
#define EXECPT_IPF_DATA_KEY_MISSED                  (7)
#define EXECPT_IPF_DIRTY_BIT                        (8)
#define EXECPT_IPF_INSTRUCTION_ACCESS_BIT           (9)
#define EXECPT_IPF_DATA_ACCESS_BIT                  (10)
#define EXECPT_IPF_BREAKPOINT                       (11)
#define EXECPT_IPF_EXTERNAL_INTERRUPT               (12)
// 13 - 19 reserved
#define EXECPT_IPF_PAGE_NOT_PRESENT                 (20)
#define EXECPT_IPF_KEY_PERMISSION                   (21)
#define EXECPT_IPF_INSTRUCTION_ACCESS_RIGHTS        (22)
#define EXECPT_IPF_DATA_ACCESS_RIGHTS               (23)
#define EXECPT_IPF_GENERAL_EXCEPTION                (24)
#define EXECPT_IPF_DISABLED_FP_REGISTER             (25)
#define EXECPT_IPF_NAT_CONSUMPTION                  (26)
#define EXECPT_IPF_SPECULATION                      (27)
// 28 reserved
#define EXECPT_IPF_DEBUG                            (28)
#define EXECPT_IPF_UNALIGNED_REFERENCE              (29)
#define EXECPT_IPF_UNSUPPORTED_DATA_REFERENCE       (30)
#define EXECPT_IPF_FP_FAULT                         (31)
#define EXECPT_IPF_FP_TRAP                          (32)
#define EXECPT_IPF_LOWER_PRIVILEGE_TRANSFER_TRAP    (33)
#define EXECPT_IPF_TAKEN_BRANCH                     (34)
#define EXECPT_IPF_SINGLE_STEP                      (35)
// 37 - 44 reserved
#define EXECPT_IPF_IA32_EXCEPTION                   (45)
#define EXECPT_IPF_IA32_INTERCEPT                   (46)
#define EXECPT_IPF_IA32_INTERRUPT                   (47)

// ARM processor exception types
#define EXCEPT_ARM_RESET                    (0)
#define EXCEPT_ARM_UNDEFINED_INSTRUCTION    (1)
#define EXCEPT_ARM_SOFTWARE_INTERRUPT       (2)
#define EXCEPT_ARM_PREFETCH_ABORT           (3)
#define EXCEPT_ARM_DATA_ABORT               (4)
#define EXCEPT_ARM_RESERVED                 (5)
#define EXCEPT_ARM_IRQ                      (6)
#define EXCEPT_ARM_FIQ                      (7)
#define MAX_ARM_EXCEPTION                   EXCEPT_ARM_FIQ

// AARCH64 processor exception types
#define EXCEPT_AARCH64_SYNCHRONOUS_EXCEPTIONS   (0)
#define EXCEPT_AARCH64_IRQ                      (1)
#define EXCEPT_AARCH64_FIQ                      (2)
#define EXCEPT_AARCH64_SERROR                   (3)
#define MAX_AARCH64_EXCEPTION                   EXCEPT_AARCH64_SERROR

typedef
VOID
(EFIAPI *EFI_PERIODIC_CALLBACK) (
    IN OUT EFI_SYSTEM_CONTEXT   SystemContext
);

typedef
VOID
(EFIAPI *EFI_EXCEPTION_CALLBACK) (
    IN EFI_EXCEPTION_TYPE       ExceptionType,
    IN OUT EFI_SYSTEM_CONTEXT   SystemContext
);

typedef
EFI_STATUS
(EFIAPI *EFI_GET_MAXIMUM_PROCESSOR_INDEX) (
    IN EFI_DEBUG_SUPPORT_PROTOCOL   *This,
    OUT UINTN                       *MaxProcessorIndex
);

typedef
EFI_STATUS
(EFIAPI *EFI_REGISTER_PERIODIC_CALLBACK) (
    IN EFI_DEBUG_SUPPORT_PROTOCOL   *This,
    IN UINTN                        ProcessorIndex,
    IN EFI_PERIODIC_CALLBACK        PeriodicCallback
);

typedef
EFI_STATUS
(EFIAPI *EFI_REGISTER_EXCEPTION_CALLBACK) (
    IN EFI_DEBUG_SUPPORT_PROTOCOL   *This,
    IN UINTN                        ProcessorIndex,
    IN EFI_EXCEPTION_CALLBACK       ExceptionCallback,
    IN EFI_EXCEPTION_TYPE           ExceptionType
);

typedef
EFI_STATUS
(EFIAPI *EFI_INVALIDATE_INSTRUCTION_CACHE) (
    IN EFI_DEBUG_SUPPORT_PROTOCOL   *This,
    IN UINTN                        ProcessorIndex,
    IN VOID                         *Start,
    IN UINT64                       Length
);

struct _EFI_DEBUG_SUPPORT_PROTOCOL {
    EFI_INSTRUCTION_SET_ARCHITECTURE    Isa;
    EFI_GET_MAXIMUM_PROCESSOR_INDEX     GetMaximumProcessorIndex;
    EFI_REGISTER_PERIODIC_CALLBACK      RegisterPeriodicCallback;
    EFI_REGISTER_EXCEPTION_CALLBACK     RegisterExceptionCallback;
    EFI_INVALIDATE_INSTRUCTION_CACHE    InvalidateInstructionCache;
};

#endif // EFI_PROTOCOL_DEBUG_DEBUGSUPPORT_H
#ifndef EFI_PROTOCOL_HII_PACKAGE_FORMS_H
#define EFI_PROTOCOL_HII_PACKAGE_FORMS_H

#include <EFI/Protocol/HII/Types.h>

//
// EFI_HII_FORM_PACKAGE_HDR
//
typedef struct {
    EFI_HII_PACKAGE_HDR  Header;
    // EFI_IFR_OP_HEADER    OpCodeHeader;
    // More op-codes follow
} EFI_HII_FORM_PACKAGE_HDR;

//
// EFI_IFR_OP_HEADER
//
typedef struct {
    UINT8   OpCode;
    UINT8   Length:7;
    UINT8   Scope:1;
} EFI_IFR_OP_HEADER;

//
// EFI_IFR_OP_HEADER.Opcode
//
#define EFI_IFR_FORM_OP                 (0x01)
#define EFI_IFR_SUBTITLE_OP             (0x02)
#define EFI_IFR_TEXT_OP                 (0x03)
#define EFI_IFR_IMAGE_OP                (0x04)
#define EFI_IFR_ONE_OF_OP               (0x05)
#define EFI_IFR_CHECKBOX_OP             (0x06)
#define EFI_IFR_NUMERIC_OP              (0x07)
#define EFI_IFR_PASSWORD_OP             (0x08)
#define EFI_IFR_ONE_OF_OPTION_OP        (0x09)
#define EFI_IFR_SUPPRESS_IF_OP          (0x0A)
#define EFI_IFR_LOCKED_OP               (0x0B)
#define EFI_IFR_ACTION_OP               (0x0C)
#define EFI_IFR_RESET_BUTTON_OP         (0x0D)
#define EFI_IFR_FORM_SET_OP             (0x0E)
#define EFI_IFR_REF_OP                  (0x0F)
#define EFI_IFR_NO_SUBMIT_IF_OP         (0x10)
#define EFI_IFR_INCONSISTENT_IF_OP      (0x11)
#define EFI_IFR_EQ_ID_VAL_OP            (0x12)
#define EFI_IFR_EQ_ID_ID_OP             (0x13)
#define EFI_IFR_EQ_ID_VAL_LIST_OP       (0x14)
#define EFI_IFR_AND_OP                  (0x15)
#define EFI_IFR_OR_OP                   (0x16)
#define EFI_IFR_NOT_OP                  (0x17)
#define EFI_IFR_RULE_OP                 (0x18)
#define EFI_IFR_GRAY_OUT_IF_OP          (0x19)
#define EFI_IFR_DATE_OP                 (0x1A)
#define EFI_IFR_TIME_OP                 (0x1B)
#define EFI_IFR_STRING_OP               (0x1C)
#define EFI_IFR_REFRESH_OP              (0x1D)
#define EFI_IFR_DISABLE_IF_OP           (0x1E)
#define EFI_IFR_ANIMATION_OP            (0x1F)
#define EFI_IFR_TO_LOWER_OP             (0x20)
#define EFI_IFR_TO_UPPER_OP             (0x21)
#define EFI_IFR_MAP_OP                  (0x22)
#define EFI_IFR_ORDERED_LIST_OP         (0x23)
#define EFI_IFR_VARSTORE_OP             (0x24)
#define EFI_IFR_VARSTORE_NAME_VALUE_OP  (0x25)
#define EFI_IFR_VARSTORE_EFI_OP         (0x26)
#define EFI_IFR_VARSTORE_DEVICE_OP      (0x27)
#define EFI_IFR_VERSION_OP              (0x28)
#define EFI_IFR_END_OP                  (0x29)
#define EFI_IFR_MATCH_OP                (0x2A)
#define EFI_IFR_GET_OP                  (0x2B)
#define EFI_IFR_SET_OP                  (0x2C)
#define EFI_IFR_READ_OP                 (0x2D)
#define EFI_IFR_WRITE_OP                (0x2E)
#define EFI_IFR_EQUAL_OP                (0x2F)
#define EFI_IFR_NOT_EQUAL_OP            (0x30)
#define EFI_IFR_GRATER_THAN_OP          (0x31)
#define EFI_IFR_GRATER_EQUAL_OP         (0x32)
#define EFI_IFR_LESS_THAN_OP            (0x33)
#define EFI_IFR_LESS_EQUAL_OP           (0x34)
#define EFI_IFR_BITWISE_AND_OP          (0x35)
#define EFI_IFR_BITWISE_OR_OP           (0x36)
#define EFI_IFR_BITWISE_NOT_OP          (0x37)
#define EFI_IFR_SHIFT_LEFT_OP           (0x38)
#define EFI_IFR_SHIFT_RIGHT_OP          (0x39)
#define EFI_IFR_ADD_OP                  (0x3A)
#define EFI_IFR_SUBTRACT_OP             (0x3B)
#define EFI_IFR_MULTIPLY_OP             (0x3C)
#define EFI_IFR_DIVIDE_OP               (0x3D)
#define EFI_IFR_MODULO_OP               (0x3E)
#define EFI_IFR_RULE_REF_OP             (0x3F)
#define EFI_IFR_QUESTION_REF1_OP        (0x40)
#define EFI_IFR_QUESTION_REF2_OP        (0x41)
#define EFI_IFR_UINT8_OP                (0x42)
#define EFI_IFR_UINT16_OP               (0x43)
#define EFI_IFR_UINT32_OP               (0x44)
#define EFI_IFR_UINT64_OP               (0x45)
#define EFI_IFR_TRUE_OP                 (0x46)
#define EFI_IFR_FALSE_OP                (0x47)
#define EFI_IFR_TO_UINT_OP              (0x48)
#define EFI_IFR_TO_STRING_OP            (0x49)
#define EFI_IFR_TO_BOOLEAN_OP           (0x4A)
#define EFI_IFR_MID_OP                  (0x4B)
#define EFI_IFR_FIND_OP                 (0x4C)
#define EFI_IFR_TOKEN_OP                (0x4D)
#define EFI_IFR_STRING_REF1_OP          (0x4E)
#define EFI_IFR_STRING_REF2_OP          (0x4F)
#define EFI_IFR_CONDITIONAL_OP          (0x50)
#define EFI_IFR_QUESTION_REF3_OP        (0x51)
#define EFI_IFR_ZERO_OP                 (0x52)
#define EFI_IFR_ONE_OP                  (0x53)
#define EFI_IFR_ONES_OP                 (0x54)
#define EFI_IFR_UNDEFINED_OP            (0x55)
#define EFI_IFR_LENGTH_OP               (0x56)
#define EFI_IFR_DUP_OP                  (0x57)
#define EFI_IFR_THIS_OP                 (0x58)
#define EFI_IFR_SPAN_OP                 (0x59)
#define EFI_IFR_VALUE_OP                (0x5A)
#define EFI_IFR_DEFAULT_OP              (0x5B)
#define EFI_IFR_DEFAULTSTORE_OP         (0x5C)
#define EFI_IFR_FORM_MAP_OP             (0x5D)
#define EFI_IFR_CATENATE_OP             (0x5E)
#define EFI_IFR_GUID_OP                 (0x5F)
#define EFI_IFR_SECURITY_OP             (0x60)
#define EFI_IFR_MODAL_TAG_OP            (0x61)
#define EFI_IFR_REFRESH_ID_OP           (0x62)
#define EFI_IFR_WARNING_IF_OP           (0x63)

//
// EFI_IFR_STATEMENT_HEADER
//
typedef struct {
    EFI_STRING_ID   Prompt;
    EFI_STRING_ID   Help;
} EFI_IFR_STATEMENT_HEADER;

//
// EFI_IFR_QUESTION_HEADER
//
typedef struct {
    EFI_IFR_STATEMENT_HEADER    Header;
    EFI_QUESTION_ID             QuestionId;
    EFI_VARSTORE_ID             VarStoreId;
    union {
        EFI_STRING_ID           VarName;
        UINT16                  VarOffset;
    }                           VarStoreInfo;
    UINT8                       Flags;
} EFI_IFR_QUESTION_HEADER;

//
// EFI_IFT_QUESTION_HEADER.Flags values
//
#define EFI_IFR_FLAG_READ_ONLY          (0x01)
#define EFI_IFR_FLAG_CALLBACK           (0X04)
#define EFI_IFR_FLAG_RESET_REQUIRED     (0x10)
#define EFI_IFR_FLAG_RECONNECT_REQUIRED (0x40)
#define EFI_IFR_FLAG_OPTIONS_ONLY       (0x80)

//
// EFI_HII_TIME
//
typedef struct {
    UINT8       Hour;
    UINT8       Minute;
    UINT8       Second;
} EFI_HII_TIME;

//
// EFI_HII_DATE
//
typedef struct {
    UINT16      Year;
    UINT8       Month;
    UINT8       Day;
} EFI_HII_DATE;

//
// EFI_HII_REF
//
typedef struct {
    EFI_QUESTION_ID QuestionId;
    EFI_FORM_ID     FormId;
    EFI_GUID        FormSetId;
    EFI_STRING_ID   DevicePath;
} EFI_HII_REF;

//
// EFI_IFR_TYPE_VALUE
//
typedef union {
    UINT8           u8;             // EFI_IFR_TYPE_NUM_SIZE_8
    UINT16          u16;            // EFI_IFR_TYPE_NUM_SIZE_16
    UINT32          u32;            // EFI_IFR_TYPE_NUM_SIZE_32
    UINT64          u64;            // EFI_IFR_TYPE_NUM_SIZE_64
    BOOLEAN         b;              // EFI_IFR_TYPE_BOOLEAN
    EFI_HII_TIME    time;           // EFI_IFR_TYPE_TIME
    EFI_HII_DATE    date;           // EFI_IFR_TYPE_DATE
    EFI_STRING_ID   string;         // EFI_IFR_TYPE_STRING
    EFI_HII_REF     ref;            // EFI_IFR_TYPE_REF
    // UINT8        buffer[...];    // EFI_IFR_TYPE_BUFFER
} EFI_IFR_TYPE_VALUE;

#define EFI_IFR_TYPE_NUM_SIZE_8     (0x00)
#define EFI_IFR_TYPE_NUM_SIZE_16    (0x01)
#define EFI_IFR_TYPE_NUM_SIZE_32    (0x02)
#define EFI_IFR_TYPE_NUM_SIZE_64    (0x03)
#define EFI_IFR_TYPE_BOOLEAN        (0x04)
#define EFI_IFR_TYPE_TIME           (0x05)
#define EFI_IFR_TYPE_DATE           (0x06)
#define EFI_IFR_TYPE_STRING         (0x07)
#define EFI_IFR_TYPE_OTHER          (0x08)
#define EFI_IFR_TYPE_UNDEFINED      (0x09)
#define EFI_IFR_TYPE_ACTION         (0x0A)
#define EFI_IFR_TYPE_BUFFER         (0x0B)
#define EFI_IFR_TYPE_REF            (0x0C)

#define EFI_IFR_OPTION_DEFAULT      (0x10)
#define EFI_IFR_OPTION_DEFAULT_MFG  (0x20)

//
// EFI_IFR_OPs
//
//
// EFI_IFR_ACTION
//
typedef struct {
    EFI_IFR_OP_HEADER       Header;
    EFI_IFR_QUESTION_HEADER Question;
    EFI_STRING_ID           QuestionConfig;
} EFI_IFR_ACTION;

//
// EFI_IFR_ACTION_1
//
typedef struct {
    EFI_IFR_OP_HEADER       Header;
    EFI_IFR_QUESTION_HEADER Question;
} EFI_IFR_ACTION_1;

//
// EFI_IFR_ANIMATION
//
typedef struct {
    EFI_IFR_OP_HEADER   Header;
    EFI_ANIMATION_ID    Id;
} EFI_IFR_ANIMATION;

//
// EFI_IFR_ADD
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_ADD;

//
// EFI_IFR_AND
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_AND;

//
// EFI_IFR_BITWISE_AND
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_BITWISE_AND;

//
// EFI_IFR_BITWISE_NOT
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_BITWISE_NOT;

//
// EFI_IFR_BITWISE_OR
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_BITWISE_OR;

//
// EFI_IFR_CATENATE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_CATENATE;

//
// EFI_IFR_CHECKBOX
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_QUESTION_HEADER     Question;
    UINT8                       Flags;
} EFI_IFR_CHECKBOX;

//
// EFI_IFR_CHECKBOX.Flags
//
#define EFI_IFR_CHECKBOX_DEFAULT        (0x01)
#define EFI_IFR_CHECKBOX_DEFAULT_MFG    (0x02)

//
// EFI_IFR_CONDITIONAL
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_CONDITIONAL;

//
// EFI_IFR_DATE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_QUESTION_HEADER     Question;
    UINT8                       Flags;
} EFI_IFR_DATE;

//
// EFI_IFR_DATE.Flags
//
#define EFI_QF_DATE_YEAR_SUPRESS    (0x01)
#define EFI_QF_DATE_MONTH_SUPRESS   (0x02)
#define EFI_QF_DATE_DAY_SUPRESS     (0x04)
#define EFI_QF_DATE_STORAGE         (0x30)

#define QF_DATE_STORAGE_NORMAL      (0x00)
#define QF_DATE_STORAGE_TIME        (0x10)
#define QF_DATE_STORAGE_WAKEUP      (0x20)

//
// EFI_IFR_DEFAULT
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    UINT16                      DefaultId;
    UINT8                       Type;
    EFI_IFR_TYPE_VALUE          Value;
} EFI_IFR_DEFAULT;

//
// EFI_IFR_DEFAULT_2
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    UINT16                      DefaultId;
    UINT8                       Type;
} EFI_IFR_DEFAULT_2;

//
// EFI_IFR_DEFAULTSTORE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_STRING_ID               DefaultName;
    UINT16                      DefaultId;
} EFI_IFR_DEFAULTSTORE;

//
// EFI_IFR_DISABLE_IF
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_DISABLE_IF;

//
// EFI_IFR_DIVIDE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_DIVIDE;

//
// EFI_IFR_DUP
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_DUP;

//
// EFI_IFR_END
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_END;

//
// EFI_IFR_EQUAL
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_EQUAL;

//
// EFI_IFR_EQ_ID_ID
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_QUESTION_ID             QuestionId1;
    EFI_QUESTION_ID             QuestionId2;
} EFI_IFR_EQ_ID_ID;

//
// EFI_IFR_EQ_ID_VAL_LIST
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_QUESTION_ID             QuestionId;
    UINT16                      ListLength;
    UINT16                      ValueList[1];
} EFI_IFR_EQ_ID_VAL_LIST;

//
// EFI_IFR_EQ_ID_VAL
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_QUESTION_ID             QuestionId;
    UINT16                      Value;
} EFI_IFR_EQ_ID_VAL;

//
// EFI_IFR_FALSE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_FALSE;

//
// EFI_IFR_FIND
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    UINT8                       Format;
} EFI_IFR_FIND;

//
// EFI_IFR_FIND.Format
//
#define EFI_IFR_FF_CASE_SENSITIVE       (0x00)
#define EFI_IFR_FF_CASE_INSENSITIVE     (0x01)

//
// EFI_IFR_FORM
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_FORM_ID                 FormId;
    EFI_STRING_ID               FormTitle;
} EFI_IFR_FORM;

//
// EFI_IFR_FORM_MAP_METHOD
//
typedef struct {
    EFI_STRING_ID               MethodTitle;
    EFI_GUID                    MethodIdentifier;
} EFI_IFR_FORM_MAP_METHOD;

// Used in EFI_IFR_FORM_MAP_METHOD.MethodIdentifier
#define EFI_HII_STANDARD_FORM_GUID \
    { 0x3BD2F4EC, 0xE524, 0x46E4, { 0xA9, 0xD8, 0x51, 0x01, 0x17, 0x42, 0x55, 0x62 } }

//
// EFI_IFR_FORM_MAP
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_FORM_ID                 FormId;
    // EFI_IFR_FORM_MAP_METHOD  Methods[...];
} EFI_IFR_FORM_MAP;

//
// EFI_IFR_SET
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_GUID                    Guid;
    EFI_STRING_ID               FormSetTitle;
    EFI_STRING_ID               Help;
    UINT8                       Flags;
    // EFI_GUID                 ClassGuid[...];
} EFI_IFR_SET;

//
// EFI_IFR_GET
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_VARSTORE_ID             VarStoreId;
    union {
        EFI_STRING_ID           VarName;
        UINT16                  VarOffset;
    }                           VarStoreInfo;
    UINT8                       VarStoreType;
} EFI_IFR_GET;

//
// EFI_IFR_GRAY_OUT_IF
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_GRAY_OUT_IF;

//
// EFI_IFR_GRATER_EQUAL
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_GRATER_EQUAL;

//
// EFI_IFR_GRATER_THAN
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_GRATER_THAN;

//
// EFI_IFR_GUID
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_GUID                    Guid;
    // Optional Data Follows
} EFI_IFR_GUID;

//
// EFI_IFR_IMAGE
//
typedef struct {
    EFI_IMAGE_ID                Id;
} EFI_IFR_IMAGE;

//
// EFI_IFR_INCONSISTENT_IF
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_STRING_ID               Error;
} EFI_IFR_INCONSISTENT_IF;

//
// EFI_IFR_LENGTH
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_LENGTH;

//
// EFI_IFR_LESS_EQUAL
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_LESS_EQUAL;

//
// EFI_IFR_LESS_THAN
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_LESS_THAN;

//
// EFI_IFR_LOCKED
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_LOCKED;

//
// EFI_IFR_MAP
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_MAP;

//
// EFI_IFR_MATCH
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_MATCH;

//
// EFI_IFR_MID
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_MID;

//
// EFI_IFR_TAG
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_TAG;

//
// EFI_IFR_MODULO
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_MODULO;

//
// EFI_IFR_MULTIPLY
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_MULTIPLY;

//
// EFI_IFR_NOT
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_NOT;

//
// EFI_IFR_NOT_EQUAL
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_NOT_EQUAL;

//
// EFI_IFR_SUBMIT_IF
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_STRING_ID               Error;
} EFI_IFR_SUBMIT_IF;

//
// EFI_IFR_NUMERIC
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_QUESTION_HEADER     Question;
    UINT8                       Flags;
    union {
        struct {
            UINT8               MinValue;
            UINT8               MaxValue;
            UINT8               Step;
        } u8;
        struct {
            UINT16              MinValue;
            UINT16              MaxValue;
            UINT16              Step;
        } u16;
        struct {
            UINT32              MinValue;
            UINT32              MaxValue;
            UINT32              Step;
        } u32;
        struct {
            UINT64              MinValue;
            UINT64              MaxValue;
            UINT64              Step;
        } u64;
    } data;
} EFI_IFR_NUMERIC;

//
// EFI_IFR_NUMERIC.Flags
//
#define EFI_IFR_NUMERIC_SIZE        (0x03)
#define EFI_IFR_NUMERIC_SIZE_1      (0x00)
#define EFI_IFR_NUMERIC_SIZE_2      (0x01)
#define EFI_IFR_NUMERIC_SIZE_4      (0x02)
#define EFI_IFR_NUMERIC_SIZE_8      (0x03)

#define EFI_IFR_DISPLAY             (0x30)
#define EFI_IFR_DISPLAY_INT_DEC     (0x00)
#define EFI_IFR_DISPLAY_UINT_DEC    (0x10)
#define EFI_IFR_DISPLAY_UINT_HEX    (0x20)

//
// EFI_IFR_ONE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_ONE;

//
// EFI_IFR_ONES
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_ONES;

//
// EFI_IFR_ONE_OF
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_QUESTION_HEADER     Question;
    UINT8                       Flags;
    union {
        struct {
            UINT8               MinValue;
            UINT8               MaxValue;
            UINT8               Step;
        } u8;
        struct {
            UINT16              MinValue;
            UINT16              MaxValue;
            UINT16              Step;
        } u16;
        struct {
            UINT32              MinValue;
            UINT32              MaxValue;
            UINT32              Step;
        } u32;
        struct {
            UINT64              MinValue;
            UINT64              MaxValue;
            UINT64              Step;
        } u64;
    } data;
} EFI_IFR_ONE_OF;

//
// EFI_IFR_ONE_OF_OPTION
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_STRING_ID               Option;
    UINT8                       Flags;
    UINT8                       Type;
    EFI_IFR_TYPE_VALUE          Value;
} EFI_IFR_ONE_OF_OPTION;

//
// EFI_IFR_OR
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_OR;

//
// EFI_IFR_ORDERED_LIST
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_QUESTION_ID             Question;
    UINT8                       MaxContainers;
    UINT8                       Flags;
} EFI_IFR_ORDERED_LIST;

//
// EFI_IFR_ORDERED_LIST.Flags
//
#define EFI_IFR_UNIQUE_SET      (0x01)
#define EFI_IFR_NO_EMPTY_SET    (0x02)

//
// EFI_IFR_PASSWORD
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_QUESTION_HEADER     Question;
    UINT16                      MinSize;
    UINT16                      MaxSize;
} EFI_IFR_PASSWORD;

//
// EFI_IFR_QUESTION_REF1
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_QUESTION_ID             QuestionId;
} EFI_IFR_QUESTION_REF1;

//
// EFI_IFR_QUESTION_REF2
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_QUESTION_REF2;

//
// EFI_IFR_QUESTION_REF3
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_QUESTION_REF3;

//
// EFI_IFR_QUESTION_REF3_2
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_STRING_ID               DevicePath;
} EFI_IFR_QUESTION_REF3_2;

//
// EFI_IFR_QUESTION_REF3_3
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_STRING_ID               DevicePath;
    EFI_GUID                    Guid;
} EFI_IFR_QUESTION_REF3_3;

//
// EFI_IFR_READ
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_READ;

//
// EFI_IFR_REF
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_QUESTION_HEADER     Question;
    EFI_FORM_ID                 FormId;
} EFI_IFR_REF;

//
// EFI_IFR_REF2
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_QUESTION_HEADER     Question;
    EFI_FORM_ID                 FormId;
    EFI_QUESTION_ID             QuestionId;
} EFI_IFR_REF2;

//
// EFI_IFR_REF3
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_QUESTION_HEADER     Question;
    EFI_FORM_ID                 FormId;
    EFI_QUESTION_ID             QuestionId;
    EFI_GUID                    FormSetId;
} EFI_IFR_REF3;

//
// EFI_IFR_REF4
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_QUESTION_HEADER     Question;
    EFI_FORM_ID                 FormId;
    EFI_QUESTION_ID             QuestionId;
    EFI_GUID                    FormSetId;
    EFI_STRING_ID               DevicePath;
} EFI_IFR_REF4;

//
// EFI_IFR_REF5
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_QUESTION_HEADER     Question;
} EFI_IFR_REF5;

//
// EFI_IFR_REFRESH
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    UINT8                       RefreshInterval;
} EFI_IFR_REFRESH;

//
// EFI_IFR_REFRESH_ID
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_GUID                    RefreshEventGroupId;
} EFI_IFR_REFRESH_ID;

//
// EFI_IFR_RESET_BUTTON
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_QUESTION_HEADER     Statement;
    EFI_DEFAULT_ID              DefaultId;
} EFI_IFR_RESET_BUTTON;

//
// EFI_IFR_RULE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    UINT8                       RuleId;
} EFI_IFR_RULE;

//
// EFI_IFR_RULE_REF
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    UINT8                       RuleId;
} EFI_IFR_RULE_REF;

//
// EFI_IFR_SECURITY
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_GUID                    Permissions;
} EFI_IFR_SECURITY;

//
// EFI_IFR_SET
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_VARSTORE_ID             VarStoreId;
    union {
        EFI_STRING_ID           VerName;
        UINT16                  VarOffset;
    }                           VarStoreInfo;
    UINT8                       VarStoreType;
} EFI_IFR_SET;

//
// EFI_IFR_SHIFT_LEFT
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_SHIFT_LEFT;

//
// EFI_IFR_SHIFT_RIGHT
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_SHIFT_RIGHT;

//
// EFI_IFR_SPAN
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    UINT8                       Flags;
} EFI_IFR_SPAN;

//
// EFI_IFR_SPAN.Flags
//
#define EFI_IFR_FLAGS_FIRST_MATCHING        (0x00)
#define EFI_IFR_FLAGS_FIRST_NON_MATCHING    (0x01)

//
// EFI_IFR_STRING
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_QUESTION_HEADER     Question;
    UINT8                       MinSize;
    UINT8                       MaxSize;
    UINT8                       Flags;
} EFI_IFR_STRING;

//
// EFI_IFR_STRING.Flags
//
#define EFI_IFR_STRING_MULTI_LINE   (0x01)

//
// EFI_IFR_STRING_REF1
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_STRING_ID               StringId;
} EFI_IFR_STRING_REF1;

//
// EFI_IFR_STRING_REF2
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_STRING_REF2;

//
// EFI_IFR_SUBTITLE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_STATEMENT_HEADER    Statement;
    UINT8                       Flags;
} EFI_IFR_SUBTITLE;

//
// EFI_IFR_SUBTITLE.Flags
//
#define EFI_IFR_FLAGS_HORIZONTAL    (0x01)

//
// EFI_IFR_SUBTRACT
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_SUBTRACT;

//
// EFI_IFR_SUPPRESS_IF
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_SUPPRESS_IF;

//
// EFI_IFR_TEXT
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_STATEMENT_HEADER    Statement;
    EFI_STRING_ID               TextTwo;
} EFI_IFR_TEXT;

//
// EFI_IFR_THIS
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_THIS;

//
// EFI_IFR_TIME
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_IFR_QUESTION_HEADER     Question;
    UINT8                       Flags;
} EFI_IFR_TIME;

//
// EFI_IFR_TIME.Flags
//
#define QF_TIME_HOUR_SUPPRESS       (0x01)
#define QF_TIME_MINUTE_SUPPRESS     (0x02)
#define QF_TIME_SECOND_SUPPRESS     (0x04)
#define QF_TIME_STORAGE             (0x30)
#define QF_TIME_STORAGE_NORMAL      (0x00)
#define QF_TIME_STORAGE_TIME        (0x10)
#define QF_TIME_STORAGE_WAKEUP      (0x20)

//
// EFI_IFR_TOKEN
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_TOKEN;

//
// EFI_IFR_TO_BOOLEAN
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_TO_BOOLEAN;

//
// EFI_IFR_TO_LOWER
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_TO_LOWER;

//
// EFI_IFR_TO_STRING
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    UINT8                       Format;
} EFI_IFR_TO_STRING;

//
// EFI_IFR_TO_UINT
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_TO_UINT;

//
// EFI_IFR_TO_UPPER
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_TO_UPPER;

//
// EFI_IFR_TRUE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_TRUE;

//
// EFI_IFR_UINT8
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    UINT8                       Value;
} EFI_IFR_UINT8;

//
// EFI_IFR_UINT16
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    UINT16                      Value;
} EFI_IFR_UINT16;

//
// EFI_IFR_UINT32
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    UINT32                      Value;
} EFI_IFR_UINT32;

//
// EFI_IFR_UINT64
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    UINT64                      Value;
} EFI_IFR_UINT64;

//
// EFI_IFR_UNDEFINED
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_UNDEFINED;

//
// EFI_IFR_VALUE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_VALUE;

//
// EFI_IFR_VARSTORE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_GUID                    Guid;
    EFI_VARSTORE_ID             VarStoreId;
    UINT16                      Size;
    // UINT8                    Name[];
} EFI_IFR_VARSTORE;

//
// EFI_IFR_VARSTORE_NAME_VALUE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_VARSTORE_ID             VarStoreId;
    EFI_GUID                    Guid;
} EFI_IFR_VARSTORE_NAME_VALUE;

//
// EFI_IFR_VARSTORE_EFI
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_VARSTORE_ID             VarStoreId;
    EFI_GUID                    Guid;
    UINT32                      Attributes;
    UINT16                      Size;
    // UINT8                    Name[];
} EFI_IFR_VARSTORE_EFI;

//
// EFI_IFR_VARSTORE_DEVICE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_STRING_ID               DevicePath;
} EFI_IFR_VARSTORE_DEVICE;

//
// EFI_IFR_VERSION
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_VERSION;

//
// EFI_IFR_WRITE
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_WRITE;

//
// EFI_IFR_ZERO
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
} EFI_IFR_ZERO;

//
// EFI_IFR_WARNING_IF
//
typedef struct {
    EFI_IFR_OP_HEADER			Header;
    EFI_STRING_ID               Warning;
    UINT8                       Timeout;
} EFI_IFR_WARNING_IF;

#endif // EFI_PROTOCOL_HII_PACKAGE_FORMS_H
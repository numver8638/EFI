#ifndef EFI_ERRORS_H
#define EFI_ERRORS_H

#define _ERROR(code)      ((EFI_STATUS)(code|HIGH_BIT))
#define _WARNING(code)    ((EFI_STATUS)(code))

#define EFI_ERROR(code)       ((INTN)(code) < 0)

#define EFI_SUCCESS  ((EFI_STATUS)(0))

// Errors
#define EFI_LOAD_ERROR             _ERROR(1)
#define EFI_INVALID_PARAMETER      _ERROR(2)
#define EFI_UNSUPPROTED            _ERROR(3)
#define EFI_BAD_BUFFER_SIZE        _ERROR(4)
#define EFI_BUFFER_TOO_SMALL       _ERROR(5)
#define EFI_NOT_READY              _ERROR(6)
#define EFI_DEVICE_ERROR           _ERROR(7)
#define EFI_WRITE_PROTECTED        _ERROR(8)
#define EFI_OUT_OF_RESOURCES       _ERROR(9)
#define EFI_VOLUME_CORRUPTED       _ERROR(10)
#define EFI_VOLUME_FULL            _ERROR(11)
#define EFI_NO_MEDIA               _ERROR(12)
#define EFI_MEDIA_CHANGED          _ERROR(13)
#define EFI_NOT_FOUND              _ERROR(14)
#define EFI_ACCESS_DENIED          _ERROR(15)
#define EFI_NO_RESPONSE            _ERROR(16)
#define EFI_NO_MAPPING             _ERROR(17)
#define EFI_TIMEOUT                _ERROR(18)
#define EFI_NOT_STARTED            _ERROR(19)
#define EFI_ALREADY_STARTED        _ERROR(20)
#define EFI_ABORTED                _ERROR(21)
#define EFI_ICMP_ERROR             _ERROR(22)
#define EFI_TFTP_ERROR             _ERROR(23)
#define EFI_PROTOCOL_ERROR         _ERROR(24)
#define EFI_INCOMPATIBLE_VERSION   _ERROR(25)
#define EFI_SECURITY_VIOLATION     _ERROR(26)
#define EFI_CRC_ERROR              _ERROR(27)
#define EFI_END_OF_MEDIA           _ERROR(28)
#define EFI_END_OF_FILE            _ERROR(31)
#define EFI_INVALID_LANGUAGE       _ERROR(32)
#define EFI_COMPROMISED_DATA       _ERROR(33)
#define EFI_IP_ADDRESS_CONFLICT    _ERROR(34)

// Warnings
#define EFI_WRAN_UNKNOWN_GLYPH     _WARNING(1)
#define EFI_WARN_DELETE_FAILURE    _WARNING(2)
#define EFI_WARN_WRITE_FAILURE     _WARNING(3)
#define EFI_WARN_BUFFER_TOO_SMALL  _WARNING(4)
#define EFI_WARN_STALE_DATA        _WARNING(5)

#endif // EFI_ERRORS_H
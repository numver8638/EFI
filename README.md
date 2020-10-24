# EFI
This is copy of code definition of Unified Extensible Firmware Interface(UEFI) Specfication 2.4 Errata C.

This library is made for my hobby OS bootloader.

## __IMPORTANT__
- __This library only contains code definition and does not have any implementation/support codes.__
- __This library is hand-written and typos might be in the code.__
- __Although all architecures in the specification are supported but compiler/architectures except IA32 and x64 under GCC is not tested. Under the not tested envionment, codes may not working. Please use with caution.__

> If you found bugs and/or typos please notice me using issues or pull requests in Github.

## License
Because the specification is opened, this library is public domain. Feel free to use it.

## Header Path
`EFI/EFI.h` includes headers listed below.
- `EFI/Types.h`
- `EFI/Errors.h`
- `EFI/SystemTable.h`

### Service Tables
| Service              | Include Path            |
|----------------------|-------------------------|
| EFI_BOOT_SERVICES    | `EFI/BootServices.h`    |
| EFI_RUNTIME_SERVICES | `EFI/RuntimeServices.h` |
| EFI_SYSTEM_TABLE     | `EFI/SystemTable.h`     |

### Protocols (Sorted ascending by protocol name)
| Protocol Name | Include Path |
|---------------|--------------|
| EFI_ABSOLUTE_POINTER_PROTOCOL | `EFI/Protocol/Console/AbsolutePointer.h` |
| EFI_ACPI_TABLE_PROTOCOL | `EFI/Protocol/ACPI/ACPI.h` |
| EFI_ADAPTER_INFORMATION_PROTOCOL | `EFI/Protocol/Driver/AdapterInformation.h` |
| EFI_ADAPTER_INFO_MEDIA_STATE | `EFI/Protocol/Driver/AdapterInformation.h` |
| EFI_ADAPTER_INFO_NETWORK_BOOT | `EFI/Protocol/Driver/AdapterInformation.h` |
| EFI_ADAPTER_INFO_SAN_MAC_ADDRESS | `EFI/Protocol/Driver/AdapterInformation.h` |
| EFI_ARP_PROTOCOL | `EFI/Protocol/Network/ARP.h` |
| EFI_ARP_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Network/ARP.h` |
| EFI_ATA_PASS_THRU_PROTOCOL | `EFI/Protocol/Media/ATAPassThru.h` |
| EFI_AUTHENTICATION_INFO_PROTOCOL | `EFI/Protocol/SecureBoot/AuthenticationInfo.h` |
| EFI_BIS_PROTOCOL | `EFI/Protocol/Network/BootIntegritySerivce.h` |
| EFI_BLOCK_IO2_PROTOCOL | `EFI/Protocol/Media/BlockIO2.h` |
| EFI_BLOCK_IO_PROTOCOL | `EFI/Protocol/Media/BlockIO.h` |
| EFI_BUS_SPECIFIC_DRIVER_OVERRIDE_PROTOCOL | `EFI/Protocol/Driver/BusSpecificDriverOverride.h` |
| EFI_COMPONENT_NAME2_PROTOCOL | `EFI/Protocol/Driver/ComponentName.h` |
| EFI_DEBUGPORT_PROTOCOL | `EFI/Protocol/Debug/DebugPort.h` |
| EFI_DEBUG_SUPPORT_PROTOCOL | `EFI/Protocol/Debug/DebugSupport.h` |
| EFI_DECOMPRESS_PROTOCOL | `EFI/Protocol/Compression/Decompress.h` |
| EFI_DEFFRRED_IMAGE_LOAD_PROTOCOL | `EFI/Protocol/Identification/DefferedImageLoad.h` |
| EFI_DEVICE_PATH_FROM_TEXT_PROTOCOL | `EFI/Protocol/Path/DevicePathFromText.h` |
| EFI_DEVICE_PATH_PROTOCOL | `EFI/Protocol/Path/DevicePath.h` |
| EFI_DEVICE_PATH_TO_TEXT_PROTOCOL | `EFI/Protocol/Path/DevicePathToText.h` |
| EFI_DEVICE_PATH_UTILITIES_PROTOCOL | `EFI/Protocol/Path/DevicePathUtilities.h` |
| EFI_DHCP4_PROTOCOL | `EFI/Protocol/Network/DHCP4.h` |
| EFI_DHCP4_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Network/DHCP4.h` |
| EFI_DHCP6_PROTOCOL | `EFI/Protocol/Network/DHCP6.h` |
| EFI_DHCP6_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Network/DHCP6.h` |
| EFI_DISK_IO2_PROTOCOL | `EFI/Protocol/Media/DiskIO2.h` |
| EFI_DISK_IO_PROTOCOL | `EFI/Protocol/Media/DiskIO.h` |
| EFI_DRIVER_BINDING_PROTOCOL | `EFI/Protocol/Driver/DriverBinding.h` |
| EFI_DRIVER_DIAGNOSTICS2_PROTOCOL | `EFI/Protocol/Driver/DriverDiagnostics.h` |
| EFI_DRIVER_FAMILY_OVERRIDE_PROTOCOL | `EFI/Protocol/Driver/FamilyOverride.h` |
| EFI_DRIVER_HEALTH_PROTOCOL | `EFI/Protocol/Driver/Health.h` |
| EFI_DRIVER_SUPPORTED_EFI_VERSION_PROTOCOL | `EFI/Protocol/Driver/SupportedVersion.h` |
| EFI_EAP_MANAGEMENT_PROTOCOL | `EFI/Protocol/Network/EAPManagement.h` |
| EFI_EAP_PROTOCOL | `EFI/Protocol/Network/EAP.h` |
| EFI_EBC_PROTOCOL | `EFI/Protocol/EBC/Interpreter.h` |
| EFI_EXT_SCSI_PASS_THRU_PROTOCOL | `EFI/Protocol/SCSI/SCSIPassThru.h` |
| EFI_FILE_PROTOCOL | `EFI/Protocol/Media/File.h` |
| EFI_FIRMWARE_MANAGEMENT_PROTOCOL | `EFI/Protocol/Firmware/FirmwareManagement.h` |
| EFI_FORM_BROWSER2_PROTOCOL | `EFI/Protocol/HII/FormBrowser.h` |
| EFI_FTP4_PROTOCOL | `EFI/Protocol/Network/FTP4.h` |
| EFI_FTP4_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Network/FTP4.h` |
| EFI_GRAPHICS_OUTPUT_PROTOCOL | `EFI/Protocol/Console/GraphicsOutput.h` |
| EFI_HASH_PROTOCOL | `EFI/Protocol/Secure/Hash.h` |
| EFI_HASH_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Secure/Hash.h` |
| EFI_HII_CONFIG_ACCESS_PROTOCOL | `EFI/Protocol/HII/ConfigurationAccess.h` |
| EFI_HII_CONFIG_ROUTING_PROTOCOL | `EFI/Protocol/HII/ConfigurationRouting.h` |
| EFI_HII_DATABASE_PROTOCOL | `EFI/Protocol/HII/Database.h` |
| EFI_HII_FONT_PROTOCOL | `EFI/Protocol/HII/Font.h` |
| EFI_HII_IMAGE_PROTOCOL | `EFI/Protocol/HII/Image.h` |
| EFI_HII_STRING_PROTOCOL | `EFI/Protocol/HII/String.h` |
| EFI_IP4_CONFIG_PROTOCOL | `EFI/Protocol/Network/IPv4Configuration.h` |
| EFI_IP4_PROTOCOL | `EFI/Protocol/Network/IPv4.h` |
| EFI_IP4_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Network/IPv4.h` |
| EFI_IP6_CONFIG_PROTOCOL | `EFI/Protocol/Network/IPv6Configuration.h` |
| EFI_IP6_PROTOCOL | `EFI/Protocol/Network/IPv6.h` |
| EFI_IP6_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Network/IPv6.h` |
| EFI_IPSEC2_PROTOCOL | `EFI/Protocol/Network/IPSec2.h` |
| EFI_IPSEC_CONFIG_PROTOCOL | `EFI/Protocol/Network/IPSecConfiguration.h` |
| EFI_IPSEC_PROTOCOL | `EFI/Protocol/Network/IPSec.h` |
| EFI_ISCSI_INITIATOR_NAME_PROTOCOL | `EFI/Protocol/iSCSI/iSCSIInitiatorName.h` |
| EFI_KEY_MANAGEMENT_SERVICE_PROTOCOL | `EFI/Protocol/Secure/KeyManagement.h` |
| EFI_LOADED_IMAGE_DEVICE_PATH_PROTOCOL | `EFI/Protocol/Image/LoadedImage.h` |
| EFI_LOADED_IMAGE_PROTOCOL | `EFI/Protocol/Image/LoadedImage.h` |
| EFI_LOAD_FILE2_PROTOCOL | `EFI/Protocol/Media/LoadFile2.h` |
| EFI_LOAD_FILE_PROTOCOL | `EFI/Protocol/Media/LoadFile.h` |
| EFI_MANAGED_NETWORK_PROTOCOL | `EFI/Protocol/Network/ManagedNetwork.h` |
| EFI_MANAGED_NETWORK_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Network/ManagedNetwork.h` |
| EFI_MTFTP4_PROTOCOL | `EFI/Protocol/Network/MTFTP4.h` |
| EFI_MTFTP4_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Network/MTFTP4.h` |
| EFI_MTFTP6_PROTOCOL | `EFI/Protocol/Network/MTFTP6.h` |
| EFI_MTFTP6_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Network/MTFTP6.h` |
| EFI_NETWORK_INTERFACE_IDENTIFIER_PROTOCOL | `EFI/Protocol/Network/InterfaceIdentifier.h` |
| EFI_PCI_IO_PROTOCOL | `EFI/Protocol/PCI/PCIIO.h` |
| EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL | `EFI/Protocol/PCI/RootBridgeIO.h` |
| EFI_PLATFORM_DRIVER_OVERRIDE_PROTOCOL | `EFI/Protocol/Driver/PlatformDriverOverride.h` |
| EFI_PLATFORM_TO_DRIVER_CONFIGURATION_PROTOCOL | `EFI/Protocol/Driver/DriverConfiguration.h` |
| EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL | `EFI/Protocol/Network/PXEBaseCodeCallback.h` |
| EFI_PXE_BASE_CODE_PROTOCOL | `EFI/Protocol/Network/PXEBaseCode.h` |
| EFI_RNG_PROTOCOL | `EFI/Protocol/Secure/Random.h` |
| EFI_SCSI_IO_PROTOCOL | `EFI/Protocol/SCSI/SCSIIO.h` |
| EFI_SERIAL_IO_PROTOCOL | `EFI/Protocol/Console/SerialIO.h` |
| EFI_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Driver/ServiceBinding.h` |
| EFI_SIMPLE_FILE_SYSTEM_PROTOCOL | `EFI/Protocol/Media/SimpleFileSystem.h` |
| EFI_SIMPLE_NETWORK_PROTOCOL | `EFI/Protocol/Network/SimpleNetwork.h` |
| EFI_SIMPLE_POINTER_PROTOCOL | `EFI/Protocol/Console/SimplePointer.h` |
| EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL | `EFI/Protocol/Console/SimpleTextInputEx.h` |
| EFI_SIMPLE_TEXT_INPUT_PROTOCOL | `EFI/Protocol/Console/SimpleTextInput.h` |
| EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL | `EFI/Protocol/Console/SimpleTextOutput.h` |
| EFI_STORAGE_SECURITY_COMMAND_PROTOCOL | `EFI/Protocol/Media/StorageSecurityCommand.h` |
| EFI_TAPE_IO_PROTOCOL | `EFI/Protocol/Media/TapeIO.h` |
| EFI_TCP4_PROTOCOL | `EFI/Protocol/Network/TCPv4.h` |
| EFI_TCP4_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Network/TCPv4.h` |
| EFI_TCP6_PROTOCOL | `EFI/Protocol/Network/TCPv6.h` |
| EFI_TCP6_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Network/TCPv6.h` |
| EFI_TIMESTAMP_PROTOCOL | `EFI/Protocol/TimeStamp/TimeStamp.h` |
| EFI_UDP4_PROTOCOL | `EFI/Protocol/Network/UDP4.h` |
| EFI_UDP4_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Network/UDP4.h` |
| EFI_UDP6_PROTOCOL | `EFI/Protocol/Network/UDP6.h` |
| EFI_UDP6_SERVICE_BINDING_PROTOCOL | `EFI/Protocol/Network/UDP6.h` |
| EFI_UNICODE_COLLATION_PROTOCOL | `EFI/Protocol/Media/UnicodeCollation.h` |
| EFI_USB2_HC_PROTOCOL | `EFI/Protocol/USB/USBHostController.h` |
| EFI_USB_IO_PROTOCOL | `EFI/Protocol/USB/USBIO.h` |
| EFI_USER_CREDENTIAL2_PROTOCOL | `EFI/Protocol/Identification/UserCredentialProvider.h` |
| EFI_USER_MANAGER_PROTOCOL | `EFI/Protocol/Identification/UserManager.h` |
| EFI_VLAN_CONFIG_PROTOCOL | `EFI/Protocol/Network/VLANConfiguration.h` |

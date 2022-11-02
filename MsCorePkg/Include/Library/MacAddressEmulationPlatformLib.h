/** @file

  Defines the APIs for the MAC Address Emulation Platform library.

  Copyright (c) Microsoft Corporation.
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/
#ifndef _MAC_ADDRESS_EMULATION_PLATFORM_LIB_H_
#define _MAC_ADDRESS_EMULATION_PLATFORM_LIB_H_

/**
  Called by the MacAddressEmulationDxe driver's entry function to determine if the platform's MAC emulation is enabled.

  @param[out]  Address - Pointer to a buffer to receive the emulated MAC address to use for this platform.

  @retval  EFI_UNSUPPORTED - Feature is not enabled/supported by the platrform.
  @retval  EFI_STATUS      - Status of other calls in the function.

**/
EFI_STATUS
IsMacEmulationEnabled (
  OUT EFI_MAC_ADDRESS *Address
  );

/**
  Executes platform-specific logic to determine if MAC-address emulation is supported by a specific SNP controller.

  @param[in]  SnpHandle - Controller handle for which to determine support.

  @retval TRUE  - Device represented by SnpHandle supports MAC emulation.
  @retval FALSE - Device represented by SnpHandle does not support MAC emulation.

**/
BOOLEAN
SnpSupportsMacEmulation (
  IN  EFI_HANDLE SnpHandle
  );

/**
  Execute any platform or network controller specific code required to implement MAC-address emulation outside of a
  call to the UEFI API EFI_SIMPLE_NETWORK_PROTOCOL::StationAddress().

  @param[in]  Address - MAC Address to use for emulation

  @retval  EFI_STATUS

**/
EFI_STATUS
PlatformMacEmulationEnable (
  IN  EFI_MAC_ADDRESS *Address
  );
#endif // _MAC_ADDRESS_EMULATION_PLATFORM_LIB_H_
#
# Copyright (C) 2006-2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
#
 # We cannot currently build a factory image. It is the sysupgrade image
  # prefixed with a header (which is actually written into the MTD device).
  # The header is 2kiB and is filled with 0xff. The format seems to be:
  #   2 bytes:  0x0000
  #   2 bytes:  checksum of the data partition (big endian)
  #   4 bytes:  length of the contained image file (big endian)
  #  32 bytes:  Firmware Version string (NUL terminated, 0xff padded)
  #   2 bytes:  0x0000
  #   2 bytes:  checksum over the header partition (big endian)
  #  32 bytes:  Model (e.g. "NBG6616", NUL termiated, 0xff padded)
  #      rest: 0xff padding
  #
  # The checksums are calculated by adding up all bytes and if a 16bit
  # overflow occurs, one is added and the sum is masked to 16 bit:
  #   csum = csum + databyte; if (csum > 0xffff) { csum += 1; csum &= 0xffff };
  # Should the file have an odd number of bytes then the byte len-0x800 is
  # used additionally.
  # The checksum for the header is calcualted over the first 2048 bytes with
  # the firmware checksum as the placeholder during calculation.
  #
  # The header is padded with 0xff to the erase block size of the device.

include $(TOPDIR)/rules.mk


ifeq "$(PROFILE)" ""
export ZY_IMG_PREFIX=$(shell echo $(SUBTARGET)|tr '[:upper:]' '[:lower:]')
FW_INFO_FILE=$(PLATFORM_SUBDIR)/FWHdr_Info
else
export ZY_IMG_PREFIX=$(shell echo $(PROFILE)|tr '[:upper:]' '[:lower:]')
FW_INFO_FILE=$(PLATFORM_SUBDIR)/fwhdr/FWHdr_Info.$(PROFILE)
endif




ZY_IMG_HDR_EXTEND_SIZE=$(shell grep 'HDR_EXTEND_SIZE' $(FW_INFO_FILE) | cut -f 2 -d '=')

##generate firmware image include header info
define zyxel_tools/genImageHeader	 

	@(if [ -f $(BIN_DIR)/$(ZY_IMG_PREFIX)-rootfs.jffs2 ]; then \
		$(STAGING_DIR_HOST)/bin/genImgHdr -i $(BIN_DIR)/$(ZY_IMG_PREFIX)-rootfs.jffs2 -v $(shell grep "FW_VERSION" $(FW_INFO_FILE) | cut -d '=' -f 2) -p $(shell grep "PROJECT_NAME" $(FW_INFO_FILE) | cut -d '=' -f 2) -s $(if $(ZY_IMG_HDR_EXTEND_SIZE),$(ZY_IMG_HDR_EXTEND_SIZE),0x10000) -o ras.bin.jffs2.header&&cp ras.bin.jffs2.header ras.bin.jffs2&&cat $(BIN_DIR)/zyxel/$(ZY_IMG_PREFIX)-rootfs.jffs2>>ras.bin.jffs2; \
	 fi; \
	 if [ -f $(BIN_DIR)/$(ZY_IMG_PREFIX)-rootfs.squashfs ]; then \
		$(STAGING_DIR_HOST)/bin/genImgHdr -i $(BIN_DIR)/$(ZY_IMG_PREFIX)-rootfs.squashfs -v $(shell grep "FW_VERSION" $(FW_INFO_FILE) | cut -d '=' -f 2) -p $(shell grep "PROJECT_NAME" $(FW_INFO_FILE) | cut -d '=' -f 2) -s $(if $(ZY_IMG_HDR_EXTEND_SIZE),$(ZY_IMG_HDR_EXTEND_SIZE),0x10000) -o ras.bin.squashfs.header&&cp ras.bin.squashfs.header ras.bin.squashfs&&cat $(BIN_DIR)/$(ZY_IMG_PREFIX)-rootfs.squashfs>>ras.bin.squashfs; \
	 fi)


endef


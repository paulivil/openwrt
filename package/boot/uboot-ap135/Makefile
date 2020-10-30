#
# Copyright (C) 2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
PKG_VERSION:=2016.01
PKG_RELEASE:=1




PKG_HASH:=e5792fba9399d9804aa2ef667f14ff771e2cdece72367d340250265bf095a5d5
include $(INCLUDE_DIR)/u-boot.mk
include $(INCLUDE_DIR)/package.mk

define U-Boot/Default
  BUILD_TARGET:=ath79
  BUILD_SUBTARGET:=generic
  BUILD_DEVICES:=$(1)
  UBOOT_IMAGE:=u-boot.bin
endef

define U-Boot/nbg6616
  NAME:=ZyXEL NBG6616
  UBOOT_CONFIG:=nbg6616
endef

define U-Boot/nbg6716
  NAME:=ZyXEL NBG6716
  BUILD_SUBTARGET:=nand
  UBOOT_CONFIG:=nbg6716
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) ./files/* $(PKG_BUILD_DIR)
	find $(PKG_BUILD_DIR) -name .svn | $(XARGS) rm -rf
endef

UBOOT_MAKE_FLAGS:= VERBOSE=1
UBOOT_CONFIGURE_VARS:= 
UBOOT_TARGETS:=\
nbg6616 \
nbg6716



$(eval $(call BuildPackage/U-Boot))

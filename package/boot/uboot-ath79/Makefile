#
# Copyright (C) 2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_VERSION:=2019.07
PKG_RELEASE:=1

PKG_HASH:=bff4fa77e8da17521c030ca4c5b947a056c1b1be4d3e6ee8637020b8d50251d0

include $(INCLUDE_DIR)/u-boot.mk
include $(INCLUDE_DIR)/package.mk

define U-Boot/Default
  BUILD_TARGET:=ath79
  BUILD_SUBTARGET:=generic
endef

define U-Boot/nbg6616
  TITLE:=NBG6616 router
  BUILD_DEVICES:=nbg6616
  HIDDEN:=y
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) ./files/* $(PKG_BUILD_DIR)
	find $(PKG_BUILD_DIR) -name .svn | $(XARGS) rm -rf
endef

UBOOT_MAKE_FLAGS :=-mno-mips16

UBOOT_TARGETS:=ap135

$(eval $(call BuildPackage/U-Boot))

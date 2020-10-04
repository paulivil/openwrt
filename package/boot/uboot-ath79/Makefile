#
# Copyright (C) 2010 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_VERSION:=2019.07
PKG_RELEASE:=1

PKG_HASH:=902d1b2c15787df55186fae4033685fb0c5a5a12755a08383e97c4a3e255925b

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

UBOOT_MAKE_FLAGS :=

UBOOT_TARGETS:=ap135

$(eval $(call BuildPackage/U-Boot))
